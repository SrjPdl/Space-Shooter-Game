#ifndef SELECTSHIP_H
#define SELECTSHIP_H
#include<character.h>


class Selectship
{
    private:
        sf::RenderWindow *window;
        sf::Text st;
        sf::Font fnt;
        sf::Texture txt[7];
        sf::Texture btn;
        sf::Sprite btns;
        sf::Sprite spr[7];
        int no;
        bool fl;
    public:
        Selectship();
        virtual ~Selectship();
        void init();
        void getwin(sf::RenderWindow *window);
        void render(bool &fl,State &s,int &n);
        void update(int &no,bool &f,State &st);


};

#endif // SELECTSHIP_H
