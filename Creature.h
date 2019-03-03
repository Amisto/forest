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

        virtual void set_mass(double m) final {mass = m;}
        virtual double get_mass() final;
        virtual void set_x(int _x) final {x = _x;}
        virtual int get_x() final {return x;}
        virtual void set_y(int _y) final {y = _y;}
        virtual int get_y() final {return y;}

        virtual void setSprite() = 0;
        virtual sf::Sprite* getSprite() final {return s;}
    private:
        double mass;
        double ass;
    protected:
        int x, y;
        sf::Sprite* s;
};

#endif // CREATURE_H
