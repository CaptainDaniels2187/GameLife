#include "GameOfLifeSim.h"

//Init all class fields od his default values
GameOfLifeSim::GameOfLifeSim()
{
	numOfCurrentGeneration = 0;

	for (int i = 0; i < NUM_OF_CELLS_Y + 2; ++i)
	{
		for (int j = 0; j < NUM_OF_CELLS_X + 2; ++j)
		{
			CurrentGeneration[i][j] = DEAD;
			NextGeneration[i][j] = 0;
		}
	}
}

//Set cell state durind user click the field
int GameOfLifeSim::setStateOfCell(int x, int y, StateOfCells state)
{
	if (x >= 1 && x <= NUM_OF_CELLS_X && y >= 1 && y <= NUM_OF_CELLS_Y)
	{
		CurrentGeneration[y][x] = state;
		return 0;
	}
	else
	{
		return 1;
	}
}

//Return cell state for check him
GameOfLifeSim::StateOfCells GameOfLifeSim::getStateOfCell(int x, int y) const
{
	if (x >= 1 && x <= NUM_OF_CELLS_X && y >= 1 && y <= NUM_OF_CELLS_Y)
	{
		return CurrentGeneration[y][x];
	}
	else
	{
		return ERR;
	}
}

//Get num of current generation
int GameOfLifeSim::getNumOfCurrentGeneration() const
{
	return numOfCurrentGeneration;
}

//Set fictional rows and colums during the game
void GameOfLifeSim::setFictionalState()
{
	for (int i = 1; i <= NUM_OF_CELLS_X; ++i)
	{
		CurrentGeneration[0][i] = CurrentGeneration[NUM_OF_CELLS_Y][i];
	}
	for (int i = 1; i <= NUM_OF_CELLS_X; ++i)
	{
		CurrentGeneration[NUM_OF_CELLS_Y + 1][i] = CurrentGeneration[1][i];
	}
	for (int i = 1; i <= NUM_OF_CELLS_Y; ++i)
	{
		CurrentGeneration[i][0] = CurrentGeneration[i][NUM_OF_CELLS_X];
	}
	for (int i = 1; i <= NUM_OF_CELLS_Y; ++i)
	{
		CurrentGeneration[i][NUM_OF_CELLS_X + 1] = CurrentGeneration[i][1];
	}
	CurrentGeneration[0][0] = CurrentGeneration[NUM_OF_CELLS_Y][NUM_OF_CELLS_X];
	CurrentGeneration[NUM_OF_CELLS_Y + 1][0] = CurrentGeneration[1][NUM_OF_CELLS_X];
	CurrentGeneration[NUM_OF_CELLS_Y + 1][NUM_OF_CELLS_X + 1] = CurrentGeneration[1][1];
	CurrentGeneration[0][NUM_OF_CELLS_X + 1] = CurrentGeneration[NUM_OF_CELLS_Y][1];
}

//This function simulates next generation in Game of Life accorfing to the rules of the game
//It is simple algorithm. It is based on counting the values of 8 neighboring cells and writing them into a next generation array.
//Then these numbers are compared, as well as the current state of the cell, 
//according to the rules of the game, and new values are already set.
GameOfLifeSim::StateOfGame GameOfLifeSim::NextStep()
{
	if (numOfCurrentGeneration < WIN_GENERATION)
	{
		setFictionalState();

		//Forming value of the neighbors [i][j] cell
		for (int i = 1; i <= NUM_OF_CELLS_Y; ++i)
		{
			for (int j = 1; j <= NUM_OF_CELLS_X; ++j)
			{
				NextGeneration[i][j] = 0;
				NextGeneration[i][j] += CurrentGeneration[i - 1][j - 1];
				NextGeneration[i][j] += CurrentGeneration[i][j - 1];
				NextGeneration[i][j] += CurrentGeneration[i + 1][j - 1];
				NextGeneration[i][j] += CurrentGeneration[i + 1][j];
				NextGeneration[i][j] += CurrentGeneration[i + 1][j + 1];
				NextGeneration[i][j] += CurrentGeneration[i][j + 1];
				NextGeneration[i][j] += CurrentGeneration[i - 1][j + 1];
				NextGeneration[i][j] += CurrentGeneration[i - 1][j];
			}
		}

		//Check for one or nore alive
		bool atLeastOneAlive = false;

		//According to the rules of the game
		//Empty cell in current generation: value of neighbors = 3 - set new life, else nothing
		//Live cell in current generation: value of neighbors = 2 or 3 - continue live, else die
		for (int i = 1; i <= NUM_OF_CELLS_Y; ++i)
		{
			for (int j = 1; j <= NUM_OF_CELLS_X; ++j)
			{
				if ((CurrentGeneration[i][j] == ALIVE && (NextGeneration[i][j] == 2 || NextGeneration[i][j] == 3)) ||
					(CurrentGeneration[i][j] == DEAD && NextGeneration[i][j] == 3))
				{
					if (!atLeastOneAlive)
					{
						atLeastOneAlive = true;
					}
					CurrentGeneration[i][j] = ALIVE;
				}
				else
				{
					CurrentGeneration[i][j] = DEAD;
				}
			}
		}

		if (atLeastOneAlive)
		{
			numOfCurrentGeneration++;
			return ONE_OR_MORE_ALIVE;
		}
		else
		{
			return ALL_IS_DEAD;
		}
	}
	else
	{
		return WIN;
	}
}