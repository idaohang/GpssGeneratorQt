#ifndef NODESWINDOW_H
#define NODESWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QComboBox>
#include <vector>
#include "networkdescriptor.h"
#include "abstractnavigatablewindow.h"

using std::vector;

namespace GeneratorGpss
{

class NetworkDescriptor;
class NodeWidget;

class NodesWindow : public AbstractNavigatableWindow
{
    Q_OBJECT

private:
    //порядок описания полей важен!
    QLabel nodesLbl;
    QPushButton addNodeBtn;
    QFrame nodesFrame;
    QVBoxLayout nodesFrameLayout;
    vector<NodeWidget*> nodeWidgets;

public:
    NodesWindow(NetworkDescriptor *netDesc,QWidget *parent = 0);
    virtual void updateDescriptor();
    virtual void updateInterface();
    virtual ~NodesWindow();
private:
    NodeWidget *createNewNodeWidget();

public slots:
    void addNodeClick();
    void deleteNodeClick();
};

class NodeWidget : public QWidget
{
public:
    NodeWidget(int id, QWidget *parent=0);
    virtual ~NodeWidget();

private:
    int id;
    QHBoxLayout mainLayout;
    QLabel nodeName;
    QLabel nodeTypeLbl;
    QComboBox nodeType;
    QPushButton deleteButton;

public:
    void setPossibleNodeTypes(vector<NodeTypeEnum> &nodeTypes);
    NodeTypeEnum getNodeType();
    QLabel *getNodeName();
    int getId();
    QPushButton *getDeleteButton();
};

}
#endif // NODESWINDOW_H
