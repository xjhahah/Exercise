#include "widget.h"
#include "ui_widget.h"
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QEvent>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <iostream>

using namespace std;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->setupUi(this);
    setWindowTitle(tr("文件传输服务器"));

    //清空列表

    server = new Myserver(this);
    server->listen(QHostAddress::Any, 8080);
    closeCommand = 0; //1 表示客户端断开连接

    ui->ClientPB1->setEnabled((false));
    ui->ClientPB2->setEnabled((false));
    ui->ClientPB3->setEnabled((false));

    //为三个按键安装事件过滤器    即断开链接按钮
    ui->ClientPB1->installEventFilter((this));
    ui->ClientPB2->installEventFilter((this));
    ui->ClientPB2->installEventFilter((this));


    ui->LBstate1->setText((tr("断开连接")));
    ui->LBstate2->setText((tr("断开连接")));
    ui->LBstate3->setText((tr("断开连接")));


}

Widget::~Widget()
{
    delete ui;
}

