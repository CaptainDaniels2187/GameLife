#include <cstdlib>
#include <ctime>
#include "GameField.h"

//Init game field for waiting user input
GameField::GameField(QWidget* parent) : QWidget(parent)
{
	GameTimer = 0;
	isStarted = false;
	isWorking = false;
	Simulation = new GameOfLifeSim;
}

//Delete the dynamic field: Simulation
GameField::~GameField()
{
	delete Simulation;
}

//Start or resume game timer
void GameField::StartTimer()
{
	if (!isStarted)
	{
		isStarted = true;
	}
	isWorking = true;
	GameTimer = startTimer(TIMER_STEP_MS);
}

//Stop game timer
void GameField::StopTimer()
{
	isWorking = false;
	killTimer(GameTimer);
}

//Reset game to start
void GameField::ResetGame()
{
	//Check for working timer
	if (isWorking)
	{
		StopTimer();
	}

	//Reset all data in Simulation
	isStarted = false;
	delete Simulation;
	Simulation = new GameOfLifeSim;

	//Update widget
	this->update();
}

//Sets random value of cells
void GameField::RandomGameSet()
{
	//Set random seed to local time
	std::srand(std::time(0));
	
	//Set random value of cells
	for (int i = 0; i < NUM_OF_CELLS_Y; ++i)
	{
		for (int j = 0; j < NUM_OF_CELLS_X; ++j)
		{
			if (Simulation->setStateOfCell(j, i, static_cast<GameOfLifeSim::StateOfCells>(std::rand() % 2)))
			{
				qDebug() << "Wrong game field coordinate! " << "x: " << j << "y: " << i;
			}
		}
	}

	//Update widget
	this->update();
}