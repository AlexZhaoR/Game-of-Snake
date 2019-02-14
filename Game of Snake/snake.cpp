#include "snake.h"
#include<QKeyEvent>
#include<QTimer>
#include<QObject>
#include<QList>
#include "food.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QDebug>
#include<QPainter>
#include<QPushButton>
#include<QObject>
#include<QApplication>
#include "creasnake.h"
#include<QLabel>

snake::snake()
{
    die->setMedia(QUrl("qrc:/sound/die.wav"));
    eat->setMedia(QUrl("qrc:/sound/eff.wav")); //set the music

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    view->setBackgroundBrush(brush); // set the color of the background

    playground->setSceneRect(0, 0, 550, 550);  // set the size of the scene
    view->setFixedSize(550, 550); // set the size for the view
    playground->addItem(this);  // add snake to the scene
    food* f = new food();
    playground->addItem(f);// add food to the scene

    playground->addItem(scores); // add scores to the scene

    scores->setPos( 20, 20);
    // set the location of the score being displayed during the game


    /**********/


    QBrush brush2;
    brush2.setStyle(Qt::SolidPattern);
    brush2.setColor(Qt::red);
    setBrush(brush2);  // set color of the snake head


    setRect(275,275,20,20); // set location and size of the snake head
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();  // make the snake head focused



    sbody* body1 = new sbody();

    bodies.prepend(body1);

    scene()->addItem(body1); // add a sbody to the scene

    QBrush brush3;
    brush3.setStyle(Qt::SolidPattern);
    brush3.setColor(Qt::yellow);
    body1->setBrush(brush3);  // set the color for the sbody



    setPos(x(), y()+21); //avoid the collision between head and body at initial position



    headPos = pos();
}

/*
match the four direction keys to four movement functions
*/
void snake::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left&!movingright&!movingleft) //avoid the snake going directly to an opposite position
        moveleft();

    else if(event->key() == Qt::Key_Right&!movingleft&!movingright)
        moveright();

    else if (event->key() == Qt::Key_Up&!movingdown&!movingup)
        moveup();

    else if (event->key() == Qt::Key_Down&!movingup&!movingdown)
        movedown();
}

