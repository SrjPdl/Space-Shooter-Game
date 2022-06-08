#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
    //dtor
}
void Character::getwin(sf::RenderWindow *window)
{
    this->window=window;
}
