#include "threadwidget.h"
#include <QHBoxLayout>
#include <QLabel>

ThreadWidget::ThreadWidget(QWidget *parent):QWidget(parent)
{
    threadType=new QComboBox;
    threadType->addItem(tr("Razomknut"));
    threadType->addItem(tr("Zamknut"));

    threadFunc=new QComboBox;
    threadFunc->addItem(tr("exp"));
    threadFunc->addItem(tr("uniform"));
    threadFunc->addItem(tr("triangle"));

    priorityType=new QComboBox;
    priorityType->addItem(tr("No"));
    priorityType->addItem(tr("Otn"));
    priorityType->addItem(tr("Abs"));

    param1=new QLineEdit;
    param2=new QLineEdit;
    param3=new QLineEdit;
    priorityValue=new QLineEdit;

    mainLayout=new QHBoxLayout;
    mainLayout->addWidget(new QLabel(tr("ThreadType: ")));
    mainLayout->addWidget(threadType,0,Qt::AlignLeft);
    threadFuncLbl=new QLabel(tr("threadFunc: "));
    mainLayout->addWidget(threadFuncLbl);
    mainLayout->addWidget(threadFunc);
    param1Lbl=new QLabel(tr("Mean: "));
    mainLayout->addWidget(param1Lbl);
    mainLayout->addWidget(param1);
    param2Lbl=new QLabel(tr("Delta: "));
    mainLayout->addWidget(param2Lbl);
    mainLayout->addWidget(param2);
    mainLayout->addWidget(new QLabel(tr("Priority: ")));
    mainLayout->addWidget(priorityType);

    curParams.push_back(threadFuncLbl);
    curParams.push_back(threadFunc);
    curParams.push_back(param1Lbl);
    curParams.push_back(param1);
    curParams.push_back(param2Lbl);
    curParams.push_back(param2);
    this->setLayout(mainLayout);

    connect(threadType,SIGNAL(currentIndexChanged(int)),this,SLOT(typeChanged(int)));
    connect(threadFunc,SIGNAL(currentIndexChanged(int)),this,SLOT(funcChanged(int)));
}

ThreadWidget::~ThreadWidget()
{
    delete threadType;
    delete threadFunc;
    delete param1;
    delete param2;
    delete param3;
    delete priorityType;
    delete priorityValue;
    delete mainLayout;
}

void ThreadWidget::typeChanged(int i)
{
    switch(threadType->currentText()[0].toAscii())
    {
    case 'R':
        for(int i=0;i<curParams.size();i++)
        {
            mainLayout->removeWidget(curParams[i]);
            curParams[i]->setVisible(false);
        }
        curParams.clear();

        mainLayout->insertWidget(2,threadFuncLbl);
        curParams.push_back(threadFuncLbl);
        mainLayout->insertWidget(3,threadFunc);
        curParams.push_back(threadFunc);
        threadFunc->setCurrentIndex(0);
        mainLayout->insertWidget(4,param1Lbl);
        curParams.push_back(param1Lbl);
        param1Lbl->setText(tr("Min: "));
        mainLayout->insertWidget(5,param1);
        curParams.push_back(param1);
        param1->setText("");
        mainLayout->insertWidget(6,param2Lbl);
        curParams.push_back(param2Lbl);
        param1Lbl->setText(tr("Max: "));
        mainLayout->insertWidget(7,param2);
        curParams.push_back(param2);
        param1->setText("");

        for(int i=0;i<curParams.size();i++)
        {
            curParams[i]->setVisible(true);
        }
        break;
    case 'Z':
        for(int i=0;i<curParams.size();i++)
        {
            mainLayout->removeWidget(curParams[i]);
            curParams[i]->setVisible(false);
        }
        curParams.clear();

        mainLayout->addWidget(param1Lbl);
        curParams.push_back(param1Lbl);
        param1Lbl->setText("Amount: ");
        mainLayout->addWidget(param1);
        curParams.push_back(param1);
        param1->setText("");

        for(int i=0;i<curParams.size();i++)
        {
            curParams[i]->setVisible(true);
        }
        break;
    }
    mainLayout->update();
    //mainLayout->invalidate();
}

void ThreadWidget::funcChanged(int i)
{
    switch(threadFunc->currentText()[0].toAscii())
    {
    case 'u':
        break;
    case 'e':
        break;
    case 't':
        break;
    }
}
