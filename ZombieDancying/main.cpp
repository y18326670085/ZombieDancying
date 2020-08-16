#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //代表整个程序的基础 本程序和其它程序的一些交互
    QApplication a(argc, argv);

    //基本显示控件
    MainWidget w;
    w.show();
    return a.exec();
}
