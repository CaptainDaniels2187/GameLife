#pragma once

#define _BACK

#include "Config.h"

class GameOfLifeSim
{
public:

	enum StateOfGame { ALL_IS_DEAD, ONE_OR_MORE_ALIVE, WIN = WIN_GENERATION };
	enum StateOfCells { DEAD, ALIVE, ERR };

private:
	
	int numOfCurrentGeneration;
	StateOfCells CurrentGeneration[NUM_OF_CELLS_Y + 2][NUM_OF_CELLS_X + 2];	//We will add fictional rows and columns from each edge 
	char NextGeneration[NUM_OF_CELLS_Y + 2][NUM_OF_CELLS_X + 2];	//for the closeness of the playing field

	//Set fictional rows and colums during the game
	void setFictionalState();

	//Cells ccordinates:
	//x : 1 .. NUM_OF_CELLS_X
	//y : 1 .. NUM_OF_CELLS_Y

public:

	//Init all class fields
	GameOfLifeSim();

	//Set random value of cells
	void setRandomCells();

	//Simlation of Game Of Life
	//Return codes:
	//0 - all is dead
	//1 - at least one is alive
	//1000 - win code
	StateOfGame NextStep();	//perfomance is important

	//Set cells state before start the game
	//Return codes:
	//0 - set is correct
	//1 - set is incorrect
	int setStateOfCell(int x, int y, StateOfCells state);

	//Get cells state
	StateOfCells getStateOfCell(int x, int y) const;

	//Get num of current generation
	int getNumOfCurrentGeneration() const;
};

