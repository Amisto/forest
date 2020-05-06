#include "Monkey.h"
#include "Forest.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


sf::Texture* Monkey::texture = NULL;
Monkey::Monkey()
{
}

Monkey::Monkey(){
};


Monkey::Monkey(double m, double b, int _x, int _y) : Animal(m, b, _x, _y){
};

Monkey::~Monkey(){
};

void Monkey::talk(){ //Monkey's intelligence level is close to human,
                     // it already can remember three phrases, not more.
    int var = rand()%3;
    switch(var) {
        case 1:
        cout << "Who! Who! Who!" << endl;
        break;
        case 2:
        cout<< "Banano!" <<endl;
        break;
        default:
        cout<< "Aaaaaaa!" <<endl;
        break;
    }
}
void Monkey::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/monkey.png"))
            cout <<"Someone has stolen le monke!" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}
void Monkey::walk(Forest *f) { //Monkey jumps everywhere!
    bool check = false;
    int _x = x, _y = y, c = 0;
    while(!check)
    {
        _x = x, _y = y;
        bool sign_x = rand()%2;
        bool sign_y = rand()%2;
        int length = rand()%3+1;
        switch (sign_x)            //it moves like a bishop in chess
        {
            case 0: _x+=length; break;
            case 1: _x-=length; break;
        }
        switch (sign_y)
        {
            case 0: _y+=length; break;
            case 1: _y-=length; break;
        }
        check = f->check(_x, _y);
        c++;
        if (c >= 20) break;          .
    }
    x = _x, y = _y;
}