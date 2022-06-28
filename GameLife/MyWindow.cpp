#include "MyWindow.h"
#include "GameField.h"

MyWindow::MyWindow(const QApplication& app)
{
	//Set Window settings
	this->setGeometry(DEFAULT_WINDOW_POS_X, DEFAULT_WINDOW_POS_Y, DEFAULT_WINDOW_SIZE_X, DEFAULT_WINDOW_SIZE_Y);
	this->setMinimumSize(DEFAULT_MIN_WINDOW_SIZE_X, DEFAULT_MIN_WINDOW_SIZE_Y);
	this->setWindowTitle(DEFAULT_GAME_TITLE);

	//Create game field widget
	GameField* FieldOfGame = new GameField;

	//Create user interface buttons and fix his sizes
	QPushButton* StartButton = new QPushButton(QString(QString::fromWCharArray(L"Старт")));
	StartButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* ResumeButton = new QPushButton(QString(QString::fromWCharArray(L"Продолжить")));
	ResumeButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* PauseButton = new QPushButton(QString(QString::fromWCharArray(L"Пауза")));
	PauseButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* ResetButton = new QPushButton(QString(QString::fromWCharArray(L"Сброс")));
	ResetButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* RandomSetButton = new QPushButton(QString(QString::fromWCharArray(L"Случайная расстановка")));
	RandomSetButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* ExitButton = new QPushButton(QString(QString::fromWCharArray(L"Выход")));
	ExitButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	//Coonect clicked start button signal to start timer of game
	QObject::connect(StartButton, SIGNAL(clicked()), FieldOfGame, SLOT(StartTimer()));

	//Connect clicked resume button signal to resume timer of game
	QObject::connect(ResumeButton, SIGNAL(clicked()), FieldOfGame, SLOT(StartTimer()));

	//Connect clicked pause button signal to stop timer of game
	QObject::connect(PauseButton, SIGNAL(clicked()), FieldOfGame, SLOT(StopTimer()));

	//Connect clicked reset button signal to reset the game
	QObject::connect(ResetButton, SIGNAL(clicked()), FieldOfGame, SLOT(ResetGame()));

	//Connect clicked random button signal to set random live cells
	QObject::connect(RandomSetButton, SIGNAL(clicked()), FieldOfGame, SLOT(RandomGameSet));

	//Connect clicked exit button signal to exit app
	QObject::connect(ExitButton, SIGNAL(clicked()), &app, SLOT(quit()));

	//Create text labels for display current game generation 
	QLabel* TextGenLabel = new QLabel(QString(QString::fromWCharArray(L"Текущее поколение:")));
	QLabel* VolatileNumGenLabel = new QLabel("0");

	//Create layouts for widgets and set his settings
	QHBoxLayout* hlayout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->setContentsMargins(V_DEFAULT_LEFT_MARGIN, V_DEFAULT_TOP_MARGIN, V_DEFAULT_RIGHT_MARGIN, V_DEFAULT_BOTTOM_MARGIN);
	vlayout->setSpacing(V_DEFAULT_SPACING);

	//Add game field widget to horizontal layout
	hlayout->addWidget(FieldOfGame, 1);	//stretch = 1 to right align of buttons and labels

	//Add text labels and buttons 
	vlayout->addWidget(TextGenLabel, 0, Qt::AlignCenter);
	vlayout->addWidget(VolatileNumGenLabel, 0, Qt::AlignCenter);
	vlayout->addWidget(StartButton, 0, Qt::AlignCenter);
	vlayout->addWidget(ResumeButton, 0, Qt::AlignCenter);
	vlayout->addWidget(PauseButton, 0, Qt::AlignCenter);
	vlayout->addWidget(ResetButton, 0, Qt::AlignCenter);
	vlayout->addWidget(RandomSetButton, 0, Qt::AlignCenter);
	//Add Stretch space between random and exit button
	vlayout->addStretch();
	vlayout->addWidget(ExitButton, 0, Qt::AlignCenter);

	//Add vertical layout with labels and buttons to horizontal(main) layout
	hlayout->addLayout(vlayout);

	//Set layout of MyWindow widget
	this->setLayout(hlayout);
}
