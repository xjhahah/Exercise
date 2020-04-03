#ifndef MYSERVER_H
#define MYSERVER_H

#include "widget.h"
#include "mythread.h"
#include "debuginfo.h"

class widget;
class Mythread;

class Myserver:public QTcpServer
{
    Q_OBJECT
public:
    Myserver(QObject* parent);
    ~Myserver()
    {}

    //存储建立连接的客户端套接字
    QList<int> socketList;
    //存储线程
    QList<Mythread *> threadList;
    //存储客户端IP地址
    QList<QString> socketIp;
    //客户端数量
    int socketNum;
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
   Widget *widget;

};

#endif // MYSERVER_H
