#include "food.h"
#include <QGraphicsItem>
#include<stdlib.h> // rand() generates a really large int
#include "sbody.h"

food::food()
{
    randomx = rand()%550;
    randomy = rand()%550;  // generate two random coordinates for the good

    setPixmap(QPixmap(":/image/apple.png")); // a image for the food

    setPos(randomx, randomy);

    setScale(0.015);  // make it a proper size
}


/*
@brief Check if the food collides with sbody, if so generate a new one
*/
void food::check()
{



    QList <QGraphicsItem*>  collided = collidingItems();

    while (collided.size() != 0||(randomx>255&&randomx<295)&&(randomy>255&&randomy<295))//loop until the food doesn't collide with anything
    {
        randomx = rand()%550;
        randomy = rand()%550;

        setPos(randomx, randomy);

        collided = collidingItems();
    }


}

