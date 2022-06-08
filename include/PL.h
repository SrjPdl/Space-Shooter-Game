#ifndef PL_H
#define PL_H

#include <Character.h>

class Pickup;
class PL : public Character
{
private:
        float speed;
        sf::Sprite spr;
        sf::Texture player;
        sf::Sprite PLAYER;
        bool scf;

    public:

        PL();
        ~PL();
        void init();
        sf::Vector2f getposition();
        sf::Vector2u getsize();
        void drawin();
        void update(float dt);
        friend class EN;
        friend Pickup;
        void shipselection(int spn);

};

#endif // PL_H
