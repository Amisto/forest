#ifndef FOREST_FISH_H
#define FOREST_FISH_H


#include "Animal.h"
#include "Herbivore.h"

#include <SFML/Graphics.hpp>

class Fish : public Animal, Herbivore {
public:
    Fish();

    Fish(double m, double b);

    Fish(double m, double b, int _x, int _y);

    ~Fish();

    void walk(Forest *f) override;

    void talk() override;

    void setSprite() override;

private:
    static sf::Texture *texture;
    int vx, vy;
};


#endif //FOREST_FISH_H
