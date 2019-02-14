#ifndef STARTGAME_H
#define STARTGAME_H
#include "mainwindow.h"
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QObject>
#include <QSlider>
#include <QLabel>
#include<QPainter>
#include<QBrush>
#include<QGraphicsScene>
#include<QGraphicsview>
#include "snake.h"
#include "food.h"
#include <QMediaPlayer>
#include "startgame.h"


class startgame : QObject
{
    Q_OBJECT

 public:
    startgame(){}

    void startg();

    ~startgame();

 public slots:

   void quitg();

private:
    // declare all the necessary windows and buttons and media and labels that are required in the startg();
    QMediaPlayer * music = new QMediaPlayer();
    QWidget * window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    QLabel* label = new QLabel;
    QPushButton* start = new QPushButton ("START");
    QPushButton* quit = new QPushButton ("QUIT");
    QPushButton* instruction = new QPushButton("INSTRUCTION");
    QWidget* instruction_window = new QWidget();
    QGridLayout* ins_layout = new QGridLayout();
    QLabel* ins1 = new QLabel();
    QLabel* ins2 = new QLabel();
    QLabel* ins3 = new QLabel();
    QLabel* ins4 = new QLabel();
    QLabel* ins5 = new QLabel();
    QLabel* ins6 = new QLabel();
    QLabel* ins7 = new QLabel();
    QLabel* ins8 = new QLabel();
    QPushButton* Back = new QPushButton("Back");
    QGridLayout *settinglayout = new QGridLayout;
    QWidget * winsetting = new QWidget;
    QLabel* label_speed = new QLabel();
    QSlider * speed = new QSlider(Qt::Horizontal);
    QPushButton* setting = new QPushButton ("SETTING");
    snake* game1 = new snake();
};





#endif // STARTGAME_H
