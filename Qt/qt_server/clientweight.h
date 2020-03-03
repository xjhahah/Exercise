#ifndef CLIENTWEIGHT_H
#define CLIENTWEIGHT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QString>

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
    void on_SendButton_clicked();

    void on_CloseButton_clicked();

    void on_pushButton_clicked();

    void on_Connect_Button_clicked();

private:
    Ui::ClientWeight *ui;
    QTcpSocket *tcpSocket;
};

#endif // CLIENTWEIGHT_H
