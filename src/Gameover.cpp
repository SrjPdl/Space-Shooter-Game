#include "Gameover.h"

Gameover::Gameover()
{
    init();
}

Gameover::~Gameover()
{
    //dtor
}
void Gameover::getwin(sf::RenderWindow *window)
{
    this->window=window;
}
void Gameover::init()
{
    font.loadFromFile("Font/font.ttf");
    buttont.loadFromFile("Images/buttons/select.png");
    bg.loadFromFile("Images/Bg/GO.jpg");
    bgs.setTexture(bg);
    title.setFont(font);
    exit.setFont(font);
    scrdisp.setFont(font);
    scrdisp.setFillColor(sf::Color(123,34,234));
    scrdisp.setCharacterSize(100);
    scrdisp.setOutlineColor(sf::Color(171,11,111));
    scrdisp.setOutlineThickness(3.f);
    getscore=true;
    button[0].setPosition(WIDTH/4-160,HEIGHT/2+1);
    button[1].setPosition(WIDTH/4*3+50,HEIGHT/2+1);
    for(int j=0;j<2;j++)
        button[j].setTexture(buttont);

    title.setPosition(WIDTH/4-140,HEIGHT/2+15);
    title.setColor(sf::Color::White);
    title.setString("RETRY");

    exit.setPosition(WIDTH/4*3+80,HEIGHT/2+15);
    exit.setColor(sf::Color::White);
    exit.setString("EXIT");
}
void Gameover::draw(EN &e,int &winfl,State &state,int s)
{
      if(getscore)
            {   ss.str("");
                this->s=s;
                ss<<s;
                getscore=false;
            }
     setc(e,winfl,state);
     window->draw(bgs);
     for(int j=0;j<2;j++)
     window->draw(button[j]);
     window->draw(title);
     window->draw(exit);
     score();
}
void Gameover::setc(EN &e,int &winfl,State &state)
{
    if(sf::Mouse::getPosition(*window).x>=button[0].getPosition().x && sf::Mouse::getPosition(*window).x<=button[0].getPosition().x+button[0].getGlobalBounds().width && sf::Mouse::getPosition(*window).y>=button[0].getPosition().y && sf::Mouse::getPosition(*window).y<=button[0].getPosition().y+button[0].getGlobalBounds().height)

       {
           button[0].setColor(sf::Color(0,110,150));
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
           {
            e.sethp(10);
            state=PLAY;
            getscore=true;
           }
       }
    else
    {

        button[0].setColor(sf::Color::White);

    }
    if(sf::Mouse::getPosition(*window).x>=button[1].getPosition().x && sf::Mouse::getPosition(*window).x<=button[1].getPosition().x+button[1].getGlobalBounds().width && sf::Mouse::getPosition(*window).y>=button[1].getPosition().y && sf::Mouse::getPosition(*window).y<=button[1].getPosition().y+button[1].getGlobalBounds().height)
    {
        button[1].setColor(sf::Color(0,110,150));
         if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
           {
                winfl=0;
           }
    }
    else{
        button[1].setColor(sf::Color::White);
    }

}
void Gameover::score()
{
        scrdisp.setPosition(300,100);
        scrdisp.setString("SCORE:");
        window->draw(scrdisp);
        scrdisp.setPosition(300+310,100);
        scrdisp.setString(ss.str());
        window->draw(scrdisp);

}

