//
//  player.hpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/19/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include "Header.h"

class Ship{
private:
    double X_axis;
    double Y_axis;
    double speed;
    double angle;
    sf::ConvexShape shape;
    bool expire;
public:
    
    /// Constructor for Ship
    Ship(sf::RenderWindow& window);
    
    ///Move ship by keys of left up right down
    void move(sf::RenderWindow& window);
    
    ///Drawship on the window
    void drawship(sf::RenderWindow& window);
    
    ///Get value of X axis
    double getX(){return X_axis;}
    
    ///Get value of Y axis
    double getY(){return Y_axis;}
    
    ///Get angle of ship
    double getAngle(){return angle;}
    
    ///Get shape of ship
    sf::ConvexShape getShape() {return shape;}
    
    ///Destructor
    void crush()&{expire = true;}
    
};




#endif /* player_hpp */
