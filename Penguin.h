#ifndef PENGUIN_H
#define PENGUIN_H

#include "Animal.h"
#include "Herbivore.h"

#include <SFML/Graphics.hpp>

class Penguin : public Animal, public Herbivore
{
    public:
        Penguin();
        Penguin(double m, double b);
        Penguin(double m, double b, int _x, int _y);
        ~Penguin();
        void talk() override;
        void setSprite() override;
    private:
        static sf::Texture *texture;
};


#endif // PENGUIN_H_INCLUDED
