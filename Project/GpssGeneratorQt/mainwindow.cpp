#include "mainwindow.h"
#include <QFile>
#include "Generator/SingleGenerator.h"
#include "Generator/MultipleGenerator.h"
#include "Generator/ExponentialFunction.h"
#include "Generator/UniformFunction.h"
#include <map>
#include <utility>

namespace GeneratorGpss
{

using std::map;
using std::pair;
using std::make_pair;
using GeneratorGPSS::Model;
using GeneratorGPSS::Node;
using GeneratorGPSS::Generator;
using GeneratorGPSS::SingleGenerator;
using GeneratorGPSS::MultipleGenerator;
using GeneratorGPSS::Terminator;
using GeneratorGPSS::Facility;
using GeneratorGPSS::Router;
using GeneratorGPSS::ExponentialFunction;
using GeneratorGPSS::UniformFunction;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),netDescriptor(),threadsWindow(&netDescriptor),nodesWindow(&netDescriptor),generateWindow(&netDescriptor),transferMatrixWindow(&netDescriptor),statsWindow(&netDescriptor)
{
    mainLayout.addWidget(&threadsWindow);
    mainLayout.addWidget(&nodesWindow);
    mainLayout.addWidget(&transferMatrixWindow);
    mainLayout.addWidget(&statsWindow);
    mainLayout.addWidget(&generateWindow);

    position=0;
    connect(threadsWindow.getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));

    connect(nodesWindow.getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));
    connect(nodesWindow.getPrevButton(),SIGNAL(clicked()),this,SLOT(prevButtonClicked()));

    connect(transferMatrixWindow.getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));
    connect(transferMatrixWindow.getPrevButton(),SIGNAL(clicked()),this,SLOT(prevButtonClicked()));

    connect(statsWindow.getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));
    connect(statsWindow.getPrevButton(),SIGNAL(clicked()),this,SLOT(prevButtonClicked()));

    connect(generateWindow.getPrevButton(),SIGNAL(clicked()),this,SLOT(prevButtonClicked()));
    connect(generateWindow.getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));
    mainLayout.setCurrentWidget(&threadsWindow);
    this->setLayout(&mainLayout);
}

