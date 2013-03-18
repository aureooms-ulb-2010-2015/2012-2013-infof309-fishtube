#include "MainWindow.h"
#include <QApplication>
#include <X11/Xlib.h>
#include <iostream>
#include <QTextCodec>


int main(int argc, char *argv[]){
	//Allows concurrent threads to make Xlib calls. (Use with OpenGL rendering threads)
	//std::cout << XInitThreads() << std::endl;
	std::cout << std::endl;

	//résouds les problèmes d'accents
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
	a.setOrganizationName("ULB");
    a.setApplicationName("FishTube");
	MainWindow w;
    w.show();
    return a.exec();
}
