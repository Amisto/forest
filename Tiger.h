//
// Created by zugvangg on 07.04.2020.
//
#ifndef TIGER_H
#define TIGER_H
#include "Animal.h"
#include "Carnivore.h"

#include <SFML/Graphics.hpp>



class Tiger : public Animal, public Carnivore
{
public:
    Tiger();
    Tiger(double m, double b);
    Tiger(double m, double b, int _x, int _y);
    ~Tiger();
    void talk() override;
    void setSprite() override;
    void sound();
private:
    static sf::Texture *texture;
};


#endif //TIGER_H
