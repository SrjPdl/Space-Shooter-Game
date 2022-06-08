#include "Bullet.h"

Bullet::Bullet():speed(500)
{
    init();
    i=0;
    bulletimer=0;
}

Bullet::~Bullet()
{
    //dtor
}
void Bullet::init()
{
    bult.loadFromFile("Images/bullet.png");
    bullet.setTexture(bult);
    bullets.push_back(bullet);
    s_bull.loadFromFile("Sound/bullet.wav");
    sd_bull.setBuffer(s_bull);
    s_end.loadFromFile("Sound/enemy.wav");
    sd_end.setBuffer(s_end);
}
void Bullet::update(float dt)
{   bulletimer++;
    pos.x=player.getposition().x+player.getsize().x/2-3;
    pos.y=player.getposition().y;
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletimer>80 && *bull!=0)
            {   bullet.setPosition(pos);
                bullets.push_back(bullet);
                bulletimer=0;
                sd_bull.setVolume(50.f);
                sd_bull.play();
                (*bull)--;
            }
    for(int i=0;i<bullets.size();i++)
    {
        bullets[i].move(0.f,-speed*dt);
        if(bullets[i].getPosition().y<0)
        {
            bullets.erase(bullets.begin()+i);

        }

   }
   for(int k=0;k<bullets.size();k++)
   {
       for(int l=0;l<enemy->enemies.size();l++)
       {
           if(bullets[k].getGlobalBounds().intersects(enemy->enemies[l].getGlobalBounds()))
           {

            i++;
            bullets.erase(bullets.begin()+k);
           }
            if(i==5)
            {
                enemy->enemies.erase(enemy->enemies.begin()+l);
                i=0;
                sd_end.play();
                (*score)++;
            }

   }



}
}
void Bullet::getpl(PL &player)
{  this->player=player;
}
void Bullet::geten(EN *enemy)
{
    this->enemy=enemy;
}
void Bullet::drawin()
{
    for(int k=0;k<bullets.size();k++)
        window->draw(bullets[k]);

}
void Bullet::scor(int *score,int *bull)
{
    this->score=score;
    this->bull=bull;
}

