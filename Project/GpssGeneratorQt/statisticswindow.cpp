#include "statisticswindow.h"

namespace GeneratorGpss
{

StatisticsWindow::StatisticsWindow(NetworkDescriptor *netDesc, QWidget *parent)
{
    this->netDescriptor=netDesc;
    statsLabel.setText(trUtf8("Сбор статистики для всей сети:"));
    mainLayout.addWidget(&statsLabel);

    netStatistic.setText(trUtf8("Собирать статистику для всей сети"));
    netStatistic.setChecked(true);
    mainLayout.addWidget(&netStatistic);

    threadStatsLbl = new QLabel(trUtf8("Сбор статистики для потоков:"));
    mainLayout.addWidget(threadStatsLbl);

    statsFrameLayout=new QVBoxLayout;
    statsFrame.setLayout(statsFrameLayout);
    mainLayout.addWidget(&statsFrame);

    mainLayout.addStretch(1);
    addNavigation();
    this->setLayout(&mainLayout);
}

QCheckBox *StatisticsWindow::getNetStatistic()
{
    return &netStatistic;
}

map<int, QCheckBox*> *StatisticsWindow::getThreadStats()
{
    return &threadStats;
}

StatisticsWindow::~StatisticsWindow()
{
    delete statsFrameLayout;
    statsFrameLayout=0;
    delete threadStatsLbl;
    threadStatsLbl=0;

}

void StatisticsWindow::updateDescriptor()
{

}

void StatisticsWindow::updateInterface()
{
    vector<ThreadDescriptor> *pThreads=netDescriptor->getThreads();

    //убираем удаленные потоки
    map<int, QCheckBox*>::iterator p;
    bool wereChanges=true;
    while(wereChanges)
    {
        wereChanges=false;
        for(p=threadStats.begin();p!=threadStats.end();p++)
        {
            bool exist=false;
            for(int i=0;i<pThreads->size();i++)
            {
                if(p->first==(*pThreads)[i].getId())
                {
                    exist=true;
                    break;
                }
            }
            if(!exist)
            {
                QCheckBox *threadStat=p->second;
                statsFrameLayout->removeWidget(threadStat);
                threadStats.erase(p);
                delete threadStat;
                wereChanges=true;
                break;
            }
        }
    }

    //добавляем новые потоки
    for(int i=0;i<pThreads->size();i++)
    {
        p=threadStats.find((*pThreads)[i].getId());
        if(p==threadStats.end())
        {
            QCheckBox *newThreadStat=new QCheckBox(trUtf8("Собирать статистику для потока %1").arg((*pThreads)[i].getId()));
            newThreadStat->setChecked(true);
            //statsFrame.layout()->addWidget(newThreadStat);
            statsFrameLayout->addWidget(newThreadStat);
            threadStats.insert(std::pair<int,QCheckBox*>((*pThreads)[i].getId(),newThreadStat));
        }
    }

}

}
