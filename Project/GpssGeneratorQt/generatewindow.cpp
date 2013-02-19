#include "generatewindow.h"
#include <QFileDialog>

namespace GeneratorGpss
{

GenerateWindow::GenerateWindow(NetworkDescriptor *netDesc,QWidget *parent):AbstractNavigatableWindow(parent)
{
    this->netDescriptor=netDesc;

    fileNameLbl.setText(trUtf8("Файл для сохранения GPSS-текста: "));
    chooseFileButton.setText(trUtf8("Выбрать..."));
    chooseFileLayout.addWidget(&fileNameLbl);
    chooseFileLayout.addWidget(&fileName);
    chooseFileLayout.addWidget(&chooseFileButton);
    mainLayout.addLayout(&chooseFileLayout);
    connect(&chooseFileButton,SIGNAL(clicked()),this,SLOT(chooseFileClicked()));

    descriptionLbl.setText(trUtf8("Описание сети:"));
    description.setReadOnly(true);
    description.setText(trUtf8("Количество потоков: %1\nКоличество узлов: %2").arg(netDescriptor->getThreads()->size()).arg(netDescriptor->getNodes()->size()));
    mainLayout.addWidget(&descriptionLbl);
    mainLayout.addWidget(&description);

    mainLayout.addStretch(1);
    addNavigation();
    this->getNextButton()->setText(trUtf8("Генерировать"));
    this->setLayout(&mainLayout);
}

void GenerateWindow::addExitButton()
{
    exitButton.setText(trUtf8("Выход"));
    mainLayout.addWidget(&exitButton,0,Qt::AlignRight);
    connect(&exitButton,SIGNAL(clicked()),this,SLOT(exitClicked()));
}

void GenerateWindow::exitClicked()
{
    this->close();
}

void GenerateWindow::chooseFileClicked()
{
    QString sFileName=QFileDialog::getSaveFileName(this,trUtf8("Задайте файл для сохранения GPSS-текста модели"),QDir::currentPath(),tr("Text (.txt)"));
    if(!sFileName.isNull())
    {
        fileName.setText(sFileName);
    }
}

QString GenerateWindow::getFileName()
{
    return fileName.text();
}

QTextEdit *GenerateWindow::getDescription()
{
    return &description;
}

void GenerateWindow::updateDescriptor()
{

}

void GenerateWindow::updateInterface()
{

}

GenerateWindow::~GenerateWindow()
{

}

}
