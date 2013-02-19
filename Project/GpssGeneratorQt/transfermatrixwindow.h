#ifndef TRANSFERMATRIXWINDOW_H
#define TRANSFERMATRIXWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include "networkdescriptor.h"
#include "abstractnavigatablewindow.h"

using std::vector;

namespace GeneratorGpss {

class ThreadMatrix;

class TransferMatrixWindow : public AbstractNavigatableWindow
{
    Q_OBJECT

private:
    //порядок описания полей важен!
    QTabWidget threadTabs;
    vector<ThreadMatrix*> threadMatrixes;

public:
    TransferMatrixWindow(NetworkDescriptor *netDesc,QWidget *parent = 0);
    vector<ThreadMatrix*> *getThreadMatrixes();
    virtual void updateDescriptor();
    virtual void updateInterface();
    virtual ~TransferMatrixWindow();

};

class ThreadMatrix : public QWidget
{
    Q_OBJECT

private:
    int id;
    QVBoxLayout mainLayout;
    QLabel matrixLbl;
    QTableWidget matrix;

public:
    ThreadMatrix(int idThread,vector<NodeDescriptor> *pNodes,QWidget *parent=0);
    int getId();
    QTableWidget *getMatrix();
};

}

#endif // TRANSFERMATRIXWINDOW_H
