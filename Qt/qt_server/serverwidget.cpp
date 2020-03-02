#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    //设置监听套接字，指定父对象，使其自动回收空间
    tcpServer = new QTcpServer(this);

    //listen,指定端口号和任意IP
    tcpServer->listen(QHostAddress::Any,8080);

    //TODO
    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
        //取出建立好链接的套接字
        tcpSocket = tcpServer->nextPendingConnection();

        //获取对方的IP和端口号
        QString ip = tcpSocket->peerAddress().toString();
        auto port = tcpSocket->peerPort();

        //将获取到的IP和端口进行组装便于打印
        QString tmp = QString("[%1：%2]: 连接成功").arg(ip).arg(port);

        //将获取到的信息打印到屏幕
        ui->ReadButton->setText(tmp);
    }
    );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_SendButton_clicked()
{
    //获取编辑区内容
    QString str = ui->WriteButton->toPlainText();

    //给对方发数据，使用的套接字是tcpSocket
    //
    tcpSocket->write(str.toUtf8().data());

}
