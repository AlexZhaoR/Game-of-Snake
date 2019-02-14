#include "startgame.h"

void startgame::startg()
{
    // a background music

 music->setMedia(QUrl("qrc:/sound/Electro-session-ambient-electronic-lounge-music.mp3"));
 music->play();




   // a welcome window containing all the buttons to access the game

     window->show();
     window->setFixedSize(600, 500);

     window->setLayout(layout);

     QPixmap bkgnd(":/image/i1.jpng"); // set the background image for the welcoming window
     bkgnd = bkgnd.scaled(window->size(), Qt::IgnoreAspectRatio);
     QPalette palette;
     palette.setBrush(QPalette::Background, bkgnd);
     window->setPalette(palette);


          label->setText("Game of Snake");
          // add a QLabel, the name of the game, on the top of the welcoming window

          // set the size and color of the words
          QFont font_label("times", 40);
          QFontMetrics fontmetrics_label(font_label);
          label->setFont(font_label);
          int pixelswide = fontmetrics_label.width(label->text());
          int pixelshigh = fontmetrics_label.height();
          label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
          label->setAlignment(Qt::AlignCenter);
          label->setFixedWidth(pixelswide);
          label->setFixedHeight(pixelshigh);
          QPalette palette2;
          palette2.setColor(QPalette::WindowText, Qt::green);

          label->setPalette(palette2);

          //add quit and start buttons to the welcome screen



     QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quitg()));
     // connect the quit button to quit()




         instruction_window->setFixedSize(800, 500);
         QObject::connect(instruction, SIGNAL(clicked()), window, SLOT(hide()));
         QObject::connect(instruction, SIGNAL(clicked()), instruction_window, SLOT(show()));

         // set the instructions in the instruction window
         instruction_window->setLayout(ins_layout);

         ins1->setText("Instructions");

         ins2->setText("1. Click on Start to start the game.");

         ins3->setText("2. Click on the Setting button to go to the speed page. Drag the slider to adjust the speed.");

         ins4->setText("3. Once the game starts, use the direction key to control the moving direction of the snake.");

         ins5->setText("4. Try to eat as many apples as you can to get higher scores and avoid biting yourself.");

         ins6->setText("5. Each time the snake eats an apple, the score will be increased by 10.");

         ins7->setText("6. If your score reaches 500, you win the game. If the snake bites itself, you lose the game.");

         ins8->setText("7. On the game over window, click on play again to start another round. Click on quit to quit the game");

         QObject::connect(Back, SIGNAL(clicked()), instruction_window, SLOT(hide()));
         QObject::connect(Back, SIGNAL(clicked()), window, SLOT(show()));


         ins_layout->addWidget(ins1);
         ins_layout->addWidget(ins2);
         ins_layout->addWidget(ins3);
         ins_layout->addWidget(ins4);
         ins_layout->addWidget(ins5);
         ins_layout->addWidget(ins6);
         ins_layout->addWidget(ins7);
         ins_layout->addWidget(ins8);
         ins_layout->addWidget(Back);



     /*Create a widget to contain elements in setting window*/

      winsetting->setFixedSize(600, 500);

      winsetting->setLayout(settinglayout);

     // set background image for the setting window
      QPixmap bkgnd1(":/image/i2.jpng");
      bkgnd1 = bkgnd1.scaled(winsetting->size(), Qt::IgnoreAspectRatio);
      QPalette palette1;
      palette1.setBrush(QPalette::Background, bkgnd1);
      winsetting->setPalette(palette1);

           label_speed->setText("Drag to the right to increase speed");
           QFont font_label1("times", 30);
           QFontMetrics fontmetrics_label1(font_label1);
           label_speed->setFont(font_label1);
           int pixelswide1 = fontmetrics_label1.width(label_speed->text());
           int pixelshigh1 = fontmetrics_label1.height();
           label_speed->setFrameStyle(QFrame::Panel|QFrame::Sunken);
           label_speed->setAlignment(Qt::AlignCenter);
           label_speed->setFixedWidth(pixelswide1);
           label_speed->setFixedHeight(pixelshigh1);
           QPalette palette3;
           palette3.setColor(QPalette::WindowText, Qt::black);
           label_speed->setPalette(palette3);

     // slider to adjust the speed of the snake

      speed->setRange(0,100); // set the range of the speed

      QPushButton* Return = new QPushButton ("RETURN");
      // a return button to return to the main menu

      settinglayout->addWidget(label_speed);
      settinglayout->addWidget(speed);
      settinglayout->addWidget(Return);

      /*return to the main menu when the user clicks the Return button*/
      QObject::connect(Return, SIGNAL(clicked()), winsetting, SLOT(hide()));
      QObject::connect(Return, SIGNAL(clicked()), window, SLOT(show()));

    /*go to the setting window when the user clicks the setting button*/
     QObject::connect(setting,SIGNAL(clicked()), window, SLOT(hide()));
     QObject::connect(setting,SIGNAL(clicked()), winsetting,SLOT(show()));

        // add all the widget to the window
         layout->addWidget(label);
         layout->addWidget(start);
         layout->addWidget(setting);
         layout->addWidget(instruction);
         layout->addWidget(quit);

         //hide the setting window initially
         winsetting->hide();

        QObject::connect(speed, SIGNAL(valueChanged(int)), game1, SLOT(set_speed(int)));
        //connect the value change of the slider with the speed of the snake

        game1->get_view()->hide();
        //hide the view of the game initially

        //click the start button to hide the welcome window and start the game
      QObject::connect(start, SIGNAL(clicked()), window, SLOT(hide()));
      QObject::connect(start, SIGNAL(clicked()), game1->get_view(), SLOT(show()));

}

//destructor to delete all the pointers declared inside the class
startgame::~startgame()
{
    delete music;
    delete layout;
    delete label;
    delete start;
    delete quit;
    delete instruction;
    delete setting;
    delete ins_layout;
    delete ins1;
    delete ins2;
    delete ins3;
    delete ins4;
    delete ins5;
    delete ins6;
    delete ins7;
    delete ins8;
    delete Back;
    delete settinglayout;
    delete label_speed;
    delete speed;
    delete winsetting;
    delete instruction_window;
    delete window;

}

//@brief quit the application
void startgame::quitg()
{
    QApplication::quit();
}
