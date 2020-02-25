#include "mywidget.h"

#include <QApplication>

//Qt头文件没有.h
//头文件和类名一样
int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象
    QApplication a(argc, argv);   //应用程序类

    //Myweight和Qweight（窗口基类）是父子关系
    //w 就是一个窗口
    MyWidget w;


    //窗口创建默认是隐藏，需要人为显示
    w.show();

    //让程序一直执行，直到有事件发生
    return a.exec();
}
