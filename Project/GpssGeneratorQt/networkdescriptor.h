#ifndef NETWORKDESCRIPTOR_H
#define NETWORKDESCRIPTOR_H

#include <QString>
#include <vector>

using std::vector;

namespace GeneratorGpss
{

enum ThreadTypeEnum {OPEN, CLOSED};
enum NodeTypeEnum {FACILITY, TRANSFER, STATISTIC, GENERATOR, TERMINATOR};
enum PriorityTypeEnum {NONE, RELATIVE, ABSOLUTE};
enum FunctionTypeEnum {EXPONENTIAL, UNIFORM, TRIANGLE};
enum StorageTypeEnum {INFINITE, LIMITED};

class ThreadDescriptor
{
private:
    static int _id;
    int id;
    QString name;
    ThreadTypeEnum type;

public:
    ThreadDescriptor();
    ThreadDescriptor(const ThreadDescriptor &obj);
    void setName(QString name);
    void setType(ThreadTypeEnum type);
    int getId();
    QString getName();
    ThreadTypeEnum getType();
};

class NodeDescriptor
{
private:
    static int _id;
    int id;
    QString name;
    NodeTypeEnum type;
public:
    NodeDescriptor();
    void setName(QString name);
    void setType(NodeTypeEnum type);
    int getId();
    QString getName();
    NodeTypeEnum getType();
};


//,     ,
class NetworkDescriptor
{

private:
    vector<ThreadDescriptor> threads;
    vector<NodeDescriptor> nodes;

public:
    NetworkDescriptor();
    vector<ThreadDescriptor> *getThreads();
    vector<NodeDescriptor> *getNodes();
    ThreadDescriptor* getThreadById(int i);
    NodeDescriptor* getNodeById(int i);
};


}

#endif // NETWORKDESCRIPTOR_H
