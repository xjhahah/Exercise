#include "clientweight.h"
#include "ui_clientweight.h"

ClientWeight::ClientWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWeight)
{
    ui->setupUi(this);

    isStart = true;

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::readyRead,
            [=](){
        //取出接收到的内容
        QString buf = tcpSocket->readAll();
        if(true == isStart){
            isStart = false;
            //解析头部信息
        }
    });
}

ClientWeight::~ClientWeight()
{
    delete ui;
}
