#include "Healthbar.h"

Healthbar::Healthbar()
{

}

Healthbar::~Healthbar()
{
}
void Healthbar::drawhp(int hp)
{
    hb.setFillColor(sf::Color::Green);
    hb.setOutlineColor(sf::Color(124,64,231));
    hb.setOutlineThickness(2);
    hb.setSize(sf::Vector2f(hp*15.5f,10.f));
     hb.setPosition(WIDTH-170.f,325.f);
    window->draw(hb);
}
void Healthbar::init()
{
    hb.setFillColor(sf::Color::Green);
    hb.setPosition(WIDTH-20,0.f);
}
void Healthbar::drawin(){}
void Healthbar::update(float dt){}
