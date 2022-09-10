#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include "titlescreen_ui.h"

class TitleScreen : public QMainWindow
{
    Q_OBJECT
    TitleScreenUI *ui;
    int boardSize;
    void setConnections();
    void closeEvent(QCloseEvent *event);

public:
    TitleScreen(QWidget *parent = nullptr);

public slots:
    void updateEasyGame(bool checked);
    void updateNormalGame(bool checked);
    void updateHardGame(bool checked);
    void startGame();

signals:
    void exited();
};

#endif // TITLESCREEN_H
