
#ifndef FOREST_MONKEY_H
#define FOREST_MONKEY_H

#include "Animal.h"
#include "Carnivore.h"
#include "Herbivore.h"

#include <SFML/Graphics.hpp>

class Monkey : public Animal, public Carnivore, public Herbivore
{
    //Monkey is free enough to eat whatever it wants, it can eat meat either plants.
    //Dramatically there are no enough small animals to be eaten by Monkey.
    //We hope it'll find them soon.
public:
    Monkey();
    Monkey(double m, double b);
    Monkey(double m, double b, int _x, int _y);
    ~Monkey();
    void talk() override;
    void setSprite() override;
    void walk(Forest *f) override; //it also jumps in a special way( not especially special).
private:
    static sf::Texture *texture;
};

#endif //FOREST_MONKEY_H
