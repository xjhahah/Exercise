#include "myserver.h"

Myserver::Myserver(QObject *parent)
{
    socketNum = 0;
    //获得当前widget对象
    widget = dynamic_cast<Widget*>(parent);
}
