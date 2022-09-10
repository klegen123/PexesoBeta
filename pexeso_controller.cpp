#include "pexeso_controller.h"
#include "pexeso.h"

#include <unistd.h>

PEXESO_Controller::PEXESO_Controller(int &boardSize, QObject *parent)
    :   QObject(parent), p(boardSize), boardSize(boardSize), currentPlayer(1),
      clickNumber(0)
{
    playButtons=p.buildPlayButtons();
    setConnections();
}

void PEXESO_Controller::setConnections(){
    for (QPlayButton &playButton : playButtons){
        connect(playButton.cellBtn, &QPushButton::clicked, [&] { updateGame(playButton); });
    }
    connect(&p, &PEXESO::newGame, this, [&] { reset(); });
}
void PEXESO_Controller::reset(){
    currentPlayer = 1;
    clickNumber=0;
    p.reset(playButtons);
}

void PEXESO_Controller::switchPlayer(){
    if (currentPlayer==1){
        currentPlayer = 2;
    }else{
        currentPlayer = 1;
    }
}

void PEXESO_Controller::startGame(){
    p.exec();
}

void PEXESO_Controller::updateGame(QPlayButton &playButton){
    if (playButton.counted!=true){
    this->p.updatePlayButton(playButton);
    p.repaint();
    clickNumber++;

    if (clickNumber==1){
        clickedBtn1=playButton.btnID;
    }else{
        clickedBtn2=playButton.btnID;
        clickNumber=0;
        sleep(1);
        checkTurnPoints();
    }
    }
}

void PEXESO_Controller::checkTurnPoints(){
    if (clickedBtn1!=clickedBtn2){
        if (playButtons.at(clickedBtn1).value==playButtons.at(clickedBtn2).value){
            p.updateScore(currentPlayer);
            playButtons.at(clickedBtn1).counted=true;
            playButtons.at(clickedBtn2).counted=true;
        }else{
            playButtons.at(clickedBtn1).counted=false;
            playButtons.at(clickedBtn2).counted=false;
            p.updateTurn();
            switchPlayer();
        }
    }
    p.resetPlayButtons(playButtons);
    p.checkResults();
}
