#ifndef COW_H
#define COW_H

#include <Animal.h>
#include <Herbivore.h>

#include <SFML/Graphics.hpp>

// Cows are big and lazy plant-eating beasts.
// They can talk, but rarely anything interesting.
// They desperately need someone to teach them how to live.

// Notice that they have the same face thing as cats.
// Ask cats about it.

class Cow : public Animal, public Herbivore
{
    public:
        Cow();
        Cow(double m, double b);
        Cow(double m, double b, int _x, int _y);
        virtual ~Cow();
        void talk();
        void setSprite();
    private:
        static sf::Texture *texture;
};

#endif // COW_H
