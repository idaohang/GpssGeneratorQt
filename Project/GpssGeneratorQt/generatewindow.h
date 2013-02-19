#ifndef GENERATEWINDOW_H
#define GENERATEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QTextEdit>
#include "networkdescriptor.h"
#include "abstractnavigatablewindow.h"

namespace GeneratorGpss
{
class GenerateWindow : public AbstractNavigatableWindow
{
    Q_OBJECT

private:
    QLabel fileNameLbl;
    QLineEdit fileName;
    QPushButton chooseFileButton;
    QHBoxLayout chooseFileLayout;

    QLabel descriptionLbl;
    QTextEdit description;
public:
    GenerateWindow(NetworkDescriptor *netDesc,QWidget *parent = 0);
    QString getFileName();
    QTextEdit *getDescription();
    QPushButton exitButton;
    void addExitButton();
    virtual void updateDescriptor();
    virtual void updateInterface();
    virtual ~GenerateWindow();
public slots:
    void chooseFileClicked();
    void exitClicked();
};
}
#endif // GENERATEWINDOW_H
