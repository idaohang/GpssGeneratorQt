#ifndef FACILITYWINDOW_H
#define FACILITYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QTabWidget>
#include <QCheckBox>
#include <vector>
#include "networkdescriptor.h"
#include "abstractnavigatablewindow.h"

using std::vector;

namespace GeneratorGpss
{
    class FacilityThreadParams;
    class NetworkDescriptor;

    class FacilityWindow : public AbstractNavigatableWindow
    {
        Q_OBJECT

    private:
        //order of fields definition may be important!
        int id;
        QLabel facilityName;
        QLabel chanelsLabel;
        QLineEdit chanels;
        QHBoxLayout chanelLayout;
        QHBoxLayout memoryLayout;
        QLabel memoryTypeLbl;
        QComboBox memoryType;
        QLabel memoryValueLbl;
        QLineEdit memoryValue;
        QCheckBox addStatisticNodeAllThreads;
        QCheckBox addStatisticQueueAllThreads;
        QHBoxLayout statisticAllThreadsLayout;

        QTabWidget threadTabs;
        vector<FacilityThreadParams*> facilityThreadParams;

    public:
        FacilityWindow(int id, NetworkDescriptor* netDesc,QWidget *parent = 0);
        int getId();
        int getChanelAmount();
        bool statNodeAllThreads();
        bool statQueueAllThreads();
        vector<FacilityThreadParams*> *getFacilityThreadParams();
        virtual void updateDescriptor();
        virtual void updateInterface();
        virtual ~FacilityWindow();

    public slots:
        void memoryTypeChanged(int i);
    };

    class FacilityFunctionWidget : public QWidget
    {
        Q_OBJECT

    private:
        QHBoxLayout mainLayout;
        QComboBox funcType;
        QLabel funcTypeLbl;
        QLineEdit param1;
        QLabel param1Lbl;
        QLineEdit param2;
        QLabel param2Lbl;
        QLineEdit param3;
        QLabel param3Lbl;
    public:
        FacilityFunctionWidget(QWidget *parent=0);
        void mySetDisabled(bool disabled);
        FunctionTypeEnum getFuncType();
        QString getParam1();
        QString getParam2();
        QString getParam3();
    public slots:
        void functionTypeChanged(int i);

    };

    class FacilityThreadParams : public QWidget
    {
        Q_OBJECT

    private:
        int id;
        QCheckBox usingInThread;
        QVBoxLayout mainLayout;
        FacilityFunctionWidget funcParams;
        QCheckBox addStatisticNode;
        QCheckBox addStatisticQueue;

    public:
        FacilityThreadParams(int id,QWidget *parent=0);
        int getId();
        bool IsUsingInThread();
        bool statNode();
        bool statQueue();
        FacilityFunctionWidget *getFuncParams();

    public slots:
        void usingInThreadChecked(bool checked);
    };
}
#endif // FACILITYWINDOW_H
