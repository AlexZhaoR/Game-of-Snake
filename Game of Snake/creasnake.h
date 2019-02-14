#ifndef CREASNAKE_H
#define CREASNAKE_H
#include "snake.h"


/*
A function to create a new snake pointer
@para int speed set the speed of the snake
*/
void creaSnake(int speed)
{
    snake* news = new snake();
    news->set_sp(speed);
    news->get_view()->show();  //show the view so a new game will be displayed
//    news->speed = s->speed;
}


#endif // CREASNAKE_H
