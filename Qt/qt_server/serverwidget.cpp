#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    tcpServer = nullptr;
    tcpSocket = nullptr;


    //设置监听套接字，指定父对象，使其自动回收空间
    tcpServer = new QTcpServer(this);

    //listen,指定端口号和任意IP
    tcpServer->listen(QHostAddress::Any,8080);

    //设定标题
    setWindowTitle("服务器：8080");

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


        //TODO
        connect(tcpSocket,&QTcpSocket::readyRead,
                [=](){
            //从通信套接字中取数据
            QByteArray array = tcpSocket->readAll();
            ui->ReadButton->append(array);

        }
        );
    }
    );


}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_SendButton_clicked()
{
    if(nullptr == tcpSocket){
        return;
    }

    //获取编辑区内容
    QString str = ui->WriteButton->toPlainText();

    //给对方发数据，使用的套接字是tcpSocket
    //
    tcpSocket->write(str.toUtf8().data());

}

void ServerWidget::on_CloseButton_clicked()
{
    if(nullptr == tcpSocket){
        return;
    }
    //主动和客户端断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = nullptr;
}
