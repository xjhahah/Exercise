#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_lineEdit_3_editingFinished()
{
    ip = ui->lineEdit->text();
    ui->textBrowser->setText(ip);
    ui->lineEdit->setText(ip);

}
