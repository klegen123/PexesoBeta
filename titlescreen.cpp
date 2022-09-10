#include "titlescreen.h"
#include "pexeso_controller.h"

TitleScreen::TitleScreen(QWidget *parent)
    : QMainWindow(parent), ui(new TitleScreenUI)
{
    ui->setupUi(this);
    setConnections();
}

void TitleScreen::setConnections()
{
    connect(ui->easyButton, SIGNAL(toggled(bool)), SLOT(updateEasyGame(bool)));
    connect(ui->normalButton, SIGNAL(toggled(bool)), SLOT(updateNormalGame(bool)));
    connect(ui->hardButton, SIGNAL(toggled(bool)), SLOT(updateHardGame(bool)));
    connect(ui->startButton, SIGNAL(clicked()), SLOT(startGame()));
}

void TitleScreen::updateEasyGame(bool checked){
    if (checked){
        boardSize = 4;
    }
}

void TitleScreen::updateNormalGame(bool checked){
    if (checked){
        boardSize = 6;
    }
}

void TitleScreen::updateHardGame(bool checked){
    if (checked){
        boardSize = 8;
    }
}

void TitleScreen::startGame()
{
    this->hide();
    PEXESO_Controller pexeso(boardSize);
    pexeso.startGame();
    this->show();
}

void TitleScreen::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    emit exited();
}
