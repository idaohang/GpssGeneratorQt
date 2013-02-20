#ifndef ABSTRACTNAVIGATABLEWINDOW_H
#define ABSTRACTNAVIGATABLEWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QMainWindow>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include "networkdescriptor.h"

namespace GeneratorGpss
{

enum NavigateEnum {NAVIGATE_BACK=1, NAVIGATE_NEXT=2,NAVIGATE_ALL=3};

class AbstractNavigatableWindow : public QWidget
{
    Q_OBJECT

protected:
    //order of fields definition may be important!
    NetworkDescriptor *netDescriptor;
    QVBoxLayout mainLayout;

    QFrame line;
    QHBoxLayout navigateLayout;
    QPushButton nextStepBtn;
    QPushButton prevStepBtn;
public:
    AbstractNavigatableWindow(QWidget *parent=0);
    QPushButton *getNextButton();
    QPushButton *getPrevButton();
    virtual void updateDescriptor()=0;
    virtual void updateInterface()=0;

protected:
    void addNavigation(NavigateEnum navigateType=NAVIGATE_ALL);
};

}

#endif // ABSTRACTNAVIGATABLEWINDOW_H
