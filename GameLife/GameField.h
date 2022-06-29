#pragma once

//////////////// CONFIGS /////////////////////
//////////////GAME SETTINGS///////////////////
#ifndef GAME_CONFIGS
#define GAME_CONFIGS

#define WIN_GENERATION 1000

#endif // !GAME_CONFIGS
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

    //Start game timer to 30 frames per second
    void StartTimer();

    //Stop game timer
    void StopTimer();

    //Reset all states of the cells to dead and restart the game
    void ResetGame();

    //Set random value of cells
    void RandomGameSet();

private:

    //Draw the game field
    void paintEvent(QPaintEvent* event);

    //Change game generation by Timer
    void timerEvent(QTimerEvent* event);

    //Set start game field configuration by user click mouse
    void mousePressEvent(QMouseEvent* event);

public:

    //Init the game field
    GameField();
};
#endif // !_BACK
