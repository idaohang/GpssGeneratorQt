
#include "threadswindow.h"
#include <QMessageBox>

namespace  GeneratorGpss
{

//ThreadsWindow==================================================================
ThreadsWindow::ThreadsWindow(NetworkDescriptor *netDesc,QWidget *parent):AbstractNavigatableWindow(parent)
{
    netDescriptor=netDesc;
    netTypeLbl.setText(trUtf8("Choose model type: "));
    netType.addItem(trUtf8("Open"));
    netType.addItem(trUtf8("Closed"));
    netType.addItem(trUtf8("Hybrid"));
    netTypeLayout.addWidget(&netTypeLbl);
    netTypeLayout.addWidget(&netType,1,Qt::AlignLeft);
    mainLayout.addLayout(&netTypeLayout);

    threadLbl.setText(trUtf8("Description of threads:"));
    threadsFrameLayout.addWidget(&threadLbl);
    //one thread by default
    threadsFrameLayout.addWidget(createNewThreadWidget());
    threadsFrame.setLayout(&threadsFrameLayout);
    mainLayout.addWidget(&threadsFrame);

    mainLayout.addStretch(1);

    addThreadBtn.setText(trUtf8("Add thread"));
    mainLayout.addWidget(&addThreadBtn,0,Qt::AlignRight);

    addNavigation(NAVIGATE_NEXT);
    this->setLayout(&mainLayout);

    connect(&addThreadBtn,SIGNAL(clicked()),this,SLOT(addThreadClick()));
}

vector<ThreadWidget*> *ThreadsWindow::getThreadWidgets()
{
    return &threadWidgets;
}

//is not implemented
void ThreadsWindow::updateDescriptor()
{
    vector<ThreadDescriptor> *pThread=netDescriptor->getThreads();
    bool threadDeleted;
    for(int i=0;i<pThread->size();i++)
    {
        bool threadFound=false;
        for(int j=0;j<threadWidgets.size();j++)
        {
            if((*pThread)[i].getId()==threadWidgets[i]->getId())
            {

            }
        }
    }
}

void ThreadsWindow::updateInterface()
{

}

ThreadWidget *ThreadsWindow::createNewThreadWidget()
{
    vector<ThreadDescriptor> *pThreads=netDescriptor->getThreads();
    pThreads->push_back(ThreadDescriptor());
    ThreadWidget *threadWidget=new ThreadWidget(pThreads->back().getId());

    connect(threadWidget->getDeleteButton(),SIGNAL(clicked()),this,SLOT(deleteThreadClick()));

    threadWidgets.push_back(threadWidget);
    return threadWidget;
}

ThreadsWindow::~ThreadsWindow()
{
    for(int i=0;i<threadWidgets.size();i++)
    {
        delete threadWidgets[i];
        threadWidgets[i]=0;
    }
}

void ThreadsWindow::addThreadClick()
{
    QWidget *newThreadWidget=createNewThreadWidget();

    threadsFrameLayout.addWidget(newThreadWidget);
}

void ThreadsWindow::deleteThreadClick()
{
    QPushButton *senderBtn=qobject_cast<QPushButton*>(sender());
    for(int i=0;i<threadWidgets.size();i++)
    {
        //selection of thread, that is correspond to button
        if(threadWidgets[i]->getDeleteButton()==senderBtn)
        {
            ThreadWidget *tmp=threadWidgets[i];
            //deleting thread from the model
            vector<ThreadDescriptor> *pThreads=netDescriptor->getThreads();
            for(int j=0;j<pThreads->size();j++)
            {
                if((*pThreads)[j].getId()==tmp->getId())
                {
                    pThreads->erase(pThreads->begin()+j);
                    break;
                }
            }

            threadsFrameLayout.removeWidget(tmp);
            threadWidgets.erase(threadWidgets.begin()+i);
            delete tmp;
            break;
        }
    }
}

//ThreadWidget==================================================================
ThreadWidget::ThreadWidget(int id,QWidget *parent):QWidget(parent)
{
    this->id=id;
    threadType.addItem(trUtf8("Open"), QVariant::fromValue((int)OPEN));
    threadType.addItem(trUtf8("Closed"),QVariant::fromValue((int)CLOSED));

    threadFunc.addItem(trUtf8("Exponential"),QVariant::fromValue((int)EXPONENTIAL));
    threadFunc.addItem(trUtf8("Uniform"),QVariant::fromValue((int)UNIFORM));
    threadFunc.addItem(trUtf8("Triangular"),QVariant::fromValue((int)TRIANGLE));

    priorityType.addItem(trUtf8("Without priority"));
    priorityType.addItem(trUtf8("Relative"));
    priorityType.addItem(trUtf8("Absolute"));

    threadTypeLbl.setText(trUtf8("Thread type: "));
    threadFuncLbl.setText(trUtf8("Destribution function for generation: "));
    param1Lbl.setText(trUtf8("Scale: "));
    param2Lbl.setText(trUtf8("Locate: "));
    priorityTypeLbl.setText(trUtf8("Priority type: "));
    priorityValueLbl.setText(trUtf8("Priority value: "));

    threadTypeLayout.addWidget(&threadTypeLbl);
    threadTypeLayout.addWidget(&threadType);
    mainLayout.addLayout(&threadTypeLayout);
    threadFuncLayout.addWidget(&threadFuncLbl);
    threadFuncLayout.addWidget(&threadFunc);
    mainLayout.addLayout(&threadFuncLayout);
    param1Layout.addWidget(&param1Lbl);
    param1.setText("0");
    param1Layout.addWidget(&param1);
    mainLayout.addLayout(&param1Layout);
    param2Layout.addWidget(&param2Lbl);
    param2.setText("0");
    param2Layout.addWidget(&param2);
    mainLayout.addLayout(&param2Layout);
    param3Layout.addWidget(&param3Lbl);
    param3Layout.addWidget(&param3);
    mainLayout.addLayout(&param3Layout);
    param3Lbl.hide();
    param3.hide();
    priorityLayout.addWidget(&priorityTypeLbl);
    priorityLayout.addWidget(&priorityType);
    mainLayout.addLayout(&priorityLayout);

    priorityValueLayout.addWidget(&priorityValueLbl);
    priorityValueLayout.addWidget(&priorityValue);
    mainLayout.addLayout(&priorityValueLayout);
    priorityValueLbl.hide();
    priorityValue.hide();

    deleteButton.setText(trUtf8("Delete"));
    mainLayout.addStretch(1);
    mainLayout.addWidget(&deleteButton,0,Qt::AlignRight);

    connect(&threadType,SIGNAL(currentIndexChanged(int)),this,SLOT(typeChanged(int)));
    connect(&threadFunc,SIGNAL(currentIndexChanged(int)),this,SLOT(funcChanged(int)));
    connect(&priorityType,SIGNAL(currentIndexChanged(int)),this,SLOT(priorityTypeChanged(int)));

    this->setLayout(&mainLayout);
}

int ThreadWidget::getId()
{
    return id;
}

ThreadWidget::~ThreadWidget()
{
}

void ThreadWidget::typeChanged(int i)
{
    switch(i)
    {
    case OPEN:
        threadFuncLbl.show();
        threadFunc.setCurrentIndex(0);
        threadFunc.show();
        param1Lbl.setText(trUtf8("Scale: "));
        param1Lbl.show();
        param1.setText("0");
        param1.show();
        param2Lbl.setText(trUtf8("Locate: "));
        param2Lbl.show();
        param2.show();
        param2.setText("0");
        break;
    case CLOSED:
        threadFuncLbl.hide();
        threadFunc.hide();
        param2.hide();
        param3.hide();
        param2Lbl.hide();
        param3Lbl.hide();
        param1Lbl.setText(trUtf8("Amount of requests: "));
        param1.setText("0");
        break;
    }
}

void ThreadWidget::funcChanged(int i)
{
    switch(i)
    {
    case UNIFORM:
        param1Lbl.setText(trUtf8("Minimum: "));
        param1.setText("0");
        param2Lbl.setText(trUtf8("Maximum: "));
        param2Lbl.show();
        param2.setText("0");
        param2.show();
        param3Lbl.hide();
        param3.hide();
        break;
    case EXPONENTIAL:
        param1Lbl.setText(trUtf8("Scale: "));
        param1.setText("0");
        param2Lbl.setText(trUtf8("Locate: "));
        param2Lbl.show();
        param2.setText("0");
        param2.show();
        param3Lbl.hide();
        param3.hide();
        break;
    case TRIANGLE:
        param1Lbl.setText(trUtf8("Minimum: "));
        param1.setText("");
        param2Lbl.setText(trUtf8("Maximum: "));
        param2Lbl.show();
        param2.setText("0");
        param2.show();
        param3Lbl.setText(trUtf8("Mode: "));
        param3Lbl.show();
        param3.setText("0");
        param3.show();
        break;
    }
}

void ThreadWidget::priorityTypeChanged(int i)
{
    switch(priorityType.currentIndex())
    {
    case NONE:
    case ABSOLUTE:
        priorityValueLbl.hide();
        priorityValue.hide();
        break;
    case RELATIVE:
        priorityValueLbl.show();
        priorityValue.show();
        break;
    }
}

ThreadTypeEnum ThreadWidget::getType()
{
    return (ThreadTypeEnum)threadType.itemData(threadType.currentIndex()).toInt();
}

FunctionTypeEnum ThreadWidget::getFunc()
{
    return (FunctionTypeEnum)threadFunc.itemData(threadFunc.currentIndex()).toInt();
}

QString ThreadWidget::getParam1()
{
    return param1.text();
}

QString ThreadWidget::getParam2()
{
    return param2.text();
}

QString ThreadWidget::getParam3()
{
    return param3.text();
}

QPushButton *ThreadWidget::getDeleteButton()
{
    return &deleteButton;
}

}
