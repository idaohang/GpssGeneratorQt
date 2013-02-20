#include "abstractnavigatablewindow.h"

namespace GeneratorGpss
{

AbstractNavigatableWindow::AbstractNavigatableWindow(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(10,10,1010,410);
}

QPushButton *AbstractNavigatableWindow::getNextButton()
{
    return &nextStepBtn;
}

QPushButton *AbstractNavigatableWindow::getPrevButton()
{
    return &prevStepBtn;
}

void AbstractNavigatableWindow::addNavigation(NavigateEnum navigateType)
{

    line.setFrameShape(QFrame::HLine);
    mainLayout.addWidget(&line);
    nextStepBtn.setText(trUtf8("Next"));
    prevStepBtn.setText(trUtf8("Back"));
    if(navigateType & NAVIGATE_BACK)
        navigateLayout.addWidget(&prevStepBtn,1,Qt::AlignRight);
    if(navigateType & NAVIGATE_NEXT)
        navigateLayout.addWidget(&nextStepBtn,0,Qt::AlignRight);
    mainLayout.addLayout(&navigateLayout);
}

}
