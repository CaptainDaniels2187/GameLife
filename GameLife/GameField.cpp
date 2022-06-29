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
	//Call the sim method
	Simulation->setRandomCells();

	//Update widget
	this->update();
}

//Processing user mouse click before start the game and set game field cells value
void GameField::mousePressEvent(QMouseEvent* event)
{
	//Check for starting the game
	if (!isStarted)
	{
		//Check for left mouse button click
		switch (event->button())
		{
		case Qt::LeftButton:
			Simulation->setStateOfCellFromCoord(event->x(), event->y(), this->width(), this->height());
			break;
		default:
			QWidget::mousePressEvent(event);
			break;
		}
	}

	//Update widget
	this->update();
}

//Processing the Game of Life and calculate next generation
void GameField::timerEvent(QTimerEvent* event)
{
	//Check for correct TimerEvent
	if (event->timerId() == GameTimer)
	{
		//Simulate next step
		GameOfLifeSim::StateOfGame state = Simulation->NextStep();

		//Update widget
		this->update();

		//Send a signal to TextLabel for change the text num of generation
		//...

		//Check the state of the game
		switch (state)
		{
		case GameOfLifeSim::ALL_IS_DEAD:
			StopTimer();
			//Show the dialog window with defeat message
			//...
			break;
		case GameOfLifeSim::ONE_OR_MORE_ALIVE:
			break;
		case GameOfLifeSim::WIN:
			StopTimer();
			//Show the dialog window with win message
			//...
			break;
		default:
			qDebug() << "Wrong game state!";
			break;
		}
	}
}

//Draw the game field...
void GameField::paintEvent(QPaintEvent* event)
{
	qDebug() << "Doing nothing)))";
}