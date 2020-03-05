#include "clientweight.h"
#include "ui_clientweight.h"

#include <QHostAddress>

#define cout qDebug() << "[" << __FILE__ << __LINE__ << "]"


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
        auto buf = tcpSocket->readAll();
        if(true == isStart){  //接收头
            isStart = false;
            //解析头部信息
            //初始化
            fileName = QString(buf).section("##",0,0);
            fileSize = QString(buf).section("##",1,1).toInt();

            recvSize = 0;

            //打开文件
            file.setFileName(fileName);
            bool flag = file.open(QIODevice::WriteOnly);

            if(flag == false){
                cout << "文件打开失败...";
            }
        }else{  //文件信息
            auto len = file.write(buf);
            recvSize += len;
            if(recvSize == fileSize){
                file.close();
                QMessageBox::information(this,"完成","文件接收成功");

                tcpSocket->disconnectFromHost();
                tcpSocket->close();
            }
        }
    });
}

ClientWeight::~ClientWeight()
{
    delete ui;
}

void ClientWeight::on_buttonConnect_clicked()
{
    //获取服务器的IP和端口
    QString ip = ui->lineEditIP->text();
    auto port = ui->lineEditPort->text().toInt();

    tcpSocket->connectToHost(QHostAddress(ip),port);
}
