#include "Plant.h"

// Not much to see here, huh.

Plant::Plant()
{
}

Plant::Plant(double m) : Creature(m)
{
}

Plant::Plant(double m, int _x, int _y) : Creature(m, _x, _y)
{
}

Plant::~Plant()
{
}
