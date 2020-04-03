#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>


#include "myserver.h"
#include "debuginfo.h"

class string;
class QEvent;
class Myserver;
class QListWidgetItem;


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    //重新实现时间

private:
    Ui::Widget *ui;

    //断开客户端链接命令，1表示断开
    int closeCommand = 1;
    //存储添加的文件路径
    QString dirPath;
    //文件列表指针
    FILE* fp;

    Myserver *server;

    //目录列表存储结构体
    struct DirInformation{
        char fileName[250]; //文件名
        char dirName[250];  //目录名
        unsigned int isDir; //判断是否为目录
        unsigned int isFile; //判断是否为文件
        unsigned int topDir; //判断是否为顶层文件
    }dirInfo;

    //判断目录
    void isDirectory(){
        dirInfo.topDir = 0;
        strcpy(dirInfo.fileName," ");
        dirInfo.isDir = 1;
        dirInfo.isFile = 0;
    }
    //判断文件
    void isFile(){
        dirInfo.topDir = 0;
        strcpy(dirInfo.dirName," ");
        dirInfo.isDir = 0;
        dirInfo.isFile = 1;
    }
};
#endif // WIDGET_H
