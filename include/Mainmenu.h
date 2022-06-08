#ifndef MAINMENU_H
#define MAINMENU_H
#define btn_no 4
#include<Character.h>
enum substate{none,help1,about1};
class Mainmenu
{
     private:
        sf::RenderWindow *window;
        sf::Font font;
        sf::Texture txtr[2];
        sf::Sprite bg;
        sf::Sprite buttons[btn_no];
        sf::Text text[btn_no];
        sf::Text bck;
        std::ifstream in;
        std::stringstream cnt;
        char c;
        int cont;
        sf::Text area;
        bool getdata;
        substate sbst;
        sf::Sprite Back;
     public:
        Mainmenu();
        ~Mainmenu();
        void init();
        void getwin(sf::RenderWindow *window);
        void draw(State &state,int &winfl);
        void click(State &state ,int &winfl);
        void help();
        void about();
        sf::Font& rtnfnt();

};

#endif // MAINMENU_H
