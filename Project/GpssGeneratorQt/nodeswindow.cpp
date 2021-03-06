
#include "nodeswindow.h"
#include <QMessageBox>

namespace GeneratorGpss
{

//NodesWindow ========================================================
NodesWindow::NodesWindow(NetworkDescriptor *netDesc,QWidget *parent):AbstractNavigatableWindow(parent)
{
    netDescriptor=netDesc;

    nodesLbl.setText(trUtf8("Nodes of the model:"));
    mainLayout.addWidget(&nodesLbl);

    //adding generator, terminator and one facility by default
    nodesFrameLayout.addWidget(createNewNodeWidget());
    nodeWidgets.back()->getDeleteButton()->hide();

    vector<NodeTypeEnum> nodeTypes;
    nodeTypes.push_back(GENERATOR);
    nodeWidgets.back()->setPossibleNodeTypes(nodeTypes);
    nodeTypes.clear();
    nodesFrameLayout.addWidget(createNewNodeWidget());
    nodeWidgets.back()->getDeleteButton()->hide();
    nodeTypes.push_back(TERMINATOR);
    nodeWidgets.back()->setPossibleNodeTypes(nodeTypes);
    nodesFrameLayout.addWidget(createNewNodeWidget());
    nodesFrame.setLayout(&nodesFrameLayout);
    mainLayout.addWidget(&nodesFrame);

    mainLayout.addStretch(1);

    addNodeBtn.setText(trUtf8("Add node"));
    mainLayout.addWidget(&addNodeBtn,0,Qt::AlignRight);
    addNavigation();
    this->setLayout(&mainLayout);

    connect(&addNodeBtn,SIGNAL(clicked()),this,SLOT(addNodeClick()));
}

void NodesWindow::updateDescriptor()
{
    NodeTypeEnum curNodeType;
    int curId;
    vector<NodeDescriptor> *pNodes=netDescriptor->getNodes();
    int curIndex;
    for(int i=0;i<nodeWidgets.size();i++)
    {
        curId=nodeWidgets[i]->getId();
        for(curIndex=0;curIndex<pNodes->size();curIndex++)
        {
            if((*pNodes)[curIndex].getId()==curId)
                break;
        }

        curNodeType=nodeWidgets[i]->getNodeType();
        (*pNodes)[curIndex].setType(curNodeType);
    }
}

void NodesWindow::updateInterface()
{

}

NodeWidget *NodesWindow::createNewNodeWidget()
{
    vector<NodeDescriptor> *pNodes=netDescriptor->getNodes();
    pNodes->push_back(NodeDescriptor());
    NodeWidget *nodeWidget=new NodeWidget(pNodes->back().getId());
    nodeWidgets.push_back(nodeWidget);

    connect(nodeWidget->getDeleteButton(),SIGNAL(clicked()),this,SLOT(deleteNodeClick()));
    return nodeWidget;
}

NodesWindow::~NodesWindow()
{
    for(int i=0;i<nodeWidgets.size();i++)
    {
        delete nodeWidgets[i];
        nodeWidgets[i]=0;
    }
}

void NodesWindow::addNodeClick()
{
    QWidget *newNodeWidget=createNewNodeWidget();

    nodesFrameLayout.addWidget(newNodeWidget);
}

void NodesWindow::deleteNodeClick()
{
    QPushButton *senderBtn=qobject_cast<QPushButton*>(sender());
    for(int i=0;i<nodeWidgets.size();i++)
    {
        //selection of nodeWidget, that corespondes to button
        if(nodeWidgets[i]->getDeleteButton()==senderBtn)
        {
            NodeWidget *tmp=nodeWidgets[i];

            //deleting node from model
            vector<NodeDescriptor> *pNodes=netDescriptor->getNodes();
            for(int j=0;j<pNodes->size();j++)
            {
                if(tmp->getId()==(*pNodes)[j].getId())
                {
                    pNodes->erase(pNodes->begin()+j);
                    break;
                }
            }

            nodesFrameLayout.removeWidget(tmp);
            nodeWidgets.erase(nodeWidgets.begin()+i);
            delete tmp;
            tmp=0;
            break;
        }
    }
}


//NodeWidget ========================================================
NodeWidget::NodeWidget(int id,QWidget *parent):QWidget(parent)
{
    this->id=id;
    nodeName.setText(trUtf8("Node b%1").arg(id));

    nodeTypeLbl.setText(trUtf8("Node type: "));

    vector<NodeTypeEnum> nodeTypes;
    nodeTypes.push_back(FACILITY);
    nodeTypes.push_back(TRANSFER);
    nodeTypes.push_back(STATISTIC);
    setPossibleNodeTypes(nodeTypes);

    mainLayout.addWidget(&nodeName);
    mainLayout.addWidget(&nodeTypeLbl);
    mainLayout.addWidget(&nodeType);
    mainLayout.addStretch(1);

    deleteButton.setText(trUtf8("Delete"));
    mainLayout.addWidget(&deleteButton,0,Qt::AlignRight);
    this->setLayout(&mainLayout);
}

NodeTypeEnum NodeWidget::getNodeType()
{
    return (NodeTypeEnum)nodeType.itemData(nodeType.currentIndex()).toInt();
}

void NodeWidget::setPossibleNodeTypes(vector<NodeTypeEnum> &nodeTypes)
{
    nodeType.clear();
    QString nodeTypeString;
    for(int i=0;i<nodeTypes.size();i++)
    {
        switch(nodeTypes[i])
        {
        case FACILITY:
            nodeTypeString=trUtf8("Facility");
            break;
        case GENERATOR:
            nodeTypeString=trUtf8("Generator");
            break;
        case TERMINATOR:
            nodeTypeString=trUtf8("Terminator");
            break;
        case TRANSFER:
            nodeTypeString=trUtf8("Transfer");
            break;
        case STATISTIC:
            nodeTypeString=trUtf8("Statistic");
            break;
        }
        nodeType.addItem(nodeTypeString,QVariant::fromValue((int)nodeTypes[i]));
    }
}

QLabel *NodeWidget::getNodeName()
{
    return &nodeName;
}

NodeWidget::~NodeWidget()
{

}

int NodeWidget::getId()
{
    return id;
}

QPushButton *NodeWidget::getDeleteButton()
{
    return &deleteButton;
}

}
