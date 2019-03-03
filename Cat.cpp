#include "Cat.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Cat::texture = NULL;

Cat::Cat()
{
}

Cat::~Cat()
{
}


Cat::Cat(double m, double b) : Animal(m, b)
{
}

Cat::Cat(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
}

void Cat::talk()
{
    cout <<"Mew" <<endl;
}

// This is how a specific creature gets its face.

// When the first cat appears in the forest, it looks at distant hieroglyphs inside of a morbid machinery
// to find the shared face for all of the kind. If the first cat fails, the rest will try again, but they will
// look at the same place and fail just the same way. Cats will be faceless then, lurking in the deep dark forest
// unnoticed and unwelcome.
// If the first cat succeeds, it gets its face.
// All the following cats will find the catkind face in its sacred place, obtaining faces of their own.

// Cats are not happy with this way of things and people trampling in and asking questions.
// Maybe you will be able to free them from this burden.

void Cat::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/cat.png"))
            cout <<"Cat went wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
