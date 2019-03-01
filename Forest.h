#ifndef FOREST_H
#define FOREST_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// The deep dark forest - strange and all-knowing and the only one in the world.
// Animals and plants live here, their numbers limited, but alterable.
// The forest allows you to watch it and move the time forward, step by step.

class Animal;
class Plant;
class Forest
{
    public:
        ~Forest();
        static Forest* get_instance();
        static Forest* get_instance(int na, int np, int _X, int _Y);
        static void clear_instance();

        void listen();
        void draw();
        void live();
        bool check(int x, int y);
        void move();
    private:
        Forest(); // Nobody can just take a forest and grow it on a backyard.
        static Forest* instance; // The forest - the one and the only.
        int init();
        int init(int na, int np, int _X, int _Y);

        Animal** animals;
        int n_animals;
        Plant** plants;
        int n_plants;

        int X, Y;
        sf::RenderWindow *window;

        bool key_pressed;
};

#endif // FOREST_H
