#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QFrame>
#include <map>
#include <utility>
#include "abstractnavigatablewindow.h"
#include "networkdescriptor.h"

using std::map;

namespace GeneratorGpss
{


class StatisticsWindow : public AbstractNavigatableWindow
{
    Q_OBJECT

private:
    //order of fields definition may be important!
    QLabel statsLabel;
    QLabel *threadStatsLbl;
    QCheckBox netStatistic;
    map<int, QCheckBox*> threadStats;


    QFrame statsFrame;
    QVBoxLayout *statsFrameLayout;

public:
    StatisticsWindow(NetworkDescriptor *netDesc,QWidget *parent = 0);
    QCheckBox *getNetStatistic();
    map<int, QCheckBox*> *getThreadStats();
    virtual void updateDescriptor();
    virtual void updateInterface();
    virtual ~StatisticsWindow();
};

}
#endif // STATISTICSWINDOW_H
