#include "serverwidget.h"
#include "ui_serverwidget.h"


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

    connect(&time,&QTimer::timeout,
            [=](){
        time.stop();

        //调用发送文件函数
        SendData();
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


//发送文件按钮
void ServerWidget::on_ButtonSend_clicked()
{
    //先发送头部信息   文件名#文件大小
    QString head = QString("%1##%1").arg(fileName).arg(fileSize);

    //发送头部信息
    auto len = tcpSocket->write(head.toUtf8());

    if(len < 0){
        cout << "文件发送失败...";
        file.close();

        ui->ButtonFile->setEnabled(true);
        ui->ButtonSend->setEnabled(false);
    }else{  //头部信息发送成功
        //发送真正的信息，防止TCP粘包，设置定时器
        time.start(20);  //延迟20ms
    }
}


void ServerWidget::SendData(){
    auto len = 0;
    do{
        //每次发送数据的大小
        char buf[1024*4] = {0};
        len = 0;

        //向文件中写内容
        len = file.read(buf,sizeof(buf));

        //读多少写多少
        len = tcpSocket->write(buf,len);

        //将发送的数据进行累加
        sendSize += len;

    }while(len);

    //文件发送完毕
    if(sendSize == fileSize){
        ui->FiletextEdit->append("文件发送完成!");
        file.close();

        //断开客户端
        tcpSocket->disconnectFromHost();
        tcpSocket->close();

    }
}
