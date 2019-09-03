//
//  bullet.cpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/18/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#include "bullet.hpp"
#include "Header.h"

bullet::bullet(float x , float y , double angle_initial) {
    angle = angle_initial;
    b_Pixel.x = x;
    b_Pixel.y = y;
    shape.setPosition(b_Pixel);
    shape.setSize(sf::Vector2f(LENGTH, THICKNESS));
    shape.setRotation(angle);
    shape.setFillColor(sf::Color::Red);
}

void bullet::setBeginnningPosition(sf::Vector2f input) {
    b_Pixel.x = input.x;
    b_Pixel.y = input.y;
}

float bullet::getBP_x() {return b_Pixel.x;}
float bullet::getBP_y() {return b_Pixel.y;}
float bullet::getBP_a() {return angle;}

void bullet::draw(sf::RenderWindow& window){
    b_Pixel.x = b_Pixel.x +SPEED * cos(getBP_a() * 3.14159 /180);
    b_Pixel.y = b_Pixel.y +SPEED * sin(getBP_a() * 3.14159 /180);
    shape.setPosition(b_Pixel.x, b_Pixel.y);
    window.draw(shape);
}

void bullet::operator=(bullet & rhs){
    b_Pixel = rhs.b_Pixel;
    angle = rhs.angle;
    shape = rhs.shape ;
    
}



