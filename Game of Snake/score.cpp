#include "score.h"
#include<QString>
#include<QFont>

score::score()
{
    //draw the text
    setPlainText(QString("SCORE: ") + QString::number(scores));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
    // set the font and color of the score text

}

/*
@brief Increase the score by 10
*/
void score::add()
{
    scores = scores + 10;
    setPlainText(QString("SCORE: ") + QString::number(scores));

}


/*
@brief get the int value of the score
@return scores
*/
int score::get_score()
{
 return scores;
}
