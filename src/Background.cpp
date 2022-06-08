#include "Background.h"

Background::Background()
{
    bg.loadFromFile("Images/Bg/bgt.png");
    bgs.setTexture(bg);
}

Background::~Background()
{
    //dtor
}
void Background::getwin(sf::RenderWindow *window)
{
  this->window=window;
}
void Background::draw()
{
        window->draw(bgs);

}
void Background::setsize(float x,float y)
{
    bgs.setScale(sf::Vector2f(x,y));
}
