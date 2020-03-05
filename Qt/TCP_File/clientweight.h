#ifndef CLIENTWEIGHT_H
#define CLIENTWEIGHT_H

#include <QWidget>

#include <QString>
#include <QFile>

#include <QTcpSocket>


namespace Ui {
class ClientWeight;
}

class ClientWeight : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWeight(QWidget *parent = nullptr);
    ~ClientWeight();

private:
    Ui::ClientWeight *ui;

    QTcpSocket* tcpSocket;
    QString      fileName; //文件名
    qint64       fileSize; //文件大小
    qint64       recvSize; //接收文件的大小

    bool         isStart = true;
};

#endif // CLIENTWEIGHT_H
