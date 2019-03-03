#include "Sundew.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Sundew::texture = NULL;

Sundew::Sundew()
{
}

Sundew::Sundew(double m): Plant(m)
{
}

Sundew::Sundew(double m, int _x, int _y): Plant(m, _x, _y)
{
}

Sundew::~Sundew()
{
    if(texture) {
        delete texture;
        texture = NULL;
    }
}

// Sundews wait for insects but to no avail.
// They are angry and vicious and definitely not talkative.
// I asked the cats and they grudgingly agreed to help you.

void Sundew::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/sundew.png"))
            cout <<"Sundew went wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
