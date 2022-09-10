#include "pexeso.h"
#include "titlescreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TitleScreen TitleScreen;
    TitleScreen.show();
    //closing the application after closing title screen
    QObject::connect(&TitleScreen, &TitleScreen::exited, &a, &QApplication::quit);
    return a.exec();
}
