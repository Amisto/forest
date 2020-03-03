#include "Mushroom.h"
#include "Forest.h"

#include<iostream>
#include <SFML/Graphics.hpp>

#define R 2

using namespace std;

vector <Mushroom*> Mushroom::Mycellium = vector<Mushroom*>();
int Mushroom::Mycellium_state = 0;
sf::Texture* Mushroom::texturedown = NULL;
sf::Texture* Mushroom::textureup = NULL;

Mushroom::Mushroom(): state(true)
{
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}

Mushroom::Mushroom(double m) : Plant(m), state(true)
{
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}
Mushroom::Mushroom(double m, int _x, int _y): Plant(m, _x, _y), state(true)
{
    Mycellium.push_back(this);
    mNumber = Mycellium.size() - 1;
}

Mushroom::~Mushroom()
{
    for (int i = 0; i < Mycellium.size(); i++)
    {
        if(Mycellium[i] == this) {
            Mycellium.erase(Mycellium.begin() + i);
            break;
        }
    }
}

void Mushroom::setSprite()
{
    if (!textureup)
    {
        textureup = new sf::Texture;
        if(!(textureup->loadFromFile("res/mushrooms/mushroom_up.png")))
            cout << "Mushroom went wrong" << endl;
    }

        if (!texturedown)
    {
        texturedown = new sf::Texture;
        if(!(texturedown->loadFromFile("res/mushrooms/mushroom_down.png")))
            cout << "Mushroom went wrong" << endl;
    }
    s = new sf::Sprite;
    s->setTexture(*textureup);
}

void Mushroom::grow(Forest* f) {
    int _x = x;
    int _y = y;
    for(int i = 0 - R; i < 1 + R; i++)
        for (int j = 0 - R; j < 1 + R; j++)
            if ( (j||i) && !(f->checkAnimals(_x + i, _y + j)) ) {
                s->setTexture(*texturedown);
                state=false;
                return;
            }
    if(!state) {
        s->setTexture(*textureup);
        state = true;
    }

}
