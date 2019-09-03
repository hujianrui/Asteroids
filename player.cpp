//
//  player.cpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/19/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#include "player.hpp"


Ship::Ship(sf::RenderWindow& window){
    /// create an empty shape
    // resize it to 3 points
    shape.setPointCount(3);
    // define the points
    shape.setPoint(0, sf::Vector2f(0, 0));
    shape.setPoint(1, sf::Vector2f(10, 30));
    shape.setPoint(2, sf::Vector2f(-10, 30));
    shape.setFillColor(sf::Color::Black);
    // set a 3-pixel wide orange outline
    shape.setOutlineThickness(3);
    shape.setOutlineColor(sf::Color::Green);
    speed = 0;
    angle = 270;
    expire = false;
    // set the absolute position of the entity
    X_axis = window.getSize().x/2;
    Y_axis = window.getSize().y/2;
    shape.setPosition((int)X_axis, (int)Y_axis);
    shape.setRotation(0);
}


void Ship::move(sf::RenderWindow& window){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && angle > 0){
        angle-=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && angle == 0){
        angle = 360;
        angle -=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && angle < 360) {
        angle +=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && angle == 360) {
        angle = 0;
        angle +=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && speed < 100){
        speed++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && speed > 0){
        speed--;
    }
    X_axis = X_axis + speed/5 * cos(angle*3.14159265/180);
    Y_axis = Y_axis + speed/5 * sin(angle*3.14159265/180);
    shape.setRotation(angle-270);
    shape.setPosition(X_axis, Y_axis);
}

void Ship::drawship(sf::RenderWindow& window){
    if(expire){
        window.clear(sf::Color::Black);
    }else{
        if(X_axis > window.getSize().x){
            X_axis -= window.getSize().x;
        }
        if(X_axis < 0){
            X_axis += window.getSize().x;
        }
        if(Y_axis > window.getSize().y){
            Y_axis -= window.getSize().y;
        }
        if(Y_axis < 0){
            Y_axis += window.getSize().y;
        }
        window.draw(shape);
    }
}
