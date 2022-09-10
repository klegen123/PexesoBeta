#include "pexeso.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QGridLayout>
#include <QProcess>
#include <QMessageBox>
#include <string>
#include <ctime>

#include <unistd.h>

PEXESO::PEXESO(const int &boardSize, QWidget *parent)
    : QDialog(parent), player1Score(0), player2Score(0), turnNumber(1),
      ui(new PEXESO_UI), boardSize(boardSize)
{
    ui->setupUi(this);
    setConnections();
}

void PEXESO::setConnections(){
    connect(ui->restartButton, &QPushButton::clicked, [=] { emit newGame(); });
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

vector<QPlayButton> PEXESO::buildPlayButtons(){
    vector<QPlayButton> playButtons;
    const QSize btnSize = QSize(100, 100);
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            QPushButton *btnGrid = new QPushButton();
            ui->lGrid->addWidget(btnGrid, y, x);
            btnGrid->setFixedSize(btnSize);
            playButtons.emplace_back(btnGrid, y, x);
        }
    }
    srand(time(NULL));
    for(int q=0; q < boardSize*boardSize; q++)
    {
        a: playButtons.at(q).value = (1+rand()%(boardSize*boardSize)/2);
        int z=0;
        for (int j=0; j<q; j++){
            if (playButtons.at(j).value==playButtons.at(q).value && j!=q){
                z++;
                if(z==2){goto a;}
                }
        }
        playButtons.at(q).btnID=q;
    }

    return playButtons;
}

void PEXESO::updatePlayButton(QPlayButton &btnGrid){
    if (btnGrid.cellBtn->text()==""){
        btnGrid.cellBtn->setText(QString::number(btnGrid.value));
        btnGrid.counted=true;
    }
}

void PEXESO::reset(vector<QPlayButton> &playButtons){
    player1Score=0;
    player2Score=0;
    turnNumber=1;
    ui->score1->setText("0");
    ui->score2->setText("0");
    ui->turnNumber->setText("1");
    srand(time(NULL));
    for(int q=0; q < boardSize*boardSize; q++)
    {
        a: playButtons.at(q).value = (1+rand()%(boardSize*boardSize)/2);
        int z=0;
        for (int j=0; j<q; j++){
            if (playButtons.at(j).value==playButtons.at(q).value && j!=q){
                z++;
                if(z==2){goto a;}
                }
        }
        playButtons.at(q).btnID=q;
        playButtons.at(q).cellBtn->setText("");
        playButtons.at(q).counted=false;
    }
}

void PEXESO::updateScore(int currentPlayer){
    if (currentPlayer==1){
        player1Score+=2;
        ui->score1->setText(QString::number(player1Score));
    }else{
        player2Score+=2;
        ui->score2->setText(QString::number(player2Score));
    }
}

void PEXESO::updateTurn(){
    if(turnNumber==1){
        turnNumber=2;
    }else{
        turnNumber=1;
    }
    ui->turnNumber->setText(QString::number(turnNumber));
}

void PEXESO::resetPlayButtons(vector<QPlayButton> &playButtons){

    for(int q=0; q < boardSize*boardSize; q++)
    {
        if(playButtons.at(q).counted!=true){
            playButtons.at(q).cellBtn->setText("");
        }
    }
}

void PEXESO::checkResults()
{
    if (player1Score+player2Score==boardSize*boardSize){
        QMessageBox resultBox;
        resultBox.setWindowTitle("Game Results");
        if (player1Score>player2Score){
            resultBox.setText(tr("Game over, Player 1 wins!"));
        } else if (player2Score>player1Score){
            resultBox.setText(tr("Game over, Player 2 wins!"));
        } else{
            resultBox.setText(tr("Game over, Draw!"));
        }
        resultBox.exec();
    }
}







