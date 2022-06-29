#pragma once

#include <QtWidgets>
#include "Config.h"

class MyWindow :
    public QWidget
{
Q_OBJECT

public:

    //Initialization of all widgets
    MyWindow(const QApplication& app);
};