Model *MainWindow::interfaceToModel()
{
    setThreadTypesInDescriptor();
    vector<ThreadDescriptor> *pThreads=netDescriptor.getThreads();
    vector<NodeDescriptor> *pNodes= netDescriptor.getNodes();
    Model *m=new Model;
    for(int i=0;i<pThreads->size();i++)
    {
        m->AddThread((*pThreads)[i].getId());
    }

    //((id_node, id_thread),Node)
    map<pair<int,int>,Generator*> generatorMap;
    map<pair<int,int>,Terminator*> terminatorMap;
    map<pair<int,int>,Facility*> facilityMap;
    map<pair<int,int>,Router*> transferMap;
    NodeDescriptor *curNode;
    Generator *gen;
    Terminator *term;
    Facility *fac;
    Router *trans;
    for(int i=0;i<pNodes->size();i++)
    {
        curNode=&((*pNodes)[i]);
        switch(curNode->getType())
        {
        case GENERATOR:
            for(int i=0;i<pThreads->size();i++)
            {
                Generator *gen=getGenerator((*pThreads)[i].getId(), curNode->getId());
                generatorMap[std::make_pair(curNode->getId(),(*pThreads)[i].getId())]=gen;
                m->AddNode(gen);
            }
            break;
        case TERMINATOR:
            term=getTerminator(curNode->getId());
            m->AddNode(term);
            for(int i=0;i<pThreads->size();i++)
            {
                terminatorMap[std::make_pair(curNode->getId(),(*pThreads)[i].getId())]=term;
            }
            break;
        case FACILITY:
            fac=getFacility(curNode->getId());
            m->AddNode(fac);
            for(int i=0;i<pThreads->size();i++)
            {
                facilityMap[std::make_pair(curNode->getId(),(*pThreads)[i].getId())]=fac;
            }
            break;
        case TRANSFER:
            trans=getTransfer(curNode->getId());
            m->AddNode(trans);
            for(int i=0;i<pThreads->size();i++)
            {
                transferMap[std::make_pair(curNode->getId(),(*pThreads)[i].getId())]=trans;
            }
            break;
        }
    }

    //добавление структуры (матриц переходов)
    vector<ThreadMatrix*> *threadMatrixes=transferMatrixWindow.getThreadMatrixes();
    QTableWidget *curMatrix;
    for(int i=0;i<pThreads->size();i++)
    {
        for(int j=0;j<threadMatrixes->size();j++)
        {
            if(threadMatrixes->at(j)->getId()==pThreads->at(i).getId())
            {
                curMatrix=threadMatrixes->at(j)->getMatrix();
                break;
            }
        }

        int rows=curMatrix->rowCount();
        int cols=curMatrix->columnCount();
        for(int y=0;y<rows;y++)
        {
            for(int x=0;x<cols;x++)
            {
                double val=curMatrix->item(y,x)->text().toDouble();
                if(val-(1E-4)>0)
                {
                    int fromId;
                    fromId=curMatrix->verticalHeaderItem(y)->data(Qt::UserRole).toInt();
                    int toId;
                    toId=curMatrix->horizontalHeaderItem(x)->data(Qt::UserRole).toInt();
                    Node *toNode;
                    switch(getNodeTypeById(toId))
                    {
                    case GENERATOR:
                        toNode=generatorMap.find(make_pair(toId,pThreads->at(i).getId()))->second;
                        break;
                    case TERMINATOR:
                        toNode=terminatorMap.find(make_pair(toId,pThreads->at(i).getId()))->second;
                        break;
                    case FACILITY:
                        toNode=facilityMap.find(make_pair(toId,pThreads->at(i).getId()))->second;
                        break;
                    case TRANSFER:
                        toNode=transferMap.find(make_pair(toId,pThreads->at(i).getId()))->second;
                        break;
                    }
                    switch(getNodeTypeById(fromId))
                    {
                    case GENERATOR:
                        gen=generatorMap.find(make_pair(fromId,pThreads->at(i).getId()))->second;
                        gen->AddNode(pThreads->at(i).getId(),toNode);
                        break;
                    case TERMINATOR:
                        term=terminatorMap.find(make_pair(fromId,pThreads->at(i).getId()))->second;
                        if(pThreads->at(i).getType()==CLOSED)
                        {
                            term->AddNode(pThreads->at(i).getId(),generatorMap.find(make_pair(1,pThreads->at(i).getId()))->second);
                        }
                        break;
                    case FACILITY:
                        fac=facilityMap.find(make_pair(fromId,pThreads->at(i).getId()))->second;
                        fac->AddNode(pThreads->at(i).getId(),toNode);
                        break;
                    case TRANSFER:
                        trans=transferMap.find(make_pair(fromId,pThreads->at(i).getId()))->second;
                        trans->AddNode(pThreads->at(i).getId(),toNode,val);
                        break;
                    }
                }
            }
        }
    }

    return m;
}

NodeTypeEnum MainWindow::getNodeTypeById(int id)
{
    vector<NodeDescriptor> *pNodes=netDescriptor.getNodes();
    for(int i=0;i<pNodes->size();i++)
    {
        if(pNodes->at(i).getId()==id)
        {
            return pNodes->at(i).getType();
        }
    }
    return FACILITY;
}

void MainWindow::setThreadTypesInDescriptor()
{
    vector<ThreadWidget*> *threadWidgets=threadsWindow.getThreadWidgets();
    vector<ThreadDescriptor> *pThreads=netDescriptor.getThreads();

    for(int i=0;i<threadWidgets->size();i++)
    {
        for(int j=0;j<pThreads->size();j++)
        {
            if(threadWidgets->at(i)->getId()==pThreads->at(j).getId())
            {
                pThreads->at(j).setType(threadWidgets->at(i)->getType());
                break;
            }
        }
    }
}

Generator *MainWindow::getGenerator(int thread, int node)
{
    Generator *res;
    //получение элементов управления, описывающих генератор данного потока
    vector<ThreadWidget*> *threadWidgets=threadsWindow.getThreadWidgets();
    ThreadWidget *curThreadParams;
    for(int  i=0;i<threadWidgets->size();i++)
    {
        if(threadWidgets->at(i)->getId()==thread)
        {
            curThreadParams=threadWidgets->at(i);
            break;
        }
    }

    SingleGenerator *g;
    MultipleGenerator *mg;
    switch(curThreadParams->getType())
    {
    case OPEN:
        g=new SingleGenerator;
        ExponentialFunction *f;
        UniformFunction *unif;
        switch(curThreadParams->getFunc())
        {
        case EXPONENTIAL:
            f=new ExponentialFunction;
            f->SetParams(rand()%100+1,curThreadParams->getParam2().toDouble(),curThreadParams->getParam1().toDouble());
            g->AddFunction(thread,f);
            break;
        case UNIFORM:
            unif=new UniformFunction;
            unif->SetParams(rand()%100+1,curThreadParams->getParam1().toDouble(),curThreadParams->getParam2().toDouble());
            g->AddFunction(thread,unif);
            break;
        }
        res=g;
        break;
    case CLOSED:
        mg=new MultipleGenerator;
        mg->AddCount(thread,curThreadParams->getParam1().toInt());
        res=mg;
        break;
    }

    res->SetName(tr("b%1").arg(node).toStdString());
    if(statsWindow.getNetStatistic()->isChecked())
        res->GenerateStandartStatistics();
    if((*statsWindow.getThreadStats())[thread]->isChecked())
        res->GenerateStandartStatistics(thread);

    return res;
}

