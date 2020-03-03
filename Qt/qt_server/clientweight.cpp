#include "clientweight.h"
#include "ui_clientweight.h"

ClientWeight::ClientWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWeight)
{
    ui->setupUi(this);

    setWindowTitle("客户端");

    //初始化通信套接字
    tcpSocket = nullptr;

    //分配空间，并初始化
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket,&QTcpSocket::connected,
            [=](){
        ui->ReadEdit->setText("和服务器连接成功...");
    }
    );


    connect(tcpSocket,&QTcpSocket::readyRead,
            [=](){
        //获取编辑区内容
        QByteArray arr = tcpSocket->readAll();
        //追加到编辑区中
        ui->ReadEdit->append(arr);

    }
    );
}

ClientWeight::~ClientWeight()
{
    delete ui;
}

void ClientWeight::on_SendButton_clicked()
{
    //获取编辑区内容
    QString str = ui->WriteEdit->toPlainText();
    //发送数据
    tcpSocket->write(str.toUtf8().data());
}

void ClientWeight::on_CloseButton_clicked()
{
    //主动断开链接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();

}

void ClientWeight::on_Connect_Button_clicked()
{
    //获取端口号和IP
    QString ip = ui->IP_Button->text();
    auto port = ui->Portbutton->text().toInt();

    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(ip),port);
}
