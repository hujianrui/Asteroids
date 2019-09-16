//
//  bullet.hpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/18/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#ifndef bullet_hpp
#define bullet_hpp
#include "Header.h"



class bullet{
private:
    sf::Vector2f b_Pixel;
    double angle;
    const uint8_t  r=50, g=50, b= 50;
    sf::RectangleShape shape;
    
     
public:
    const float THICKNESS=5;
    const float SPEED =10;
    const float LENGTH=20;
    const float PI = 3.14159265;
    
    
    ///contructor for connection with ship
    bullet(float x, float y , double angle_initial);
    
    ///set beginning position
    void setBeginnningPosition(sf::Vector2f input);
    
    ///read b_Pixel x
    float getBP_x();

    ///read b_Pixel y
    float getBP_y();
    ///read Beginning Angle
    float getBP_a();
    
    ///get Shape
    sf::RectangleShape getShape() {return shape;}
    
    ///bullet move to next position
    void draw(sf::RenderWindow& window);
    
    //overlaod of =
    void operator=(bullet & rhs);

};

#endif /* bullet_hpp */
