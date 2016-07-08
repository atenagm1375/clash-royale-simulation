#include <iostream>
#include <QtWidgets/qapplication.h>
#include "header files/Window.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication myApp(argc, argv);
    Window window;
    window.mainWindow.show();
    return myApp.exec();
}