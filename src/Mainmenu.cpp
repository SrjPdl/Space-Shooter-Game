#include "Mainmenu.h"

Mainmenu::Mainmenu()
{
    init();
}

Mainmenu::~Mainmenu()
{

}
void Mainmenu::getwin(sf::RenderWindow *window)
{
    this->window=window;
}
void Mainmenu::init()
{
    cont=0;
    font.loadFromFile("Font/font.ttf");
    txtr[0].loadFromFile("Images/Bg/mbg.jpg");
    txtr[1].loadFromFile("Images/buttons/select.png");
    bg.setTexture(txtr[0]);
    bck.setFont(font);
    area.setFont(font);
    area.setPosition(sf::Vector2f(0,HEIGHT/2-200));
    area.setFillColor(sf::Color::Green);
    area.setCharacterSize(40);
    area.setOutlineColor(sf::Color::White);
    area.setOutlineThickness(1.f);
    bck.setPosition(45,HEIGHT-(Back.getGlobalBounds().left+Back.getGlobalBounds().height)-55);
    bck.setString("Back");
    Back.setTexture(txtr[1]);
    Back.setPosition(0,HEIGHT-(Back.getGlobalBounds().left+Back.getGlobalBounds().height));
    sbst=none;
    getdata=true;
    for(int i=0;i<btn_no;i++)
    {
    text[i].setFont(font);
    buttons[i].setTexture(txtr[1]);
    buttons[i].setPosition((WIDTH/2-buttons[i].getGlobalBounds().width/2),100+(HEIGHT/4)*i);
    text[i].setPosition((WIDTH/2-buttons[i].getGlobalBounds().width/2+40),110+(HEIGHT/4)*i);
    }
    text[0].setString("START");
    text[1].setString("HELP");
    text[2].setString("ABOUT");
    text[3].setString("EXIT");
}
void Mainmenu::draw(State &state,int &winfl)
{

    click(state,winfl);
    if(sbst==none)
    {
        window->draw(bg);
        for(int i=0;i<btn_no;i++)
        {
            window->draw(buttons[i]);
            window->draw(text[i]);
        }
    }
    if(sbst==help1)
    {
        window->draw(area);
        window->draw(Back);
        window->draw(bck);
    }
    if(sbst==about1)
    {
        window->draw(area);
        window->draw(Back);
        window->draw(bck);
    }
}
void Mainmenu::click(State &state,int &winfl)
{
    for(int i=0;i<btn_no;i++)
    {
        switch(sbst)
        {
            case none:
                if(sf::Mouse::getPosition(*window).x>=buttons[i].getPosition().x && sf::Mouse::getPosition(*window).x<=buttons[i].getPosition().x+buttons[i].getGlobalBounds().width && sf::Mouse::getPosition(*window).y>=buttons[i].getPosition().y && sf::Mouse::getPosition(*window).y<=buttons[i].getPosition().y+buttons[i].getGlobalBounds().height)
                  {
                    buttons[i].setColor(sf::Color(0,110,150));
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                             if( i==0)
                                {
                                    state=SPACESHIP;
                                }
                            if(i==3)
                                {
                                    winfl=0;
                                }
                            if(i==1)
                                {
                                    cnt.str("");
                                    getdata=true;
                                    cont=0;
                                    sbst=help1;
                                }
                                if(i==2)
                                {   cnt.str("");
                                    getdata=true;
                                    cont=0;
                                    sbst=about1;
                                }
                        }
                }
            else
                {
                    buttons[i].setColor(sf::Color::White);

                }
            break;
            case help1:
                help();
                if(sf::Mouse::getPosition(*window).x>=Back.getPosition().x && sf::Mouse::getPosition(*window).x<=Back.getPosition().x+buttons[i].getGlobalBounds().width && sf::Mouse::getPosition(*window).y>=Back.getPosition().y && sf::Mouse::getPosition(*window).y<=Back.getPosition().y+buttons[i].getGlobalBounds().height)
                    {
                        Back.setColor(sf::Color(0,110,150));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        sbst=none;
                    }
                 else
                    {
                        Back.setColor(sf::Color::White);
                    }

                break;
            case about1:
                about();
                if(sf::Mouse::getPosition(*window).x>=Back.getPosition().x && sf::Mouse::getPosition(*window).x<=Back.getPosition().x+buttons[i].getGlobalBounds().width && sf::Mouse::getPosition(*window).y>=Back.getPosition().y && sf::Mouse::getPosition(*window).y<=Back.getPosition().y+buttons[i].getGlobalBounds().height)
                    {
                        Back.setColor(sf::Color(0,110,150));
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        sbst=none;
                    }
                 else
                    {
                        Back.setColor(sf::Color::White);
                    }
        }
}
}
void Mainmenu::help()
{
    if(getdata)
    {
        in.open("data/help.las");
        while(!in.eof())
        {
            in.get(c);
            cont++;
        }
        in.close();
        in.open("data/help.las");
        char *s=new char[cont];
        in.getline(s,cont,'$');
        cnt.write(reinterpret_cast<char*>(s),cont-5);
        area.setString(cnt.str());
        getdata=false;
        in.close();
        delete [] s;
    }

}
void Mainmenu::about()
{
    if(getdata)
    {   in.open("data/about.las");
        while(!in.eof())
        {
            in.get(c);
            cont++;
        }
        in.close();
        in.open("data/about.las");
        char *s=new char[cont];
        in.getline(s,cont,'$');
        cnt.write(reinterpret_cast<char*>(s),cont-2);
        area.setString(cnt.str());
        getdata=false;
        delete [] s;
        in.close();
    }

}
sf::Font& Mainmenu::rtnfnt()
{
    return font;
}
