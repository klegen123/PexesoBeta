#ifndef PEXESO_UI_H
#define PEXESO_UI_H

#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>

class PEXESO_UI{
    QVBoxLayout *lVertical;
    QHBoxLayout *lHBoxButtons;
    QHBoxLayout *lHBoxScore;
    QGridLayout *lGrid;

    QPushButton *quitButton;
    QPushButton *restartButton;
    QLabel *lblPlayer1;
    QTextEdit *score1;
    QLabel *lblTurn;
    QTextEdit *turnNumber;
    QLabel *lblPlayer2;
    QTextEdit *score2;
    QFont font;

public:
    void setupUi(QDialog *PEXESO){
        PEXESO->setWindowTitle(QObject::tr("PexesoBeta"));

        lVertical = new QVBoxLayout;
        lHBoxButtons = new QHBoxLayout;
        lHBoxScore = new QHBoxLayout;
        lGrid = new QGridLayout;

        quitButton = new QPushButton(QObject::tr("&Back"));
        restartButton = new QPushButton(QObject::tr("&Restart"));
        lHBoxButtons->addWidget(quitButton);
        lHBoxButtons->addWidget(restartButton);

        font.setPointSize(14);
        lblPlayer1 = new QLabel(QObject::tr("Player1: "));
        score1 = new QTextEdit;
        score1->setMaximumSize(80,40);
        score1->setFont(font);
        score1->setText("0");
        lblTurn = new QLabel(QObject::tr("Turn: "));
        turnNumber = new QTextEdit;
        turnNumber->setMaximumSize(80,40);
        turnNumber->setFont(font);
        turnNumber->setText("1");
        lblPlayer2 = new QLabel(QObject::tr("Player2: "));
        score2 = new QTextEdit;
        score2->setMaximumSize(80,40);
        score2->setFont(font);
        score2->setText("0");
        lHBoxScore->addWidget(lblPlayer1);
        lHBoxScore->setAlignment(lblPlayer1, Qt::AlignRight);
        lHBoxScore->addWidget(score1);
        lHBoxScore->setAlignment(score1, Qt::AlignLeft);
        lHBoxScore->addWidget(lblTurn);
        lHBoxScore->setAlignment(lblTurn, Qt::AlignRight);
        lHBoxScore->addWidget(turnNumber);
        lHBoxScore->setAlignment(turnNumber, Qt::AlignLeft);
        lHBoxScore->addWidget(lblPlayer2);
        lHBoxScore->setAlignment(lblPlayer2, Qt::AlignRight);
        lHBoxScore->addWidget(score2);
        lHBoxScore->setAlignment(score2, Qt::AlignLeft);

        lGrid = new QGridLayout;
        lGrid->setSpacing(0);

        lVertical->addLayout(lHBoxButtons);
        lVertical->addLayout(lHBoxScore);
        lVertical->addLayout(lGrid);

        PEXESO->setLayout(lVertical);
    }
    friend class PEXESO;
};



#endif // PEXESO_UI_H
