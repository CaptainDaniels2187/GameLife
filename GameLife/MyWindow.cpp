#include "MyWindow.h"
#include "GameField.h"

MyWindow::MyWindow(const QApplication& app)
{
	//Set Window settings
	this->setGeometry(DEFAULT_WINDOW_POS_X, DEFAULT_WINDOW_POS_Y, DEFAULT_WINDOW_SIZE_X, DEFAULT_WINDOW_SIZE_Y);
	this->setMinimumSize(DEFAULT_MIN_WINDOW_SIZE_X, DEFAULT_MIN_WINDOW_SIZE_Y);
	this->setWindowTitle(DEFAULT_GAME_TITLE);

	//Calculating center of display
	QRect rect = QApplication::desktop()->availableGeometry();
	QPoint center = rect.center();
	int dx = center.x() - (this->width() / 2);
	int dy = center.y() - (this->height() / 2);
	center.setX(dx);
	center.setY(dy);

	//Move widget to the center
	this->move(center);

	//Create game field widget
	GameField* FieldOfGame = new GameField;

	//Create user interface buttons and fix his sizes
	QPushButton* StartButton = new QPushButton(QString::fromWCharArray(L"?????"));
	StartButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* PauseButton = new QPushButton(QString::fromWCharArray(L"?????"));
	PauseButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* ResetButton = new QPushButton(QString::fromWCharArray(L"?????"));
	ResetButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* RandomSetButton = new QPushButton(QString::fromWCharArray(L"????????? ???????????"));
	RandomSetButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QPushButton* ExitButton = new QPushButton(QString::fromWCharArray(L"?????"));
	ExitButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	//Coonect clicked start button signal to start timer of game
	QObject::connect(StartButton, SIGNAL(clicked()), FieldOfGame, SLOT(StartTimer()));

	//Connect clicked pause button signal to stop timer of game
	QObject::connect(PauseButton, SIGNAL(clicked()), FieldOfGame, SLOT(StopTimer()));

	//Connect clicked reset button signal to reset the game
	QObject::connect(ResetButton, SIGNAL(clicked()), FieldOfGame, SLOT(ResetGame()));

	//Connect clicked random button signal to set random live cells
	QObject::connect(RandomSetButton, SIGNAL(clicked()), FieldOfGame, SLOT(RandomGameSet()));

	//Connect clicked exit button signal to exit app
	QObject::connect(ExitButton, SIGNAL(clicked()), &app, SLOT(quit()));

	//Create text labels for display current game generation 
	QLabel* TextGenLabel = new QLabel(QString::fromWCharArray(L"??????? ?????????:"));
	QLabel* VolatileNumGenLabel = new QLabel("0");

	//Connect volatile num of the game generation to text label
	QObject::connect(FieldOfGame, SIGNAL(GenChanged(int)), VolatileNumGenLabel, SLOT(setNum(int)));

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
	vlayout->addWidget(PauseButton, 0, Qt::AlignCenter);
	vlayout->addWidget(ResetButton, 0, Qt::AlignCenter);
	vlayout->addWidget(RandomSetButton, 0, Qt::AlignCenter);
	vlayout->addStretch();	//Add stretch space between random and exit button
	vlayout->addWidget(ExitButton, 0, Qt::AlignCenter);

	//Add vertical layout with labels and buttons to horizontal(main) layout
	hlayout->addLayout(vlayout);

	//Set layout of MyWindow widget
	this->setLayout(hlayout);
}
