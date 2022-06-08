#include "Selectship.h"

Selectship::Selectship()
{
    init();
    no=0;
    fl=true;
}

Selectship::~Selectship()
{
    //dtor
}
void Selectship::getwin(sf::RenderWindow *window)
{
    this->window=window;
}
void Selectship::init()
{
    txt[0].loadFromFile("Images/players/show/1.png");
    txt[1].loadFromFile("Images/players/show/2.png");
    txt[2].loadFromFile("Images/players/show/3.png");
    txt[3].loadFromFile("Images/players/show/4.png");
    txt[4].loadFromFile("Images/players/show/bg.jpg");
    txt[5].loadFromFile("Images/buttons/sb_r.png");
    txt[6].loadFromFile("Images/buttons/sb_l.png");
    btn.loadFromFile("Images/buttons/select.png");
    fnt.loadFromFile("Font/font.ttf");
    st.setFont(fnt);
    st.setString("SELECT");
    btns.setTexture(btn);
    btns.setPosition(420,600);
    st.setPosition(btns.getPosition().x+40,btns.getPosition().y+10);

    for(int i=0;i<7;i++)
    {
        spr[i].setTexture(txt[i]);
        spr[i].setPosition(300,200);

    }
    spr[4].setPosition(0.f,0.f);
    spr[5].setPosition(WIDTH-715,HEIGHT-370);
    spr[6].setPosition(WIDTH-297,HEIGHT-365);
}
void Selectship::render(bool &fl,State &s,int &n)
{
     update(this->no,fl,s);
     n=this->no;
     window->draw(spr[4]);
     window->draw(spr[5]);
     window->draw(spr[6]);
     window->draw(spr[no]);
     window->draw(btns);
     window->draw(st);
}
void Selectship::update(int &no,bool &f,State &st)
{
    if(spr[5].getPosition().x<=sf::Mouse::getPosition(*window).x && spr[5].getPosition().x+spr[5].getGlobalBounds().width>=sf::Mouse::getPosition(*window).x && spr[5].getPosition().y<=sf::Mouse::getPosition(*window).y && spr[5].getPosition().y+spr[5].getGlobalBounds().height>=sf::Mouse::getPosition(*window).y)
    {
        spr[5].setColor(sf::Color(0,110,150));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && f==true)
        {
            if(no==0)
            {
             no=3;
            }
            else
            {
                no-=1;
            }
            f=false;
        }
    }

    else spr[5].setColor(sf::Color::White);
     if(spr[6].getPosition().x<=sf::Mouse::getPosition(*window).x && spr[6].getPosition().x+spr[6].getGlobalBounds().width>=sf::Mouse::getPosition(*window).x && spr[6].getPosition().y<=sf::Mouse::getPosition(*window).y && spr[6].getPosition().y+spr[6].getGlobalBounds().height>=sf::Mouse::getPosition(*window).y)
    {
        spr[6].setColor(sf::Color(0,110,150));
     if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& f==true)
      {

            if(no==3)
            no=0;
            else no+=1;
            f=false;
    }

    }
    else spr[6].setColor(sf::Color::White);
    if(btns.getPosition().x<=sf::Mouse::getPosition(*window).x && btns.getPosition().x+btns.getGlobalBounds().width>=sf::Mouse::getPosition(*window).x && btns.getPosition().y<=sf::Mouse::getPosition(*window).y && btns.getPosition().y+btns.getGlobalBounds().height>=sf::Mouse::getPosition(*window).y)
    {
        btns.setColor(sf::Color(10,200,210));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            st=PLAY;
        }
    }
        else btns.setColor(sf::Color::White);
}
