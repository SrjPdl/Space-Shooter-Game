#ifndef PICKUP_H
#define PICKUP_H

#include <Character.h>
#include "PL.h"


class Pickup : public Character
{
    private:
        sf::Texture bpt;
        sf::Texture hpt;
        sf::Sprite bps;
        sf::Sprite hps;
        sf::SoundBuffer s_p;
        sf::Sound sd_p;
        int btimer;
        int htimer;
        PL *pl;
        SYSTEMTIME time;
        const int speed;
        bool bpc;
        bool hpc;
        bool bppc;
        bool hppc;

    public:
        Pickup();
        ~Pickup();
        void init();
        void update(float dt);
        void drawin();
        void getplayer(PL *pl);
        void check(int *nob, int *hp);
};

#endif // PICKUP_H
