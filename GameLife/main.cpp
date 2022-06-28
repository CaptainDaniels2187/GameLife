#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include "MyWindow.h"



int main(int args, char** argv)
{
	//Create application object
	QApplication GameOfLife(args, argv);
	
	//Initialization Main Window
	MyWindow Window(GameOfLife);

	//Show Window
	Window.show();

	return GameOfLife.exec();
}