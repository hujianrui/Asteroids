//
//  asteroid.cpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/19/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#include "asteroid.hpp"
#include "Header.h"

asteroid::asteroid()  {
    sf::Vector2f input;
    float index = randomNumber();
    if (index>=0 && index <0.25){
        input.x=0;
        input.y= 800 * index;
    }
    if (index>=0.25 && index <0.5){
        input.x=1500;
        input.y= 800 * index;
    }
    if (index>=0.5 && index <0.75){
        input.x=1500 * index;
        input.y= 0;
    }
    if (index>=0.75 && index <0.5){
        input.x=1500 * index;
        input.y= 600;
    }
    
    angle = MAXANGLE * index;
    speed = MAXSPEED * index+3;
    radius = MAXRADIUS;
    shape.setPosition(input);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(THICKNESS);
    b_Pixel.x=input.x;
    b_Pixel.y=input.y;

}
asteroid::asteroid(float x, float y){
    float index= randomNumber();
    angle = MAXANGLE * index;
    speed = MAXSPEED*0.5 + MAXSPEED *index;
    radius = radius_small;
    b_Pixel.x=x;
    b_Pixel.y=y;
    shape.setPosition(b_Pixel);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(THICKNESS);
}

asteroid::asteroid(float x, float y, float radius){
    float index= randomNumber();
    angle = (MAXANGLE * index+90);
    speed = MAXSPEED*0.5 + MAXSPEED *index;
    radius = radius;
    b_Pixel.x=x;
    b_Pixel.y=y;
    shape.setPosition(b_Pixel);
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(THICKNESS);
}



void asteroid::draw(sf::RenderWindow& window){
    b_Pixel.x = b_Pixel.x +speed * cos(angle * 3.14159 /180);
    b_Pixel.y = b_Pixel.y +speed * sin(angle * 3.14159 /180);
    if (b_Pixel.x<0) b_Pixel.x=1600;
    if (b_Pixel.x>1600) b_Pixel.x = 0;
    if (b_Pixel.y < 0) b_Pixel.y = 900;
    if (b_Pixel.y >900) b_Pixel.y = 0;
    shape.setPosition(b_Pixel);
    window.draw(shape);
}


void asteroid::operator=(asteroid &rhs) {
    angle = rhs.angle;
    radius = rhs.radius;
    b_Pixel = rhs.b_Pixel;
    speed = rhs.speed;
    shape = rhs.shape;
}



float randomNumber() {
    srand((unsigned)time(NULL));
    float x = rand() % 101;
    return x/100;
}
