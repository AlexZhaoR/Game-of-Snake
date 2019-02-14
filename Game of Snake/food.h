#ifndef FOOD_H
#define FOOD_H
#include<QGraphicsPixmapItem>
#include<QObject>


/*
A food class that can be eaten by the snake in the game
*/
class food: public QObject, public QGraphicsPixmapItem // inherit from QGraphicsPixmapItem
{
    Q_OBJECT
public:
    food();
    void check();

private:
    double randomx = -100;
    double randomy = -100;   //the coordinates of the food


};

#endif // FOOD_H
