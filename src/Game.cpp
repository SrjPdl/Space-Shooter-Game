#include "Game.h"


void Game::initWin()
{
    this->window.create(sf::VideoMode(WIDTH,HEIGHT),"GAME",sf::Style::Close);
    this->window.setPosition(sf::Vector2i(200,0));
    mm=new Mainmenu;
    ship=new Selectship;
    fl=1;
    p=0;
    winfl=1;
    scf=true;
    scn=0;
    state=Menu;
    deletecontroller=true;
    mm->getwin(&window);
    ship->getwin(&window);
    hb.getwin(&window);
    bg.getwin(&window);
    bullet.getwin(&window);
    player.getwin(&window);
    enemy.getwin(&window);
    g.getwin(&window);
    pickup.getwin(&window);
    score.setFont(mm->rtnfnt());
    score.setPosition(window.getSize().x-90,100);
    score.setColor(sf::Color::White);

    b_no.setFont(mm->rtnfnt());
    b_no.setPosition(window.getSize().x-90,200);
    b_no.setColor(sf::Color::White);
    s=0;
    b=100;

}

Game::Game()
{

    this->initWin();
}

Game::~Game()
{
    delete mm;

}


void Game::updateDt()
{
    this->dt=this->dtClock.restart().asSeconds();

}
void Game::updateWindowEvent()
{
    while(this->window.pollEvent(this->winEvnt))
    {
        switch(this->winEvnt.type)
        {
        case sf::Event::Closed:
            this->window.close();
            break;
        }
    }
}
void Game::update()
{
    this->updateWindowEvent();
    if(state==PLAY)
    {
    player.update(dt);
    enemy.update(dt);
    pickup.update(dt);

    if(fl)
    bullet.update(dt);
    enemy.getpl(player);
    bullet.getpl(player);
    bullet.geten(&enemy);
    pickup.getplayer(&player);
    fl=1;
    }
}
void Game::run()
{
    while(this->window.isOpen() && winfl)
    {
            this->updateDt();
            this->update();
            enemy.plhpcheck(hp);
            this->rdr();
            p++;
            if(p==450)
            {
                scf=true;
                p=0;
            }
    }
}
void Game::rdr()
{
    this->window.clear(sf::Color(0,32,71));
    if(state==Menu)
    {
        mm->draw(state,winfl);
    }
    else if(state==SPACESHIP)
    {
        ship->render(scf,state,scn);
    }
    else if(state==PLAY)
    {   if(deletecontroller)
        {
            delete ship;
            deletecontroller=false;
        }
        bg.setsize(1,1);
        bg.draw();
        hb.drawhp(hp);
        player.shipselection(scn);
        player.drawin();
        enemy.drawin();
        bullet.drawin();
        pickup.drawin();
        status();
        if(hp<=0)
            state=EXIT;
    }
    else if(state==EXIT)
    {
        g.draw(enemy,winfl,state,s);
        fl=0;
        s=0;
        b=100;
    }
    this->window.display();
}
void Game::status()
{

        bullet.scor(&s,&b);
        pickup.check(&b,&hp);
        enemy.sethp(hp);
        std::stringstream sc,bt;
        sc<<s;
        bt<<b;
        score.setPosition(score.getPosition().x-80,score.getPosition().y);
        score.setString("Score: ");
        window.draw(score);
        score.setPosition(score.getPosition().x+80,score.getPosition().y);
        score.setString(sc.str());
        window.draw(score);

        b_no.setPosition(b_no.getPosition().x-80,b_no.getPosition().y);
        b_no.setString("Bullet:");
        window.draw(b_no);
        b_no.setPosition(b_no.getPosition().x+80,b_no.getPosition().y);
        b_no.setString(bt.str());
        window.draw(b_no);
}
