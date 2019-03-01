#ifndef FLOWER_H
#define FLOWER_H

#include <Plant.h>
#include <Herbivore.h>

#include <SFML/Graphics.hpp>

// Flowers can bloom but nobody knows why and what for.
// They have faces, and the same cat-face thing (yes, ask cats about it), and nothing more.
// Somehow they are slightly afraid of cows.

class Flower : public Plant
{
    public:
        Flower();
        Flower(double m);
        Flower(double m, int _x, int _y);
        virtual ~Flower();
        bool bloom;
        void setSprite();
    private:
        static sf::Texture *texture;
};

#endif // FLOWER_H
