#ifndef BULLET_H
#define BULLET_H

#include <Character.h>
#include<PL.h>
#include<EN.h>


class Bullet : public Character
{
    private:
        sf::Texture bult;
        sf::Sprite bullet;
        sf::Vector2f pos;
        sf::SoundBuffer s_bull;
        sf::Sound sd_bull;
        sf::SoundBuffer s_end;
        sf::Sound sd_end;
        PL player;
        EN *enemy;
        int *score;
        int *bull;
        int bulletimer;
        const int speed;
        int i,l;
        std::vector<sf::Sprite> bullets;
    public:
        Bullet();
        ~Bullet();
        void init();
        void getpl(PL &player);
        void geten(EN *enemy);
        void drawin();
        void update(float dt);
        void scor(int *score,int *bull);

};

#endif // BULLET_H
