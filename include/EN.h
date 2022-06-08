#ifndef EN_H
#define EN_H

#include <Character.h>
#include<PL.h>


class EN : public Character
{
    private:
         float speed;
         int i,hp;
         sf::Texture enemy[4];
         sf::Sprite ENEMY;
         PL player;
         SYSTEMTIME time;
         int spawnTimer;
         std::vector<sf::Sprite> enemies;
    public:
        EN();
        ~EN();



        void init();
        void getpl(PL &player);
        sf::Vector2f getsize();
        void drawin();
        void update(float dt);
        void plhpcheck(int &hp);
        void sethp(int a);
        friend class Bullet;

};

#endif // EN_H
