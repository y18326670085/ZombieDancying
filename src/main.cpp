#include "MainWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // 代表是整个程序的基础 本程序和其他程序的一些交互
    QApplication a(argc, argv);
    // 基本显示控件
    MainWidget w;
    w.show();
    // a.exec调用程序生成
    return a.exec();
}
