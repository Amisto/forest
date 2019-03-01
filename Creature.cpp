#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature() : s(NULL)
{
}

Creature::Creature(double m) : mass(m), s(NULL)
{
}

Creature::Creature(double m, int _x, int _y) : mass(m), x(_x), y(_y), s(NULL)
{
}

// "I don't know how it got here, but I'm gonna clean this."
Creature::~Creature()
{
    if (s)
        delete s;
}

// You can change his mind.
double Creature::get_mass()
{
    cout <<"And why exactly do you need my mass?" <<endl;
    return 0.0;
}
