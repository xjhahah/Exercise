#include "serverwidget.h"
#include "ui_serverwidget.h"

#include <QDebug>
#include <QString>
#include <QFileDialog> //文件对话框头文件

#define cout qDebug() << "[" << __FILE__ << __LINE__ << "]"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    //初始化
    tcpServer = nullptr;
    tcpSocket = nullptr;


    //分配空间，监听套接字
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8080);

    setWindowTitle("服务器端口：8080");

    //连接不成功之前，按钮不能使用
    ui->ButtonFile->setEnabled(false);
    ui->ButtonSend->setEnabled(false);

    //如果客户端和服务器连接成功
    //会自动触发newConnection
    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
        //1.取出建立好的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //2.得到对放的IP和端口号
        QString ip = tcpSocket->peerAddress().toString();
        auto port = tcpSocket->peerPort();

        //3.组装IP和port
        QString str = QString("[%1:%2] 连接成功").arg(ip).arg(port);

        //4.显示到编辑区
        ui->FiletextEdit->setText(str);

        //5.链接成功之后，按钮才可以使用
        ui->ButtonFile->setEnabled(true);
        ui->ButtonSend->setEnabled(true);

    }
    );



}

ServerWidget::~ServerWidget()
{
    delete ui;
}


//选择文件的按钮
void ServerWidget::on_ButtonFile_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"open","../");

    //判断打开是否成功
    if(false == filePath.isEmpty()){
        fileName.clear();
        fileSize = 0;
        //获取文件信息
        QFileInfo info(filePath);
        fileName = info.fileName(); //获取文件名称
        fileSize = info.size();     //获取文件大小

        sendSize = 0;
        //只读方式打开文件，指定文件的名字
        file.setFileName(filePath);

        //打开文件
        bool flag = file.open(QIODevice::ReadOnly);
        if(flag == false){
            cout << "文件打开失败！！！";
        }
        else{
            //提示打开文件路径
            ui->FiletextEdit->append(filePath);
            ui->ButtonFile->setEnabled(false);
            ui->ButtonSend->setEnabled(true);
        }

        //只读方式打开

    }
    else{
        cout << "文件路径出错...";
    }
}
