#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    //构造函数 生成对象需要的函数
    MainWidget(QWidget *parent = nullptr);

    //释放对象需要的函数
    ~MainWidget();
};
#endif // MAINWIDGET_H
