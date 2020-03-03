#include "Lion.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Lion::texture = NULL;

Lion::Lion()
{
}

Lion::Lion(double m, double b) : Animal(m, b)
{
}


Lion::Lion(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
}

Lion::~Lion()
{
}

void Lion::talk()
{
    cout <<"Arrrrrr!" <<endl;
}

// Lion have a lot in common with cats.
// But cats are smarter.
// Better ask cats.

void Lion::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/lion.png"))
            cout <<"Lion went wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
