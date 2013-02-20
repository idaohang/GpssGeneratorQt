#ifndef THREADSWINDOW_H
#define THREADSWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <vector>
#include "abstractnavigatablewindow.h"
#include "networkdescriptor.h"

using std::vector;

namespace GeneratorGpss
{

class NetworkDescriptor;
class ThreadWidget;

class ThreadsWindow : public AbstractNavigatableWindow
{
    Q_OBJECT

private:
    //order of fields definition may be important!
    QPushButton addThreadBtn;
    QFrame threadsFrame;
    QVBoxLayout threadsFrameLayout;
    vector<ThreadWidget*> threadWidgets;
    QHBoxLayout netTypeLayout;
    QLabel netTypeLbl;
    QComboBox netType;
    QLabel threadLbl;

public:
    ThreadsWindow(NetworkDescriptor *netDesc,QWidget *parent = 0);
    virtual void updateDescriptor();
    virtual void updateInterface();
    vector<ThreadWidget*> *getThreadWidgets();
    virtual ~ThreadsWindow();

private:
    ThreadWidget *createNewThreadWidget();

public slots:
    void addThreadClick();
    void deleteThreadClick();
};

class ThreadWidget : public QWidget
{
    Q_OBJECT

public:
    ThreadWidget(int id, QWidget *parent=0);
    virtual ~ThreadWidget();

private:
    int id;
    QHBoxLayout mainLayout;
    QVBoxLayout threadTypeLayout;
    QComboBox threadType;
    QVBoxLayout threadFuncLayout;
    QComboBox threadFunc;
    QLineEdit param1;
    QLineEdit param2;
    QLineEdit param3;
    QVBoxLayout priorityLayout;
    QVBoxLayout priorityValueLayout;
    QComboBox priorityType;
    QLineEdit priorityValue;
    QLabel threadFuncLbl;
    QLabel param1Lbl;
    QLabel param2Lbl;
    QLabel param3Lbl;
    QLabel priorityValueLbl;
    QLabel priorityTypeLbl;
    QLabel threadTypeLbl;
    QPushButton deleteButton;
    QVBoxLayout param1Layout;
    QVBoxLayout param2Layout;
    QVBoxLayout param3Layout;

public:
    ThreadTypeEnum getType();
    FunctionTypeEnum getFunc();
    QString getParam1();
    QString getParam2();
    QString getParam3();
    QPushButton *getDeleteButton();
    int getId();

public slots:
    void typeChanged(int i);
    void funcChanged(int i);
    void priorityTypeChanged(int i);
};

}
#endif // THREADSWINDOW_H
