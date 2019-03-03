#ifndef SUNDEW_H
#define SUNDEW_H

#include <Plant.h>
#include <Carnivore.h>

#include <SFML/Graphics.hpp>

// Sundews are flesh-eating plants.
// Normally, they eat insects, but this forest is strange, and they had to adjust.
// Help them to do it.

// Ask cats about this face thing.

class Sundew : public Plant, public Carnivore
{
    public:
        Sundew();
        Sundew(double m);
        Sundew(double m, int _x, int _y);
        virtual ~Sundew();
        void setSprite();
    private:
        static sf::Texture *texture;
};

#endif // SUNDEW_H
