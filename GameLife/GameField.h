#pragma once

//////////////// CONFIGS /////////////////////
//////////////////////////////////////////////
////////////GAME FIELD SETTINGS///////////////
#ifndef FIELD_CONFIGS
#define FIELD_CONFIGS

#define NUM_OF_CELLS_X 45
#define NUM_OF_CELLS_Y 25

#endif // !FIELD_CONFIGS
//////////////////////////////////////////////

#ifndef _BACK
#include <QtWidgets>
#include "GameOfLifeSim.h"

class GameField :
    public QWidget
{
Q_OBJECT

private:

    GameOfLifeSim Simulation;
    bool isStarted;

//Slots to operate the game
public slots:

    void StartTimer();
    void StopTimer();
    void ResetGame();
    void RandomGameSet();

private:

    //Draw the game field
    void paintEvent(QPaintEvent* event);

    //Change game generation by Timer
    void timerEvent(QTimerEvent* event);

    //Set start game field configuration by user click mouse
    void mousePressEvent(QMouseEvent* event);
};
#endif // !_BACK
