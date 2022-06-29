#pragma once

#include <QtWidgets>
#include "GameOfLifeSim.h"

class GameField :
    public QWidget
{
Q_OBJECT

private:

    int GameTimer;
    GameOfLifeSim* Simulation;
    bool isStarted;
    bool isWorking;

//Signals send to others
signals:
    void GenChanged(int);

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

    //Set start game field configuration by user click mouse
    void mousePressEvent(QMouseEvent* event);

    //Change game generation by Timer
    void timerEvent(QTimerEvent* event);

    //Draw the game field
    void paintEvent(QPaintEvent* event);

    //Show the dialog win\lost window
    void showDialog(GameOfLifeSim::StateOfGame state);

public:

    //Init the game field
    GameField(QWidget* parent = nullptr);

    //Correct destroy all class fields 
    ~GameField();
};
