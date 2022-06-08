#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "EN.h"
#include<Mainmenu.h>

class Gameover
{
    private:
        sf::RenderWindow *window;
        sf::Font font;
        sf::Text title;
        sf::Text exit;
        sf::Texture bg;
        sf::Sprite bgs;
        sf::Text scrdisp;
        int s;
        bool getscore;
        sf::Sprite button[2];
        sf::Texture buttont;
        std::stringstream ss;
    public:
        Gameover();
        ~Gameover();
        void init();
         void getwin(sf::RenderWindow *window);
         void draw(EN &e,int &winfl,State &state,int s);
         void setc(EN &e,int &winfl,State &state);
         void score();

};

#endif // GAMEOVER_H
