#ifndef PEXESO_CONTROLLER_H
#define PEXESO_CONTROLLER_H

#include <QObject>
#include <vector>
#include "pexeso.h"

using std::vector;

class PEXESO_Controller : public QObject
{
    Q_OBJECT
    PEXESO p;
    vector<QPlayButton> playButtons;
    int boardSize;
    int currentPlayer;
    int clickNumber, clickedBtn1, clickedBtn2;
    void setConnections();
    void reset();
    void switchPlayer();
    void checkTurnPoints();
public:
    PEXESO_Controller(int &boardSize, QObject *parent = nullptr);
    void startGame();
public slots:
    void updateGame(QPlayButton &playButton);
};

#endif // PEXESO_CONTROLLER_H
