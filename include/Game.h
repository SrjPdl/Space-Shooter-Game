#ifndef GAME_H
#define GAME_H
#include "PL.h"
#include "EN.h"
#include "Bullet.h"
#include "Background.h"
#include "Healthbar.h"
#include "Gameover.h"
#include "Mainmenu.h"
#include "Selectship.h"
#include "Pickup.h"
class Game
{
    private:
        sf::RenderWindow window;
        sf::Event winEvnt;
        sf::Clock dtClock;
        sf::Text score;
        sf::Text b_no;
        float dt;
        int s;
        int b;
        int scn;
        bool deletecontroller;
        Mainmenu *mm;
        PL player;
        EN enemy;
        Pickup pickup;
        Selectship *ship;
        Background bg;
        Bullet bullet;
        Healthbar hb;
        Gameover g;
        State state;
        int hp,fl;
        bool scf;
        unsigned p;
        int winfl;
        void initWin();
    public:
        Game();
        virtual ~Game();


        void updateDt();
        void updateWindowEvent();
        void update();
        void rdr();
        void run();
        void status();

};

#endif // GAME_H
