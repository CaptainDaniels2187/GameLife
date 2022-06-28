#pragma once
#include <qwidget.h>
#include<QtWidgets>

class MyWidget :
    public QWidget
{
Q_OBJECT
public:

private:
    int num;
    void paintEvent(QPaintEvent* event);
signals:
    void MySignal();
};

