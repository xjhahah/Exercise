#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <iostream>
#include <QWidget>

using namespace std;

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
};
#endif // MYWIDGET_H
