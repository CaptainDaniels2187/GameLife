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
	pb1->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb2 = new QPushButton("2");
	pb2->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb3 = new QPushButton("3");
	pb3->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb4 = new QPushButton("4");
	pb4->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb5 = new QPushButton("5");
	pb5->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
	QPushButton* pb6 = new QPushButton("6");
	pb6->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

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