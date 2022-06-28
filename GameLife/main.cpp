#include<QtCore>
#include<QtWidgets>
#include<QtGui>
#include"MyWidget.h"



int main(int args, char** argv)
{
	QApplication GameOfLife(args, argv);
	
	QWidget MainWindow;
	MainWindow.setGeometry(0, 0, 1280, 720);
	MainWindow.setMinimumSize(530, 350);
	MainWindow.setWindowTitle("GameOfLife");

	MyWidget* TestRect = new MyWidget;

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
	QObject::connect(ExitButton, SIGNAL(clicked()), &GameOfLife, SLOT(quit()));
	ExitButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QLabel* TextGenLabel = new QLabel(QString(QString::fromWCharArray(L"Текущее поколение:")));
	QLabel* VolatileNumGenLabel = new QLabel("0");

	QHBoxLayout* hlayout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->setContentsMargins(0, 15, 30, 15);
	vlayout->setSpacing(15);

	hlayout->addWidget(TestRect,1);
	vlayout->addWidget(TextGenLabel, 0, Qt::AlignCenter);
	vlayout->addWidget(VolatileNumGenLabel, 0, Qt::AlignCenter);
	vlayout->addWidget(StartButton, 0, Qt::AlignCenter);
	vlayout->addWidget(ResumeButton, 0, Qt::AlignCenter);
	vlayout->addWidget(PauseButton, 0, Qt::AlignCenter);
	vlayout->addWidget(ResetButton, 0, Qt::AlignCenter);
	vlayout->addWidget(RandomSetButton, 0, Qt::AlignCenter);
	vlayout->addStretch();
	vlayout->addWidget(ExitButton, 0, Qt::AlignCenter);
	hlayout->addLayout(vlayout);
	

	MainWindow.setLayout(hlayout);
	MainWindow.show();

	return GameOfLife.exec();
}