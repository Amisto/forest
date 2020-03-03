#include "Plant.h"
class Forest;
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

void Plant::grow(Forest* f) {

}
