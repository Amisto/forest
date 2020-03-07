#include "Sparrow.h"

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>

sf::Texture* Sparrow::texture = NULL;

Sparrow::Sparrow() {

}

Sparrow::Sparrow(double m, double b) : Animal(m, b) {
}


Sparrow::Sparrow(double m, double b, int _x, int _y) : Animal(m, b, _x, _y) {
}

Sparrow::~Sparrow() {

}

void Sparrow::talk() {
    cout <<"Chirick chirick" <<endl;
}

void Sparrow::setSprite() {
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/sparrow.png"))
            cout <<"Sparrow fly wrong" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
