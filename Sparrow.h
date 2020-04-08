#ifndef Sparrow_h
#define Sparrow_h

#include "Animal.h"
#include "Herbivore.h"
#include <SFML/Graphics.hpp>

class Sparrow: public Animal, public Herbivore{
public:
    Sparrow();
    Sparrow(double m, double b);
    Sparrow(double m, double b, int _x, int _y);
    ~Sparrow();
    void talk() override;
    void setSprite() override;
private:
    static sf::Texture *texture;
};
#endif