void snake::moveup()
{


    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(down()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(left()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(right()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(up()));
// disconnect the timer with all movements

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(up()));
// connect the timer with upward movement

    timer->start(speed); // start the timer

    movingup = true;  // make movingup true
        movingdown = false;
    movingleft = false;
        movingright =false;

}

/*reference the moveup() function, everything is defined in a similar fashion*/
void snake::movedown()
{
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(up()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(down()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(left()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(right()));

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(down()));

    timer->start(speed);
    movingup = false;
        movingdown = true;
    movingleft = false;
        movingright =false;
}

/*reference the moveup() function, everything is defined in a similar fashion*/
void snake::moveleft()
{


    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(down()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(up()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(right()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(left()));

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(left()));

    timer->start(speed);
    movingup = false;
        movingdown = false;
    movingleft = true;
        movingright =false;
    }

/*reference the moveup() function, everything is defined in a similar fashion*/
void snake::moveright()
{
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(down()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(left()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(up()));
    QObject::disconnect(timer, SIGNAL(timeout()),this,SLOT(right()));

    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(right()));

    timer->start(speed);

    movingup = false;
    movingdown = false;
    movingleft = false;
    movingright = true;
}


/*
@brief enlarge the snake body by one unit
*/
void snake::enlarge()
{
    check_win(); // check wheter the player wins the game
    sbody* body = new sbody();
    bodies.prepend(body);  // prepend the sbody to the beginning of the list
    scene()->addItem(body); // add body to the scene
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    body->setBrush(brush);  //fill the  body with yellow

}

/*a function called when the game is over*/
void snake::gameover()
{
    timer->stop();  // stop the timer so the snake stop moving

    QString filename = ":/image/i3.jpng";
    QImage image(filename);
    QGraphicsPixmapItem* item_graph = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item_graph->setPos(-40, 120);
    reportwindow->addItem(item_graph);

    die->play();  // play the sound effect for dying

    QPushButton* again = new QPushButton("PLAY AGAIN");
    QPushButton* quitgame = new QPushButton("QUIT");

    again->setGeometry(0,0,120, 40);
    quitgame->setGeometry(0,50, 120, 40);  //set the location of the two buttons

   QGraphicsProxyWidget* proxy1 = reportwindow->addWidget(again);
   QGraphicsProxyWidget* proxy2 = reportwindow->addWidget(quitgame);
   // add two buttons to the scene when game is over

QObject::connect(quitgame, SIGNAL(clicked()), this, SLOT(quitgame()));
// connect quit button with quitgame slots

QObject::connect(again, SIGNAL(clicked()), this, SLOT(restart()));
       reportwindow->addItem(scores);  // add scores to the gameover scene
     scores->setPos(20,-50); //set the position of the scores

view->setScene(reportwindow); // make the gameover scene visible


}

/* handle the collision of items*/
void snake::handlecollision()
{
    QList <QGraphicsItem*>  collided = collidingItems();
    // make a list of items that collides with the snake

    for(int i=0; i<collided.size();i++)
    {
        if(typeid(*collided[i]) == typeid(food)) // the food is collided with
         {
            eat->play(); // play the sound for eating
            scene()->removeItem(collided[i]); // remove the food from scene
            delete collided[i]; // delete the food

            scores->add(); // update the scores

            enlarge();
            enlarge();
            enlarge(); // enlarge the snake body by 3 units

            creafood(); // create a new food on the scene


            return;}

    if(typeid(*collided[i]) == typeid(sbody)) // if the sbody is collided with

          { qDebug() << "gameover";
           gameover(); // call the gameover function
          }
    }
}


/*@Check whether the player wins the game*/
void snake::check_win()
{
    if(scores->get_score()>=500) // if the socre reaches 500, call gameover()
    {
        gameover();
        QGraphicsTextItem* win = new QGraphicsTextItem();
        win -> setPlainText(QString("Congratulations! You Won!"));
        win -> setDefaultTextColor(Qt::yellow);
        win-> setFont(QFont("times", 20));
        win->setPos(-45 , -100);
        reportwindow->addItem(win);  // display winning scene
    }

}

/*@brief
 @return the scores of the snake*/
score *snake::get_scores()
{
    return scores;
}

/* a slot that can set the speed of the snake*/
void snake::set_speed(int n)
{
    speed = 100 - n;
    /*larger n means smaller speed, the speed is the Qtimer time so the snake
     will move faster*/
}

/*@brief start a new game*/
void snake::restart()
{
   get_view()->hide(); // hide the view
   creaSnake(speed); // create a new snake class
}

/*quit the application*/
void snake::quitgame()
{
    QApplication::quit();
}

/*@return view of the snake*/
QGraphicsView* snake::get_view()
{
    return view;
}

/*set speed for the snake*/
void snake::set_sp(int sp)
{
    speed = sp;
}


snake::~snake()  // destructor
{
    delete timer;
    delete scores;
    delete playground;
    delete reportwindow;
    delete view;
    delete eat;
    delete die;
    for(int i = 0; i < bodies.size(); i++)
    {
        delete bodies[i];
    }
    // delete all the pointers created in the class
}


/*@brief slots that make the snake move*/
void snake::up()
{
    handlecollision();
    //check collision everytime before the position of the snake is changed

    if(y()<-275)    //check boundary
    {
        setPos(x(), y() + 570);
        // if it is out of boundary, move to the other side of the boundary
    }

    setPos(x(), y()-21);    // update the position of the snake head

    for(int i =0;i<bodies.size()-1;i++) // update the posisiton of the snake bodies
    {
        bodies[i]->setPos(bodies[i+1]->pos());
     // every part of the bodies goes to the position of the sbody in front of it
    }

    bodies.last()->setPos(headPos);
    // the sbody directy following the snake head goes to the positon of the snake head

    headPos = pos();

}

/*reference up() for comments, all move slots are defined in the same fashion*/
void snake::down()
{

    handlecollision();
    if(y()>275)
    {
        setPos(x(), y() - 570);
    }
    setPos(x(), y()+21);
    for(int i =0;i<bodies.size()-1;i++)
    {
        bodies[i]->setPos(bodies[i+1]->pos());


    }
    bodies.last()->setPos(headPos);

    headPos = pos();

}

/*reference up() for comments, all move slots are defined in the same fashion*/
void snake::left()
{
    handlecollision();
    if(x()<-275)
    {
        setPos(x()+570, y());
    }
    setPos(x()-21, y());
    for(int i =0;i<bodies.size()-1;i++)
    {
        bodies[i]->setPos(bodies[i+1]->pos());


    }
    bodies.last()->setPos(headPos);

    headPos = pos();

}

/*reference up() for comments, all move slots are defined in the same fashion*/
void snake::right()
{
    handlecollision();
    if(x()> 275)
    {
        setPos(x()-570, y());
    }

    setPos(x()+21, y());
    for(int i =0;i<bodies.size()-1;i++)
    {
        bodies[i]->setPos(bodies[i+1]->pos());
    }
    bodies.last()->setPos(headPos);

    headPos = pos();

}

/*function to create a food and add it to the scene*/
void snake::creafood()
{
    food* newfood = new food();

    scene()->addItem(newfood);

    newfood->check();


}
