#pragma once

#define _BACK
#include "GameField.h"

class GameOfLifeSim
{
private:
	
	int numOfCurrentGeneration;
	char CurrentGeneration[NUM_OF_CELLS_Y][NUM_OF_CELLS_X];
	char NextGeneration[NUM_OF_CELLS_Y][NUM_OF_CELLS_X];

public:
	enum StateOfGame { ALL_IS_DEAD, ONE_OR_MORE_ALIVE, WIN = 1000 };
	enum StateOfCells { DEAD, ALIVE };
	//Simlation of Game Of Life
	//Return codes:
	//0 - all is dead
	//1 - at least one is alive
	//1000 - win code
	int NextStep();
};