void MainWindow::setDescriptionString()
{
    QString res;
    vector<NodeDescriptor> *pNodes=netDescriptor.getNodes();
    vector<ThreadDescriptor> *pThreads=netDescriptor.getThreads();
    res.append(trUtf8("Количество потоков: %1\n").arg(pThreads->size()));
    res.append(trUtf8("Типы потоков:\n"));

    vector<ThreadWidget*> *threads=threadsWindow.getThreadWidgets();
    for(int i=0;i<threads->size();i++)
    {
        res.append(trUtf8("\tТип потока №%1: %2\n").arg(threads->at(i)->getId()).arg((threads->at(i)->getType()==OPEN)?trUtf8("Разомкнутый"):trUtf8("Замкнутый")));
    }
    res.append(trUtf8("Количество узлов: %1\n").arg(pNodes->size()));
    res.append(trUtf8("Типы узлов:\n"));
    for(int i=0;i<pNodes->size();i++)
    {
        res.append(trUtf8("\tТип узла b%1: ").arg(pNodes->at(i).getId()));
        switch(pNodes->at(i).getType())
        {
        case GENERATOR:
            res.append(trUtf8("Генератор"));
            break;
        case TERMINATOR:
            res.append(trUtf8("Приемник"));
            break;
        case FACILITY:
            res.append(trUtf8("Устройство"));
            break;
        case TRANSFER:
            res.append(trUtf8("Маршрутный узел"));
            break;
        }
        res.append(trUtf8("\n"));
    }
    generateWindow.getDescription()->setText(res);
}

Terminator *MainWindow::getTerminator(int node)
{
    Terminator *t=new Terminator;
    t->SetName(tr("b%1").arg(node).toStdString());

    if(statsWindow.getNetStatistic()->isChecked())
        t->GenerateStandartStatistics();
    map<int, QCheckBox*>::iterator p;
    for(p=statsWindow.getThreadStats()->begin();p!=statsWindow.getThreadStats()->end();p++)
    {
        if(p->second->isChecked())
        {
            t->GenerateStandartStatistics(p->first);
        }
    }
    return t;
}

Facility *MainWindow::getFacility(int node)
{
    FacilityWindow *fw;
    for(int i=0;i<nodes.size();i++)
    {
        if(node==nodes[i]->getId())
        {
            fw=nodes[i];
            break;
        }
    }

    Facility *f=new Facility;
    f->SetName(tr("b%1").arg(node).toStdString());
    f->SetChanelAmount(fw->getChanelAmount());
    int statMask=0;
    if(fw->statNodeAllThreads())
    {
        statMask|=2;
    }
    if(fw->statQueueAllThreads())
    {
        statMask|=1;
    }
    f->GenerateStandartStatistics(-1,statMask);

    vector<FacilityThreadParams*> *threadParams=fw->getFacilityThreadParams();
    FacilityFunctionWidget *funcParams;
    for(int i=0;i<threadParams->size();i++)
    {
        if(threadParams->at(i)->IsUsingInThread())
        {
            funcParams=threadParams->at(i)->getFuncParams();
            ExponentialFunction *func;
            UniformFunction *unif;
            switch(funcParams->getFuncType())
            {
            case EXPONENTIAL:
                func=new ExponentialFunction;
                func->SetParams(rand()%100+1,funcParams->getParam2().toDouble(),funcParams->getParam1().toDouble());
                f->AddFunction(threadParams->at(i)->getId(),func);
                break;
            case UNIFORM:
                unif=new UniformFunction;
                unif->SetParams(rand()%100+1,funcParams->getParam1().toDouble(),funcParams->getParam2().toDouble());
                f->AddFunction(threadParams->at(i)->getId(),unif);
                break;
            }

            statMask=0;
            if(threadParams->at(i)->statNode())
            {
                statMask|=2;
            }
            if(threadParams->at(i)->statQueue())
            {
                statMask|=1;
            }
            f->GenerateStandartStatistics(threadParams->at(i)->getId(),statMask);
        }
    }
    return f;
}

