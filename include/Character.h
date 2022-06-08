#ifndef CHARACTER_H
#define CHARACTER_H
#define WIDTH 1000
#define HEIGHT 700
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

enum State {Menu,SPACESHIP,PLAY,EXIT};
class Character
{
    private:

    protected:
        sf::RenderWindow *window;
    public:
        Character();
        virtual ~Character();
        virtual void init()=0;
        virtual void drawin()=0;
        virtual void update(float dt)=0;
        void getwin(sf::RenderWindow *window);

};

#endif // CHARACTER_H
