#include "MyWindow.h"
#include "MyWidget.h"

MyWindow::MyWindow(const QApplication& app)
{
	//Set Window settings
	this->setGeometry(0, 0, 1280, 720);
	this->setMinimumSize(530, 350);
	this->setWindowTitle("GameOfLife");

	//Create game field widget
	MyWidget* TestRect = new MyWidget;

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

	//Connect clicked exit button signal to exit app
	QObject::connect(ExitButton, SIGNAL(clicked()), &app, SLOT(quit()));

	//Create text labels for display current game generation 
	QLabel* TextGenLabel = new QLabel(QString(QString::fromWCharArray(L"Текущее поколение:")));
	QLabel* VolatileNumGenLabel = new QLabel("0");

	//Create layouts for widgets and set his settings
	QHBoxLayout* hlayout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->setContentsMargins(0, 15, 30, 15);
	vlayout->setSpacing(15);

	//Add game field widget to horizontal layout
	hlayout->addWidget(TestRect, 1);	//stretch = 1 to right align of buttons and labels

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
