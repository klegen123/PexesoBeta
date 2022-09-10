#ifndef TITLESCREEN_UI_H
#define TITLESCREEN_UI_H

#include <QMainWindow>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>
#include <QFileDialog>

class TitleScreenUI{
    QWidget *centralWidget;
    QLabel *lblchooseDifficulty;
    QLabel *logo;
    QVBoxLayout *lchooseDifficulty;
    QRadioButton *easyButton;
    QRadioButton *normalButton;
    QRadioButton *hardButton;
    QPushButton *startButton;
    QFont font;

public:
    void setupUi(QMainWindow *TitleScreen){
        font.setPointSize(16);
        lchooseDifficulty = new QVBoxLayout;
        lblchooseDifficulty = new QLabel(QObject::tr("Welcome to PEXESO\n for mathematicians! \n\n   Choose difficulty:"));
        lblchooseDifficulty->setFont(font);

        QPixmap imagePixmap("://logo//logo.png");
        logo=new QLabel;
        logo->setPixmap(imagePixmap);
        font.setPointSize(12);
        easyButton = new QRadioButton(QObject::tr("Easy"));
        easyButton->setFont(font);
        normalButton = new QRadioButton(QObject::tr("Normal"));
        normalButton->setFont(font);
        hardButton = new QRadioButton(QObject::tr("Hard"));
        hardButton->setFont(font);
        startButton = new QPushButton(QObject::tr("Start game"));
        centralWidget = new QWidget;

        //TitleScreen->resize(400, 300);
        TitleScreen->setWindowTitle(QObject::tr("PexesoBeta"));

        lchooseDifficulty->addWidget(logo);
        lchooseDifficulty->addWidget(lblchooseDifficulty);
        lchooseDifficulty->setAlignment(lblchooseDifficulty, Qt::AlignCenter);
        lchooseDifficulty->addWidget(easyButton);
        lchooseDifficulty->addWidget(normalButton);
        lchooseDifficulty->addWidget(hardButton);
        lchooseDifficulty->addWidget(startButton);

        centralWidget->setLayout(lchooseDifficulty);
        TitleScreen->setCentralWidget(centralWidget);
    }
    friend class TitleScreen;
};

#endif // TITLESCREEN_UI_H
