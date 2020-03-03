#ifndef MUSHROOM_H_INCLUDED
#define MUSHROOM_H_INCLUDED
#include<vector>
#include "Plant.h"
#include <SFML/Graphics.hpp>



class Mushroom: public Plant
{
public:
    Mushroom();
    Mushroom(double m);
    Mushroom(double m, int _x, int _y);
    ~Mushroom();
    void grow(Forest* f) override;
    void setSprite() override;
protected:
    int mNumber;
    bool state;
    static sf::Texture *textureup;
    static sf::Texture *texturedown;
    static std::vector <Mushroom*> Mycellium;
    static int Mycellium_state;
};

#endif // MUSHROOM_H_INCLUDED
