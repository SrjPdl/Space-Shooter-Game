#include "EN.h"

EN::EN()
{
    this->init();
    spawnTimer=0;
    hp=10;
    speed=250;

}

EN::~EN()
{
    //dtor
}
void EN::init()
{

   enemy[0].loadFromFile("Images/enemies/1.png");
   enemy[1].loadFromFile("Images/enemies/2.png");
   enemy[2].loadFromFile("Images/enemies/3.png");
   enemy[3].loadFromFile("Images/enemies/4.png");
   ENEMY.setTexture(enemy[3]);
   enemies.push_back(ENEMY);
   GetSystemTime(&time);
}
void EN::update(float dt)
{
        spawnTimer++;
    if(spawnTimer>=250)
        {   int j=(time.wSecond*rand()+rand())%4;
            ENEMY.setPosition((time.wMilliseconds*rand())%static_cast<int>(window->getSize().x-enemy[j].getSize().x-186),-10);
            ENEMY.setTexture(enemy[j]);
            enemies.push_back(ENEMY);
            spawnTimer=0;
        }

    for(i=0;i<enemies.size();i++)
    {
        enemies[i].move(0.f,speed*dt);
        if(enemies[i].getPosition().y>window->getSize().y+ENEMY.getGlobalBounds().height)
        {
            enemies.erase(enemies.begin()+i);

        }
      if(player.PLAYER.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
      {
        hp--;
        enemies.erase(enemies.begin()+i);
      }


    }
}
void EN::drawin()
{
    for(int k=0;k<enemies.size();k++)
    window->draw(enemies[k]);
}
void EN::getpl(PL &player)
{  this->player=player;
}
sf::Vector2f EN::getsize()
{
    sf::Vector2f s;
    s.x=enemies[i].getGlobalBounds().left;
    s.y=enemies[i].getGlobalBounds().top;
    return s;
}
void EN::plhpcheck(int &hp)
{
    hp=this->hp;
}
void EN::sethp(int a)
{
    this->hp=a;
}

