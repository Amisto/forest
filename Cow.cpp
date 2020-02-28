#include "Cow.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Cow::texture = NULL;

Cow::Cow()
{
}

Cow::Cow(double m, double b) : Animal(m, b)
{
}


Cow::Cow(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
}

Cow::~Cow()
{
    if (texture)
    {
        delete texture;
        texture=NULL;
    }
}

void Cow::talk()
{
    cout <<"Moo" <<endl;
}

// Cows have a lot in common with cats.
// But cats are smarter.
// Better ask cats.

void Cow::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/cow.png"))
            cout <<"Cow went wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
