#include "transfermatrixwindow.h"

namespace GeneratorGpss
{

TransferMatrixWindow::TransferMatrixWindow(NetworkDescriptor *netDesc,QWidget *parent):AbstractNavigatableWindow(parent)
{
    this->netDescriptor=netDesc;
    vector<ThreadDescriptor> *pThreads=netDesc->getThreads();
    vector<NodeDescriptor> *pNodes=netDesc->getNodes();
    for(int i=0;i<pThreads->size();i++)
    {
        threadMatrixes.push_back(new ThreadMatrix((*pThreads)[i].getId(),pNodes));
        threadTabs.addTab(threadMatrixes.back(),trUtf8("Thread №%1").arg((*pThreads)[i].getId()));
    }

    mainLayout.addWidget(&threadTabs);
    addNavigation();

    this->setLayout(&mainLayout);
}

vector<ThreadMatrix*> *TransferMatrixWindow::getThreadMatrixes()
{
    return &threadMatrixes;
}

void TransferMatrixWindow::updateDescriptor()
{

}

void TransferMatrixWindow::updateInterface()
{
    vector<ThreadDescriptor> *pThreads=netDescriptor->getThreads();
    vector<NodeDescriptor> *pNodes=netDescriptor->getNodes();
    //adding new threads
    for(int i=0;i<pThreads->size();i++)
    {
        bool found=false;
        for(int j=0;j<threadMatrixes.size();j++)
        {
            if((*pThreads)[i].getId()==threadMatrixes[j]->getId())
            {
                found=true;
                break;
            }
        }
        if(!found)
        {
            threadMatrixes.push_back(new ThreadMatrix((*pThreads)[i].getId(),pNodes));
            threadTabs.addTab(threadMatrixes.back(),trUtf8("Thread №%1").arg((*pThreads)[i].getId()));
        }
    }

    //Deleting old threads
    bool wereChanges=true;
    while(wereChanges)
    {
        wereChanges=false;
        for(int i=0;i<threadMatrixes.size();i++)
        {
            bool exist=false;
            for(int j=0;j<pThreads->size();j++)
            {
                if(threadMatrixes[i]->getId()==(*pThreads)[j].getId())
                {
                    exist=true;
                    break;
                }
            }
            if(!exist)
            {
                threadTabs.removeTab(i);
                threadMatrixes.erase(threadMatrixes.begin()+i);
                wereChanges=true;
                break;
            }
        }
    }

    //adding new nodes
    QTableWidget *curMatrix;
    for(int t=0;t<threadMatrixes.size();t++)
    {
        curMatrix=threadMatrixes[t]->getMatrix();

        for(int i=2;i<pNodes->size();i++)
        {
            bool found=false;
            for(int j=1;j<curMatrix->rowCount()-1;j++)
            {
                if(curMatrix->verticalHeaderItem(j)->data(Qt::UserRole)==(*pNodes)[i].getId())
                {
                    found=true;
                    break;
                }
            }

            if(!found)
            {
                int insertedIndex=curMatrix->rowCount()-1;
                QTableWidgetItem *itemToInsert;
                curMatrix->insertRow(insertedIndex);
                curMatrix->insertColumn(insertedIndex);
                int curNodes=curMatrix->rowCount();

                itemToInsert=new QTableWidgetItem(tr("b%1").arg((*pNodes)[i].getId()));
                itemToInsert->setData(Qt::UserRole,(*pNodes)[i].getId());
                curMatrix->setVerticalHeaderItem(insertedIndex,itemToInsert);
                itemToInsert=new QTableWidgetItem(tr("b%1").arg((*pNodes)[i].getId()));
                itemToInsert->setData(Qt::UserRole,(*pNodes)[i].getId());
                curMatrix->setHorizontalHeaderItem(insertedIndex,itemToInsert);

                for(int j=0;j<curNodes;j++)
                {
                    curMatrix->setItem(insertedIndex,j,new QTableWidgetItem(tr("0")));
                    if(j!=insertedIndex)
                    {
                        curMatrix->setItem(j,insertedIndex,new QTableWidgetItem(tr("0")));
                    }
                }
            }
        }
    }

    //deleting new nodes
    wereChanges=true;
    while(wereChanges)
    {
        wereChanges=false;
        for(int t=0;t<threadMatrixes.size();t++)
        {
            curMatrix=threadMatrixes[t]->getMatrix();
            for(int i=1;i<curMatrix->rowCount()-1;i++)
            {
                bool exist=false;
                for(int j=2;j<pNodes->size();j++)
                {
                    if((*pNodes)[j].getId()==curMatrix->verticalHeaderItem(i)->data(Qt::UserRole))
                    {
                        exist=true;
                        break;
                    }
                }

                if(!exist)
                {
                    curMatrix->removeRow(i);
                    curMatrix->removeColumn(i);
                    wereChanges=true;
                    break;
                }
            }
        }
    }

    for(int i=0;i<threadMatrixes.size();i++)
    {
        threadMatrixes[i]->getMatrix()->resizeColumnsToContents();
    }
}

TransferMatrixWindow::~TransferMatrixWindow()
{

}

ThreadMatrix::ThreadMatrix(int threadId, vector<NodeDescriptor> *pNodes, QWidget *parent):QWidget(parent)
{
    int nodes=pNodes->size();
    id=threadId;
    matrixLbl.setText(trUtf8("Matrix of transfer:"));
    mainLayout.addWidget(&matrixLbl);

    matrix.hasMouseTracking();

    QTableWidgetItem *curItem;
    matrix.setColumnCount(nodes);
    matrix.setRowCount(nodes);
    curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[0].getId()));
    curItem->setData(Qt::UserRole,(*pNodes)[0].getId());
    matrix.setHorizontalHeaderItem(0,curItem);
    curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[1].getId()));
    curItem->setData(Qt::UserRole,(*pNodes)[1].getId());
    matrix.setHorizontalHeaderItem(nodes-1,curItem);
    curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[0].getId()));
    curItem->setData(Qt::UserRole,(*pNodes)[0].getId());
    matrix.setVerticalHeaderItem(0,curItem);
    curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[1].getId()));
    curItem->setData(Qt::UserRole,(*pNodes)[1].getId());
    matrix.setVerticalHeaderItem(nodes-1,curItem);
    for(int i=1;i<matrix.columnCount()-1;i++)
    {
        curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[i+1].getId()));
        curItem->setData(Qt::UserRole,(*pNodes)[i+1].getId());
        matrix.setHorizontalHeaderItem(i,curItem);
    }
    for(int i=1;i<matrix.rowCount()-1;i++)
    {
        curItem=new QTableWidgetItem(tr("b%1").arg((*pNodes)[i+1].getId()));
        curItem->setData(Qt::UserRole,(*pNodes)[i+1].getId());
        matrix.setVerticalHeaderItem(i, curItem);
    }
    for(int i=0;i<matrix.columnCount();i++)
    {
        for(int j=0;j<matrix.rowCount();j++)
        {
            matrix.setItem(i,j,new QTableWidgetItem(tr("0")));
        }
    }
    mainLayout.addWidget(&matrix);

    this->setLayout(&mainLayout);
}

int ThreadMatrix::getId()
{
    return id;
}

QTableWidget *ThreadMatrix::getMatrix()
{
    return &matrix;
}

}
