#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <vector>
#include "nodeswindow.h"
#include "threadswindow.h"
#include "generatewindow.h"
#include "facilitywindow.h"
#include "networkdescriptor.h"
#include "transfermatrixwindow.h"
#include "statisticswindow.h"
#include "abstractnavigatablewindow.h"
#include "Generator/Model.h"
#include "Generator/Generator.h"
#include "Generator/Terminator.h"
#include "Generator/Facility.h"
#include "Generator/Router.h"
#include <QStackedLayout>

using std::vector;

namespace GeneratorGpss
{

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    QStackedLayout mainLayout;
    int position;
    NetworkDescriptor netDescriptor;
    ThreadsWindow threadsWindow;
    NodesWindow nodesWindow;
    vector<FacilityWindow*> nodes;
    StatisticsWindow statsWindow;
    GenerateWindow generateWindow;
    TransferMatrixWindow transferMatrixWindow;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setDescriptionString();
    GeneratorGPSS::Model *interfaceToModel();
    GeneratorGPSS::Generator *getGenerator(int thread, int node);
    GeneratorGPSS::Terminator *getTerminator(int node);
    GeneratorGPSS::Facility *getFacility(int node);
    GeneratorGPSS::Router *getTransfer(int node);
    NodeTypeEnum getNodeTypeById(int id);
    void setThreadTypesInDescriptor();
public slots:
    void nextButtonClicked();
    void prevButtonClicked();
};

}
#endif // MAINWINDOW_H
