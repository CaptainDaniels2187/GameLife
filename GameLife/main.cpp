#include<QtCore>
#include<QtWidgets>
#include<QtGui>
#include"MyWidget.h"



int main(int args, char** argv)
{
	QApplication GameLife(args, argv);
	
	QWidget MainWindow;

	MyWidget* TestRect = new MyWidget;

	QPushButton* pb1 = new QPushButton("1");
	QPushButton* pb2 = new QPushButton("2");
	QPushButton* pb3 = new QPushButton("3");
	QPushButton* pb4 = new QPushButton("4");
	QPushButton* pb5 = new QPushButton("5");
	QPushButton* pb6 = new QPushButton("6");

	QHBoxLayout* hlayout = new QHBoxLayout;
	QVBoxLayout* vlayout = new QVBoxLayout;

	hlayout->addWidget(TestRect);
	vlayout->addWidget(pb1);
	vlayout->addWidget(pb2);
	vlayout->addWidget(pb3);
	vlayout->addWidget(pb4);
	vlayout->addWidget(pb5);
	vlayout->addWidget(pb6);
	hlayout->addLayout(vlayout);

	MainWindow.setLayout(hlayout);
	MainWindow.show();



	return GameLife.exec();
}