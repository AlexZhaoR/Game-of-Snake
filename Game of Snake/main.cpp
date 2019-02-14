/*
Ruyang Zhao  Xijuan Liu
PiC 10C Final Project
Game of Snake
I pledge that I have neither given nor received unauthorized assistance on this assignment.

All the images and musics are downloaded from free open sources on the following website：

http://www.orangefreesounds.com/ambient-electronic-lounge-music-electro-session/
https://freesound.org/people/aust_paul/sounds/30928/
https://freesound.org/people/Bertrof/sounds/131662/
http://app.shafa.com/apk/quanmintanchishe.html
https://itunes.apple.com/kr/app/snake-off/id1152952778?l=en&mt=8
https://apkgk.com/com.kawaiigame.snake

*/

#include <QApplication>
#include "startgame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    startgame game;
    game.startg();

    return a.exec();
}
