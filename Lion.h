#ifndef LION_H
#define LION_H

#include "Animal.h"
#include "Carnivore.h"

#include <SFML/Graphics.hpp>

// Lion are big and scary cat eat cow.
// They can scream, but rarely anything interesting.
// They desperately need someone to teach them how to live.

// Notice that they have the same face thing as cats.
// Ask cats about it.

class Lion : public Animal, public Carnivore
{
    public:
        Lion();
        Lion(double m, double b);
        Lion(double m, double b, int _x, int _y);
        ~Lion();
        void talk() override;
        void setSprite() override;
    private:
        static sf::Texture *texture;
};

#endif // LION_H
