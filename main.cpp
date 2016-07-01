#include <iostream>
#include <QtWidgets/qapplication.h>
#include "header files/MainWindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication myApp(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return myApp.exec();
}