//
// Created by zugvangg on 07.04.2020.
//

#include "Tiger.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
sf::Texture* Tiger::texture = NULL;

Tiger::Tiger()
{
}

Tiger::Tiger(double m, double b) : Animal(m, b)
{
}


Tiger::Tiger(double m, double b, int _x, int _y) : Animal(m, b, _x, _y)
{
}

Tiger::~Tiger()
{
}

void Tiger::talk()
{
    cout <<"I am a Tiger!" <<endl;
}

//Tigers are really similar to Lions...

void Tiger::setSprite()
{
    if (!texture)
    {
        texture = new sf::Texture;
        if (!texture->loadFromFile("res/Tiger.jpg"))
            cout <<"Tiger does not exist" <<endl;
    }
    s = new sf::Sprite;
    s->setTexture(*texture);
}


//Tigers roar, endlessly...
void Tiger::sound() {
    sf::SoundBuffer Buffer;//создаём буфер для звука
    Buffer.loadFromFile("TigerSound.ogg");//загружаем в него звук
    sf::Sound sound;
    sound.setBuffer(Buffer);

    while(1==1) //sorry for this
    {
        sound.play();
    }
    sound.play();


}
