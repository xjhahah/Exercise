#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>
#include<QWidget>
#include<QTcpServer>
#include<QFile>
#include<QByteArray>
#include<QProgressDialog>
#include<stdio.h>
#include<QMutex>
#include <QMetaType>



QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_toolButton_triggered(QAction *arg1);

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_3_editingFinished();

private:
    Ui::ClientWindow *ui;

    QTcpSocket *tcpSocket;
    QString ip;
    QString port;

};
#endif // CLIENTWINDOW_H
