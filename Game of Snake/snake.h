#ifndef SNAKE_H
#define SNAKE_H
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QKeyEvent>
#include<QObject>
#include<QTimer>
#include<QList>
#include "score.h"
#include "sbody.h"
#include<QPointF>
#include"mainwindow.h"
#include<QPushButton>
#include<QMediaPlayer>


/*
A snake class that functions like a singe game
*/
class snake : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    snake();

    void moveup();
    void movedown();
    void moveleft();
    void moveright();
    void enlarge();
    void gameover();
    void handlecollision();
    void check_win();

    score* get_scores();
    QGraphicsView* get_view();
    void set_sp(int sp);
    ~snake();

protected:
    void keyPressEvent(QKeyEvent* event);

public slots:
    void up();
    void down();
    void left();
    void right();
    void creafood();
    void set_speed(int n);
    void restart();
    void quitgame();


private:

    QTimer* timer = new QTimer();
    score* scores = new score();

    bool movingup = false;
    bool movingdown = false;
    bool movingleft = false;
    bool movingright =false;  // keep track of the direction of the snake motion

    QList<QGraphicsRectItem*> bodies;

    QPointF headPos;

    int speed = 100;
    QGraphicsScene *playground = new QGraphicsScene();
    // scene for the game playing

    QGraphicsScene* reportwindow = new QGraphicsScene();
    // scene for the window after the game is over

    QGraphicsView *view = new QGraphicsView(playground);
    //view for the game playing

    QMediaPlayer* eat = new QMediaPlayer();
    QMediaPlayer* die = new QMediaPlayer();
    // sound effecet for eating and dying of the snake

};

#endif // SNAKE_H
