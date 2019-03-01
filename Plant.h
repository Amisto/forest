#ifndef PLANT_H
#define PLANT_H

#include <Creature.h>

// Plants stand and grow.
// They do not care where the food comes from.
// They do not know how to get their faces and, as plants, do not care about faces at all.

// You can make their life more fulfilling.

class Plant : public Creature
{
    public:
        Plant();
        Plant(double m);
        Plant(double m, int _x, int _y);
        virtual ~Plant();
        void gain_mass(double dm) {Creature::set_mass(Creature::get_mass() + dm);}
    private:
};

#endif // PLANT_H
