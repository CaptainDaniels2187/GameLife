#pragma once

//////////////// CONFIGS /////////////////////
//////////////////////////////////////////////
////////////GAME FIELD SETTINGS///////////////
#define NUM_OF_CELLS_X 45
#define NUM_OF_CELLS_Y 25
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
    bool isPossibleClicked;

    //Slots to operate game
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

};
#endif // !_BACK
