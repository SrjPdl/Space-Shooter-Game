#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<Character.h>

class Background
{
     private:
         sf::Texture bg;
         sf::Sprite bgs;
         sf::RenderWindow *window;

    public:
        Background();
        ~Background();
        void getwin(sf::RenderWindow *window);
        void draw();
        void setsize(float x,float y);


};

#endif // BACKGROUND_H
