#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>

#include <QFile>
#include <QDebug>
#include <QString>

#include <QFileInfo> //获取文件信息
#include <QFileDialog> //文件对话框头文件
#include <QTimer>  //定时器

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>



QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

    void SendData();

private slots:
    void on_ButtonFile_clicked();

    void on_ButtonSend_clicked();

private:
    Ui::ServerWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QFile            file; //文件对象
    QString      fileName; //文件名
    qint64       fileSize; //文件大小
    qint64       sendSize; //发送文件的大小
    QTimer       time;
};
#endif // SERVERWIDGET_H
