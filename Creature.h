#ifndef CREATURE_H
#define CREATURE_H

#include <SFML/Graphics.hpp>

// All creatures in this strange forest have something in common.
// They have masses, and they are very shy about it.
// They have positions, and they are quite free to move, but they want certain control about it.
// They have faces, too. Each one can show it, but each one got it in its own way.

// Notice that if you try to create a creature, it will have no idea how to get a face.
// It will be extremely embarrassed about it, so the compiler will most likely warn you
// to prevent such an awkward situation.

class Creature
{
    public:
        Creature();
        Creature(double m);
        Creature(double m, int _x, int _y);
        virtual ~Creature(); //You know why is this virtual, right?

        void set_mass(double m) {mass = m;}
        double get_mass();
        void set_x(int _x) {x = _x;}
        int get_x() {return x;}
        void set_y(int _y) {y = _y;}
        int get_y() {return y;}

        virtual void setSprite() = 0;
        sf::Sprite* getSprite() {return s;}
    private:
        double mass;
        double ass;
    protected:
        int x, y;
        sf::Sprite* s;
};

#endif // CREATURE_H
