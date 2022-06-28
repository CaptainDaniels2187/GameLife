#pragma once
#include <QtWidgets>

//////////////// CONFIGS /////////////////////
//////////////////////////////////////////////
/////////////WINDOW SETTINGS//////////////////
#define DEFAULT_WINDOW_POS_X 0
#define DEFAULT_WINDOW_POS_Y 0

#define DEFAULT_WINDOW_SIZE_X 1280
#define DEFAULT_WINDOW_SIZE_Y 720

#define DEFAULT_MIN_WINDOW_SIZE_X 530
#define DEFAULT_MIN_WINDOW_SIZE_Y 350

#define DEFAULT_GAME_TITLE "GameOfLife"
//////////////////////////////////////////////
//////////VERTICAL LAYOUT SETTINGS////////////
#define V_DEFAULT_LEFT_MARGIN 0
#define V_DEFAULT_TOP_MARGIN 15
#define V_DEFAULT_RIGHT_MARGIN 30
#define V_DEFAULT_BOTTOM_MARGIN 15

#define V_DEFAULT_SPACING 15
//////////////////////////////////////////////
//////////////////////////////////////////////

class MyWindow :
    public QWidget
{
Q_OBJECT
public:
    //Initialization of all widgets
    MyWindow(const QApplication& app);
};

