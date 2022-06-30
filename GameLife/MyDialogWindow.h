#pragma once

#include <QtWidgets>
#include "GameOfLifeSim.h"

class MyDialogWindow :
    public QDialog
{
Q_OBJECT

public:

    MyDialogWindow(GameOfLifeSim::StateOfGame state, int numOfEndGeneration, QWidget* parent = nullptr);
};

