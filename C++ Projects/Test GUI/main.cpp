/*
 * File:   main.cpp
 * Author: mark
 *
 * Created on 18. März 2014, 07:39
 */

//#include <QApplication>
#include <QtGui>
#include <QtCore>
#include "QPushButton"
#include "QTextEdit"
#include "QApplication"
#include "QMainWindow"

int main(int argc, char *argv[])
{
	// initialize resources, if needed
	// Q_INIT_RESOURCE(resfile);

	QApplication app(argc, argv);

	// create and show your widgets here
	QMainWindow w();
	
	QPushButton b();
	
	
	return app.exec();
}
