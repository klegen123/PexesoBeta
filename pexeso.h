#ifndef PEXESO_H
#define PEXESO_H

#include "pexeso_ui.h"

#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <vector>

class QPushButton;
class QPlayButton;

using std::vector;


class PEXESO : public QDialog
{
    Q_OBJECT
    int player1Score, player2Score, turnNumber;
    PEXESO_UI *ui;
    int boardSize;
    void setConnections();
public:
    PEXESO(const int &boardSize, QWidget *parent = nullptr);
    vector<QPlayButton> buildPlayButtons();
    void updatePlayButton(QPlayButton &btnGrid);
    void resetPlayButtons(vector<QPlayButton> &playButtons);
    void updateScore(int currentPlayer);
    void updateTurn();
    void reset(vector<QPlayButton> &playButtons);
    void checkResults();
signals:
    void newGame();
};



class QPlayButton
{
public:
    QPushButton *cellBtn = nullptr;
    int value;
    int btnID=-1;
    int row = -1;
    int col = -1;
    bool counted=false;
    QPlayButton(QPushButton *cellBtn, int row, int col)
        : cellBtn(cellBtn), row(row), col(col) {}
};


#endif // PEXESO_H
