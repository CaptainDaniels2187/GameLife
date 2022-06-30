#include "MyDialogWindow.h"

MyDialogWindow::MyDialogWindow(GameOfLifeSim::StateOfGame state, int numOfEndGeneration, QWidget* parent)
	: QDialog(parent)
{
	//Set dialog window settings
	this->setWindowFlags(Qt::Window | Qt::WindowTitleHint);

	//Create win\lost text label
	QLabel* TextMessage = new QLabel;

	//Set the text according the game state
	switch (state)
	{
	case GameOfLifeSim::ALL_IS_DEAD:
		TextMessage->setText(QString::fromWCharArray(L"Вся жизнь погибла за ") + QString::number(numOfEndGeneration) +
			QString::fromWCharArray(L" поколений. Вы проиграли."));
		break;
	case GameOfLifeSim::WIN:
		TextMessage->setText(QString::fromWCharArray(L"Вы продержались 1000 поколений. Мои поздравления."));
		break;
	default:
		TextMessage->setText("Error");
		break;
	}

	//Create the question label
	QLabel* Question = new QLabel(QString::fromWCharArray(L"Желаете ли вы начать заново?"));

	//Create user interface buttons
	QPushButton* ResetButton = new QPushButton(QString::fromWCharArray(L"Да"));
	QPushButton* ExitButton = new QPushButton(QString::fromWCharArray(L"Выход"));

	//Connect buttons to dialog window slots
	QObject::connect(ResetButton, SIGNAL(clicked()), this, SLOT(accept()));
	QObject::connect(ExitButton, SIGNAL(clicked()), this, SLOT(reject()));

	//Create layouts for placement widgets
	QVBoxLayout* vlayout = new QVBoxLayout;
	QHBoxLayout* hlayout = new QHBoxLayout;

	//Add text label in center vlayout
	vlayout->addWidget(TextMessage, 0, Qt::AlignCenter);
	vlayout->addWidget(Question, 0, Qt::AlignCenter);

	//Add buttons in hlayout
	hlayout->addWidget(ResetButton);
	hlayout->addWidget(ExitButton);

	//Add buttons layout in main layout
	vlayout->addLayout(hlayout);

	//Set layout in main widget
	this->setLayout(vlayout);
}