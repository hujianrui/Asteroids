

#ifndef asteroid_hpp
#define asteroid_hpp
#include "Header.h"

class asteroid {
private:
    sf::Vector2f b_Pixel;
    
    sf::CircleShape shape;
    float angle =0 , radius =0 ;
    const float THICKNESS= 3;
    const float MAXSPEED = 8;
    const float MAXRADIUS= 40;
    const float MAXANGLE = 360;
    const float PI = 3.14159265;
    float speed = 0;
    const float radius_small= 20;

public:
    bool expire = false;
    ///constructor for asteroid
    asteroid ();

    ///constructor for a small asteroid with random angle
    asteroid(float x, float y);
    
    asteroid(float x, float y, float radius);
    
    ///draw shape on the window
    void draw(sf::RenderWindow& window);

    ///destructor
    void crush()&{expire = true;}
    
    ///get Shape
    sf::CircleShape getShape() {return shape;}
    
    //get X of shape
    float getX() {return b_Pixel.x;}
    
    //get Y of shape
    float getY() {return b_Pixel.y;}
    
    void operator=(asteroid &rhs);
    
    
};

///get a random number between 0 ~ 1
float randomNumber();





#endif /* asteroid_hpp */
