#include "Flower.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Flower::texture = NULL;

Flower::Flower()
{
    bloom = false;
}

Flower::Flower(double m): Plant(m)
{
    bloom = false;
}

Flower::Flower(double m, int _x, int _y): Plant(m, _x, _y)
{
    bloom = false;
}

Flower::~Flower()
{
    if(texture) {
        delete texture;
        texture = NULL;
    }
}

// Flowers listen to the blowing wind.
// Try asking cats about this part.

void Flower::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/flower.png"))
            cout <<"Flower went wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
