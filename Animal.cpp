#include "Animal.h"
#include "Forest.h"

#include <stdlib.h>

Animal::Animal()
{
}

Animal::Animal(double m, double b) : Creature(m), brain(b)
{
}

Animal::Animal(double m, double b, int _x, int _y) : Creature(m, _x, _y), brain(b)
{
}

Animal::~Animal()
{
}

// We let an animal decide where to go:
// - some want to go to certain plants
// - some want to hunt each other
// - some will want, consequently, to run from each other.
// Without a specific behavior, the animal will wander aimlessly.

// The animal wants to know something about the forest it lives in.
// The forest may allow the animal to see some things, real or not.
// In this case, the forest allows the animal to see the borders.
// The animal can only hope that the forest does not lie.

void Animal::walk(Forest* f)
{
    bool check = false;
    int _x = x, _y = y;
    while(!check)
    {
        _x = x, _y = y;
        int dir = rand()%4;
        switch (dir)            // Just a dainty step in a random direction.
        {
            case 0: _x++; break;
            case 1: _x--; break;
            case 2: _y++; break;
            case 3: _y--; break;
        }
        check = f->check(_x, _y);   // When making a step, first try the ground.
                                    // If it fails you, just try again.
    }
    x = _x, y = _y;                 // Stepping to the safe forest ground.
}
