// The heart of the forest - its deep thoughts and distant rambling and horrors unseen from the outside.

#include "Forest.h"
#include "Cow.h"
#include "Cat.h"
#include "Lion.h"
#include "Flower.h"
#include "Sundew.h"
#include "Mushroom.h"
#include "Penguin.h"
#include "Fish.h"
#include "Sparrow.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Pixie size of screen.
#define SX 1500
#define SY 1000

Forest* Forest::instance = NULL;

Forest* Forest::get_instance()
{
    if (!instance)
    {
        cout <<"Warning - an empty Forest was created. Don't expect much." <<endl;
        instance = new Forest;
    }
    return instance;
}

Forest* Forest::get_instance(int na, int np, int _X, int _Y)
{
    if (!instance)
    {
        instance = new Forest;
        if (int e = instance->init(na, np, _X, _Y))
        {
            cout <<"Forest failed with code " <<e <<endl;
            delete instance;
            instance = NULL;
        }
    }
    return instance;
}

void Forest::clear_instance()
{
    delete instance;
    instance = NULL;
}

Forest::Forest()
{
    n_animals = 0;
    animals = NULL;
    n_plants = 0;
    plants = NULL;
    X = Y = 0;
    window = NULL;
    key_pressed = false;
    srand(time(NULL));
}

Forest::~Forest()
{
    for (int i=0; i<n_animals; i++)
        delete animals[i];
    for (int i=0; i<n_plants; i++)
        delete plants[i];
    delete[] animals;
    delete[] plants;
    delete window;
}

// It is a rare man nowadays who listens to the forest.
void Forest::listen()
{
    if (!animals) return;
    for (int i=0; i<n_animals; i++)
        animals[i]->talk();
}

int Forest::init(int na, int np, int _X, int _Y)
{
    n_animals = na;
    animals = new Animal*[n_animals];
    if (!animals) return 1;
    for (int i=0; i<n_animals; i++)
    {
        int r = rand()%6;           // The amount of animals is given from beyond, but each animal can decide
                                    // what it wants to be.
        switch(r) {
        case 0:
        {
            if (!(animals[i] = new Cow(1, 1)))
                return 2;
            break;
        }
        case 1:
        {
            if (!(animals[i] = new Cat(1, 1)))
                return 3;
            break;
        }
        case 2:
        {
            if (!(animals[i] = new Lion(1, 1)))
                return 33;
            break;
        }
        case 3:
        {
            if (!(animals[i] = new Penguin(1,1)))
                return 4;
            break;
        }
        case 4:
        {
            if (!(animals[i] = new Fish(1,1)))
                return 0;
            break;
        }
        case 5:
        {
            if (!(animals[i] = new Sparrow(1,1)))
                return 0;
            break;
        }
        }
    }
    n_plants = np;
    plants = new Plant*[n_plants];
    if (!plants) return 4;
    for (int i=0; i<n_plants; i++)
    {
        int r = rand()%3;           // The amount of plants is also given from beyond, and each plant can also decide
        switch (r) {
        case 0:


            if (!(plants[i] = new Sundew(1)))
                return 5;
            break;


        case 1:


            if (!(plants[i] = new Flower(1)))
                return 6;
            break;


        case 2:

            if (!(plants[i] = new Mushroom(1))) {

                return 9;
            }
            break;

        }
    }

    int ia = 0, ip = 0, _x, _y;
    X = _X, Y = _Y;

    // We try to set them apart from each other.
    bool **taken;
    taken = new bool*[X];
    if (!taken) return 7;
    for (int i=0; i<X; i++)
        if (!(taken[i] = new bool[Y]))
            return 8;

    for (int i=0; i<X; i++)
        for (int j=0; j<Y; j++)
            taken[i][j] = false;

    while (ip < n_plants)
    {
        // Looking through all the animals and plants, one at a time, and finding each one a cozy spot.
        // It might take time if the forest is small and crowded.
        _x = rand()%X;
        _y = rand()%Y;
        if (taken[_x][_y]) continue;
        plants[ip]->set_x(_x);
        plants[ip]->set_y(_y);
        plants[ip]->setSprite();
        taken[_x][_y] = true;
        ip++;
    }
    while (ia < n_animals)
    {
        _x = rand()%X;
        _y = rand()%Y;
        if (taken[_x][_y]) continue;
        animals[ia]->set_x(_x);
        animals[ia]->set_y(_y);
        animals[ia]->setSprite();
        taken[_x][_y] = true;
        ia++;
    }

    for (int i=0; i<X; i++)
        delete[] taken[i];
    delete taken;

    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;
    window = new sf::RenderWindow(sf::VideoMode(SX, SY), "Forest", sf::Style::Default, contextSettings);
    window->setActive();

    return 0;
}

void Forest::live()
{
    if (!window || !animals || !plants) return; // Playing safe.

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

        }

        // The forest allows you to guide it to the future, one step at a time.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (!key_pressed)
            {
                move();
                key_pressed = true;
            }
        }
        else key_pressed = false;

        window->clear(sf::Color(0,50,0));  // Evergreen forest is behind all the things here.
        draw();
        window->display();
    }
}

void Forest::draw()
{
    if (!window || !animals || !plants) return;

        // Plants and animals are really trusting to let everyone meddle with their faces.
        // But this is most convenient for the forest.

    for (int i = 0; i < n_plants; i++)
    {
        sf::Sprite *s = plants[i]->getSprite();
        if (!s) continue;
        s->setPosition(sf::Vector2f(plants[i]->get_x() * SX / (float)X, plants[i]->get_y() * SY / (float)Y));
        s->setScale(sf::Vector2f(SX / 200.0 / X, SY / 200.0 / Y));
        window->draw(*s);
    }
    for (int i = 0; i < n_animals; i++)
    {
        sf::Sprite *s = animals[i]->getSprite();
        if (!s) continue;
        s->setPosition(sf::Vector2f(animals[i]->get_x() * SX/(float)X, animals[i]->get_y() * SY / (float)Y));
        s->setScale(sf::Vector2f(SX / 200.0 / X, SY / 200.0 / Y));
        window->draw(*s);
    }
}

// This is for animals, remember?
// Looks like the forest is not as deceiving as some animals expected.
// It even tells animals of other animals or plants being here.
bool Forest::check(int x, int y)
{
    if (x >= 0 && x < X && y >= 0 && y < Y)
    {

        for (int i = 0; i < n_animals; i++) {
        if (animals[i]->get_x() == x && animals[i]->get_y() == y)
            return 0;
        }

        for (int i = 0; i < n_plants; i++) {
        if(plants[i]->get_x() == x && plants[i]->get_y() == y)
            return 0;
        }
    }
    else return 0;
    return x >= 0 && x < X && y >= 0 && y < Y;
}

bool Forest::checkAnimals(int x, int y)
{
    for (int i = 0; i < n_animals; i++) {
        if(animals[i]->get_x() == x && animals[i]->get_y() == y)
            return 0;
    }
    return 1;
}

bool Forest::checkPlants(int x, int y)
{
    for (int i = 0; i < n_plants; i++) {
        if(plants[i]->get_x() == x && plants[i]->get_y() == y)
            return 0;
    }
    return 1;
}

// The polite part of the forest, where it gently asks all the animals to make a step.
void Forest::move()
{
    if (!animals) return;
    for (int i = 0; i < n_animals; i++)
        animals[i]->walk(this);
    if (!plants) return;
    for (int i = 0; i < n_plants; i++)
        plants[i]->grow(this);
}
