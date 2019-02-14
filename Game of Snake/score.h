#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>


/*
A score class that inherits from QGraohicsTextItem
It keeps track of the scores of the current game and can be added to the scene
*/
class score : public QGraphicsTextItem
{
public:
    score();
    void add();
    int get_score();

private:
    int scores = 0;

};


#endif // SCORE_H

