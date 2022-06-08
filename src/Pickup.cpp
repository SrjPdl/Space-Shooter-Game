#include "Pickup.h"

Pickup::Pickup():speed(150)
{
   init();
   btimer=0;
   htimer=0;
}
Pickup::~Pickup(){}
void Pickup::init()
{
    bpt.loadFromFile("Images/bulletp.png");
    bps.setTexture(bpt);
    hpt.loadFromFile("Images/hp.png");
    hps.setTexture(hpt);
    GetSystemTime(&time);
    s_p.loadFromFile("Sound/pickup.wav");
    sd_p.setBuffer(s_p);
    bpc=true;
    hpc=true;
    hppc=true;
    bppc=true;
}
void Pickup::update(float dt)
{
      if(bpc)
    {
        btimer++;
        if(!bppc)
        bppc=true;

    }
    if(btimer==10000)
    {   if(bppc)
        {
            bps.setPosition((time.wMilliseconds*rand())%static_cast<int>(window->getSize().x-bpt.getSize().x-186),-10);
            bppc=false;
        }
        bps.move(0.f,speed*dt);
        bpc=false;
        if(bps.getPosition().y>HEIGHT+bpt.getSize().y)
        {
            bpc=true;
            btimer=0;
        }
    }

    if(hpc)
    {
        htimer++;
        if(!hppc)
        hppc=true;

    }
    if(htimer==20000)
    {
         if(hppc)
        {
            hps.setPosition((time.wMilliseconds*rand())%static_cast<int>(window->getSize().x-bpt.getSize().x-186),-10);
            hppc=false;
        }
        hps.move(0.f,speed*dt);
        hpc=false;
        if(hps.getPosition().y>HEIGHT+hpt.getSize().y)
        {
            hpc=true;
            htimer=0;
        }
    }
}
void Pickup::drawin()
{   if(btimer==10000)
    window->draw(bps);
    if(htimer==20000)
    window->draw(hps);
}
void Pickup::getplayer(PL *pl)
{
    this->pl=pl;
}
void Pickup::check(int *nob,int *hp)
{
    if(pl->PLAYER.getGlobalBounds().intersects(bps.getGlobalBounds()))
    {
    (*nob)+=100;
    bps.setPosition((time.wMilliseconds*rand())%static_cast<int>(window->getSize().x-bpt.getSize().x-186),-10);
    sd_p.play();
    btimer=0;
    bpc=true;
    }
    if(pl->PLAYER.getGlobalBounds().intersects(hps.getGlobalBounds()))
    {
    (*hp)=10;
    hps.setPosition((time.wMilliseconds*rand())%static_cast<int>(window->getSize().x-bpt.getSize().x-186),-10);
    sd_p.play();
    htimer=0;
    hpc=true;
    }
}