Router *MainWindow::getTransfer(int node)
{
    Router *r=new Router;
    r->SetName(tr("b%1").arg(node).toStdString());

    return r;
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::nextButtonClicked()
{
    vector<NodeDescriptor> *pNodes=netDescriptor.getNodes();

    if(position==0)
    {
        threadsWindow.updateDescriptor();
        nodesWindow.updateInterface();
        mainLayout.setCurrentWidget(&nodesWindow);
    }
    else if(position==1)
    {
        nodesWindow.updateDescriptor();
        transferMatrixWindow.updateInterface();
        mainLayout.setCurrentWidget(&transferMatrixWindow);
    }
    else if(position==2)
    {
        transferMatrixWindow.updateDescriptor();

        //добавляем новые окна для добавленных узлов
        for(int i=0;i<pNodes->size();i++)
        {
            if((*pNodes)[i].getType()!=FACILITY)
                continue;
            bool found=false;
            for(int j=0;j<nodes.size();j++)
            {
                if((*pNodes)[i].getId()==nodes[j]->getId())
                {
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                nodes.push_back(new FacilityWindow((*pNodes)[i].getId(),&netDescriptor));
                mainLayout.addWidget(nodes.back());
                connect(nodes.back()->getNextButton(),SIGNAL(clicked()),this,SLOT(nextButtonClicked()));
                connect(nodes.back()->getPrevButton(),SIGNAL(clicked()),this,SLOT(prevButtonClicked()));
            }
        }
        //удаляем старые окна для удаленных узлов
        bool wereChanges=true;
        while(wereChanges)
        {
            wereChanges=false;
            for(int i=0;i<nodes.size();i++)
            {
                bool exist=false;
                for(int j=0;j<pNodes->size();j++)
                {
                    if(nodes[i]->getId()==(*pNodes)[j].getId() && (*pNodes)[j].getType()==FACILITY)
                    {
                        exist=true;
                        break;
                    }
                }
                if(!exist)
                {
                    FacilityWindow *tmp=nodes[i];
                    mainLayout.removeWidget(tmp);
                    nodes.erase(nodes.begin()+i);
                    delete tmp;
                    wereChanges=true;
                    break;
                }
            }
        }

        for(int i=0;i<nodes.size();i++)
        {
            nodes[i]->updateInterface();
        }

        statsWindow.updateInterface();

        if(nodes.size()>0)
            mainLayout.setCurrentWidget(nodes[0]);
        else
            mainLayout.setCurrentWidget(&statsWindow);
    }
    else if(position>2 && position<=2+nodes.size()-1)
    {
        mainLayout.setCurrentWidget(nodes[position-2]);
    }
    else if(position==2+nodes.size())
    {
        statsWindow.updateInterface();
        mainLayout.setCurrentWidget(&statsWindow);
    }
    else if(position==3+nodes.size())
    {
        statsWindow.updateDescriptor();
        generateWindow.updateInterface();
        setDescriptionString();
        mainLayout.setCurrentWidget(&generateWindow);
    }
    else if(position==4+nodes.size())
    {
        Model *m=interfaceToModel();
        QString fileName=generateWindow.getFileName();
        std::ofstream output;
        output.open(fileName.toStdString().c_str());
        m->GenerateTextGPSS(output);
        output.close();
        delete m;

        QFile resFile(fileName);
        resFile.open(QIODevice::ReadOnly);
        generateWindow.getDescription()->setText(resFile.readAll());
        resFile.close();

        generateWindow.getNextButton()->hide();
        generateWindow.getPrevButton()->hide();
        generateWindow.addExitButton();
        position--;
    }
    position++;
}

void MainWindow::prevButtonClicked()
{
    if(position==1)
    {
        mainLayout.setCurrentWidget(&threadsWindow);
    }
    else if(position==2)
    {
        mainLayout.setCurrentWidget(&nodesWindow);
    }
    else if(position==3)
    {
        mainLayout.setCurrentWidget(&transferMatrixWindow);
    }
    else if(position>3 && position<3+nodes.size())
    {
        mainLayout.setCurrentWidget(nodes[position-4]);
    }
    else if(position==3+nodes.size())
    {
        mainLayout.setCurrentWidget(nodes.back());
    }
    else
    {
        mainLayout.setCurrentWidget(&statsWindow);
    }
    position--;
}

}
