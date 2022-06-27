#include<QtWidgets/QApplication>
#include<QtWidgets/Qlabel>

int main(int args, char** argv)
{
	QApplication GameLife(args, argv);
	QLabel* TestLabel = new QLabel("Hello World!");
	TestLabel->show();
	return GameLife.exec();
}