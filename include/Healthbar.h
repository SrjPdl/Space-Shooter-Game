#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <Character.h>


class Healthbar : public Character
{
    private:
        sf::RectangleShape hb;
    public:
        Healthbar();
        ~Healthbar();
         void init();
         void drawin();
         void update(float dt);
         void drawhp(int hp);


};

#endif // HEALTHBAR_H
