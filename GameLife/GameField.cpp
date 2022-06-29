#include "GameField.h"
#include <QDebug>

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
		GameTimer = 0;
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

//Show the dialog win\lost window
void GameField::showDialog(GameOfLifeSim::StateOfGame state)
{
	//Create dialog window object and set his settings
	QDialog* endGameWindow = new QDialog;
	endGameWindow->setWindowFlags(Qt::Window | Qt::WindowTitleHint);

	//Create win\lost text label
	QLabel* TextMessage = new QLabel;

	//Set the text according the game state
	switch (state)
	{
	case GameOfLifeSim::ALL_IS_DEAD:
		TextMessage->setText(QString::fromWCharArray(L"Вся жизнь погибла за ") + QString::number(Simulation->getNumOfCurrentGeneration()) +
			QString::fromWCharArray(L" поколений. Вы проиграли."));
		break;
	case GameOfLifeSim::WIN:
		TextMessage->setText(QString::fromWCharArray(L"Вы продержались 1000 поколений. Мои поздравления"));
		break;
	default:
		TextMessage->setText("Error");
		break;
	}

	//Create the question label
	QLabel* Question = new QLabel(QString(QString::fromWCharArray(L"Желаете ли вы начать заново?")));

	//Create user interface buttons
	QPushButton* ResetButton = new QPushButton(QString(QString::fromWCharArray(L"Да")));
	QPushButton* ExitButton = new QPushButton(QString(QString::fromWCharArray(L"Выход")));

	//Connect buttons to dialog window slots
	QObject::connect(ResetButton, SIGNAL(clicked()), endGameWindow, SLOT(accept()));
	QObject::connect(ExitButton, SIGNAL(clicked()), endGameWindow, SLOT(reject()));

	//Create layouts for placement widgets
	QVBoxLayout* vlayout = new QVBoxLayout;
	QHBoxLayout* hlayout = new QHBoxLayout;

	//Add text label in center vlayout
	vlayout->addWidget(TextMessage, 0, Qt::AlignCenter);
	vlayout->addWidget(Question,0, Qt::AlignCenter);

	//Add buttons in hlayout
	hlayout->addWidget(ResetButton);
	hlayout->addWidget(ExitButton);

	//Add buttons layout in main layout
	vlayout->addLayout(hlayout);

	//Set layout in main widget
	endGameWindow->setLayout(vlayout);

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

	//Curren pos
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
	//painter.drawRect(QRect(this->pos(), this->pos() + QPoint(this->width() - FIELD_RIGHT_MARGIN, this->height() - FIELD_BOTTOM_MARGIN)));
}