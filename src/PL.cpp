#include "PL.h"

PL::PL()
{
    scf=true;
    speed=500;
}

PL::~PL()
{
    //dtor
}
void PL::init()
{
    this->PLAYER.setTexture(player);
    this->PLAYER.setPosition(sf::Vector2f(WIDTH/2-PLAYER.getGlobalBounds().width/2,HEIGHT-PLAYER.getGlobalBounds().height));
}
void PL::update(float dt)
{
     /*if(sf::Mouse::getPosition(*window).x>0 && sf::Mouse::getPosition(*window).x<window->getSize().x-player.getSize().x-160)
        {
            PLAYER.setPosition(sf::Vector2f(sf::Mouse::getPosition(*window).x,PLAYER.getPosition().y));

        }*/
          if(PLAYER.getPosition().x<0)
          {
              PLAYER.setPosition(sf::Vector2f(0,PLAYER.getPosition().y));
          }
          if(PLAYER.getPosition().x>WIDTH-player.getSize().x-186)
            PLAYER.setPosition(sf::Vector2f(WIDTH-player.getSize().x-186,PLAYER.getPosition().y));
        if(PLAYER.getPosition().x>=0 && PLAYER.getPosition().x<=WIDTH-player.getSize().x-186)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                PLAYER.move(-speed*dt,0);
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                PLAYER.move(speed*dt,0);
        }


}
void PL::drawin()
{
    window->draw(PLAYER);
}
sf::Vector2f PL::getposition()
{
    return PLAYER.getPosition();
}
sf::Vector2u PL::getsize()
{
    return player.getSize();
}
void PL::shipselection(int spn)
{
     if(scf)
        {
        switch(spn)
        {
        case 0:
            this->player.loadFromFile("Images/players/1.png");
            scf=false;
            init();
            break;
        case 1:
            this->player.loadFromFile("Images/players/2.png");
            scf=false;
            init();
            break;
        case 2:
            this->player.loadFromFile("Images/players/3.png");
            scf=false;
            init();
            break;
        case 3:
            this->player.loadFromFile("Images/players/4.png");
            scf=false;
            init();
            break;
        }
        }
}


