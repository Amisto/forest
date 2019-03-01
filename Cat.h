#ifndef CAT_H
#define CAT_H

#include <Animal.h>
#include <Carnivore.h>

#include <SFML/Graphics.hpp>

// Cats are cute and effective predators who stalk their prey in this strange forest and like to talk about it.
// At the moment, they do not have much to talk about.
// You can change that.

// All cats in this strange dark forest seem to have the same face.
// I can say you more than that - they all have a one single face that they discontentedly share.
// When you look at a cat, through her personal creature face you actually see that single common muzzle.
// Cats are strange creatures.

class Cat : public Animal, public Carnivore
{
    public:
        Cat();
        Cat(double m, double b);
        Cat(double m, double b, int _x, int _y);
        virtual ~Cat();
        void talk();
        void setSprite();
    private:
        static sf::Texture *texture;

        // If you want to deal with catkind face in the very proper and polite way,
        // you can also count cats in the forest - noticing every cat that walks in and every cat that walks out.
        // If all the cats are gone in one way or another, and you do not expect them to return any soon,
        // you can delete their shared face.
        // Common faces are heavy for the forest to remember, and if it is inhabited by too many different creatures,
        // something may be lost, forgotten or broken, and the forest will drown in cold imperceivable void
        // with segmented tentacles of morbid machinery.
        // Do not let that happen.
};

#endif // CAT_H
