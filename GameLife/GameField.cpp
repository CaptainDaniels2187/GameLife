#include <QDebug>
#include "GameField.h"
#include "MyDialogWindow.h"

//Init game field for waiting user input
GameField::GameField(QWidget* parent) : QWidget(parent)
{
	GameTimer = 0;
	isStarted = false;
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
	GameTimer = startTimer(TIMER_STEP_MS);
}

//Stop game timer
void GameField::StopTimer()
{
	killTimer(GameTimer);
	GameTimer = 0;
}

//Reset game to start
void GameField::ResetGame()
{
	//Check for working timer
	if (!GameTimer)
	{
		StopTimer();
	}

	//Reset all data in Simulation
	isStarted = false;
	delete Simulation;
	Simulation = new GameOfLifeSim;

	//Send message to update text label
	emit GenChanged(Simulation->getNumOfCurrentGeneration());

	//Update widget
	this->update();
}

//Sets random value of cells
void GameField::RandomGameSet()
{
	//Check for start the game
	if (!isStarted)
	{
		//Call the sim method
		Simulation->setRandomCells();

		//Update widget
		this->update();
	}
}

//Set state of cell from mouse coordinates
void GameField::setStateOfCellFromCoord(int x, int y)
{
	//Calculating row and column of cell in matrix
	int x_cell = (this->width() - FIELD_RIGHT_MARGIN) / NUM_OF_CELLS_X;
	int y_cell = (this->height() - FIELD_BOTTOM_MARGIN) / NUM_OF_CELLS_Y;
	int row = y / y_cell;
	int column = x / x_cell;
	int return_code = 0;

	//Switch his state
	switch (Simulation->getStateOfCell(column + 1, row + 1))
	{
	case GameOfLifeSim::DEAD:
		return_code = Simulation->setStateOfCell(column + 1, row + 1, GameOfLifeSim::ALIVE);
		break;
	case GameOfLifeSim::ALIVE:
		return_code = Simulation->setStateOfCell(column + 1, row + 1, GameOfLifeSim::DEAD);
		break;
	default:
		return_code = Simulation->setStateOfCell(column + 1, row + 1, GameOfLifeSim::ERR);
		break;
	}

	//Check return code for coorect set state
	if (return_code)
	{
		qDebug() << "Wrong game field coordinate! " << "x: " << column + 1 << "y: " << row + 1;
	}
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
			setStateOfCellFromCoord(event->x(), event->y());
			break;
		default:
			QWidget::mousePressEvent(event);
			break;
		}
	}

	//Update widget
	this->update();
}

//Show the dialog win\lost window
void GameField::showDialog(GameOfLifeSim::StateOfGame state)
{
	//Create dialog window object and set his settings
	MyDialogWindow* endGameWindow = new MyDialogWindow(state, Simulation->getNumOfCurrentGeneration());

	//Start the execution dialog window
	if (endGameWindow->exec() == QDialog::Accepted)
	{
		ResetGame();
	}
	else
	{
		QApplication::quit();
	}

	//Delete resourses
	delete endGameWindow;
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
		emit GenChanged(Simulation->getNumOfCurrentGeneration());

		//Check the state of the game
		switch (state)
		{
		case GameOfLifeSim::ALL_IS_DEAD:
			//Show the dialog window with defeat message
			showDialog(state);
			break;
		case GameOfLifeSim::ONE_OR_MORE_ALIVE:
			break;
		case GameOfLifeSim::WIN:
			//Show the dialog window with win message
			showDialog(state);
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
	//Create canvas
	QPainter painter(this);

	//Set rects border style
	painter.setPen(QPen(Qt::gray, 2));

	//Calculate the rect size
	int x_cell = (this->width() - FIELD_RIGHT_MARGIN) / NUM_OF_CELLS_X;
	int y_cell = (this->height() - FIELD_BOTTOM_MARGIN) / NUM_OF_CELLS_Y;

	//Current pos
	int x = 0, y = 0;

	//Draw the matrix
	for (int i = 1; i <= NUM_OF_CELLS_Y; ++i)
	{
		for (int j = 1; j <= NUM_OF_CELLS_X; ++j)
		{
			switch (Simulation->getStateOfCell(j, i))
			{
			case GameOfLifeSim::ALIVE:
				painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));	//Alive cell is black
				break;
			case GameOfLifeSim::DEAD:
				painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));	//Dead cell is white
				break;
			default:
				qDebug() << "Wrong cell state or coordinates! " << "x: " << j << " " << "y: " << i;
				break;
			}
			painter.drawRect(QRect(x, y, x_cell, y_cell));
			x += x_cell;
		}
		x = 0;
		y += y_cell;
	}
}