#include<QtCore>
#include<QtWidgets>
#include<QtGui>
#include"MyWidget.h"



int main(int args, char** argv)
{
	QApplication GameLife(args, argv);
	
	QWidget MainWindow;
	MainWindow.setGeometry(0, 0, 1280, 720);

	MyWidget* TestRect = new MyWidget;

	QPushButton* pb1 = new QPushButton(QString(QString::fromWCharArray(L"Старт")));
	pb1->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb2 = new QPushButton(QString(QString::fromWCharArray(L"Продолжить")));
	pb2->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb3 = new QPushButton(QString(QString::fromWCharArray(L"Пауза")));
	pb3->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb4 = new QPushButton(QString(QString::fromWCharArray(L"Сброс")));
	pb4->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb5 = new QPushButton(QString(QString::fromWCharArray(L"Случайная расстановка")));
	pb5->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb6 = new QPushButton(QString(QString::fromWCharArray(L"Выход")));
	pb6->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

	QHBoxLayout* hlayout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->setContentsMargins(0, 15, 30, 15);
	vlayout->setSpacing(15);
	//vlayout->

	hlayout->addWidget(TestRect);
	vlayout->addWidget(pb1);
	vlayout->addWidget(pb2);
	vlayout->addWidget(pb3);
	vlayout->addWidget(pb4);
	vlayout->addWidget(pb5);
	vlayout->addStretch();
	vlayout->addWidget(pb6);
	hlayout->addLayout(vlayout);

	MainWindow.setLayout(hlayout);
	MainWindow.show();



	return GameLife.exec();
}