#ifndef CLIENTWEIGHT_H
#define CLIENTWEIGHT_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QFile>

#include <QTcpSocket>
#include <QTcpServer>

#include <QMessageBox>

namespace Ui {
class ClientWeight;
}

class ClientWeight : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWeight(QWidget *parent = nullptr);
    ~ClientWeight();

private slots:
    void on_buttonConnect_clicked();

private:
    Ui::ClientWeight *ui;

    QTcpSocket   *tcpSocket;
    QFile        file; //文件对象
    QString      fileName; //文件名
    qint64       fileSize; //文件大小
    qint64       recvSize; //接收文件的大小
    bool         isStart;
};

#endif // CLIENTWEIGHT_H
