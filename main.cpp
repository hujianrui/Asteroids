//
//  main.cpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/18/18.
///  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[]) {
    
    
    sf::RenderWindow window(sf::VideoMode(1600,900), "My Game");
    window.setFramerateLimit(30);

    
    //        sf::sleep(sf::seconds(0.1));
    
    sf::Time elapsedTime , elapsedTime1;
    sf::Clock clock;
    
//Initialazition of the world
    
    std::vector<asteroid> asteroids, asteroids_small;
    std::vector<bullet> bullets;
    
    
    for (int i = 0 ; i < 3 ; ++ i) {
        asteroid temp;
        asteroids.push_back(temp);
    }
    
    Ship ship1(window);
    
//Music and sound
    
    sf::Music music;
    if (!music.openFromFile("starwars.ogg")){
        return -1; // error
    }
    music.play();
    
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Gun+Silencer.wav")){
        return -1; // error
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    
//    system("pause");
    
//Texture and Sprite
    
    sf::Texture texture;
    if (!texture.loadFromFile("stars.png")){
        return -1; // error// error...
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255,255,255,255));

//Text and font
    sf::Font font;
    if (!font.loadFromFile("happytimes.ttf"))
        return 10;
    
    int s2 = 0;  //scores
    std::string  s1 = std::to_string(s2);
    
    
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    
    // set the string to display
    text.setString(s1);
    
    // set the character size
    text.setCharacterSize(48); // in pixels, not points!
    
    // set the color
    text.setFillColor(sf::Color::Yellow);

    
    sf::Text text2;
    text2.setFont(font); // font is a sf::Font
    
    // set the string to display
    text2.setString("Lifes :");
    
    // set the character size
    text2.setCharacterSize(48); // in pixels, not points!
    
    // set the color
    text2.setFillColor(sf::Color::Yellow);
    text2.setPosition(1400, 0);
    
    int ships_counter =5;
    
    std::string  s3 = std::to_string(ships_counter);
    sf::Text text3;
    text3.setFont(font); // font is a sf::Font
    
    // set the string to display
    text3.setString(s3);
    
    // set the character size
    text3.setCharacterSize(48); // in pixels, not points!
    
    // set the color
    text3.setFillColor(sf::Color::Yellow);
    text3.setPosition(1550, 0);
    
    
    //Game loop
    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)){
            
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Space:
                            bullet temp(ship1.getX(),ship1.getY(),ship1.getAngle());
                            bullets.push_back(temp);
                            sound.play();
                            break;
                            }
               break;
            }
        }
        sf::Time frametime=clock.restart();
        elapsedTime+= frametime;
    
        if (elapsedTime>sf::milliseconds(2000)){
            asteroid temp;
            asteroids.push_back(temp);
            elapsedTime= sf::milliseconds(0);
        }
    
        //Big asteroids vs bullet collision check
        for (int i=bullets.size()-1 ; i >=0 ; --i)
            for (int j= asteroids.size()-1; j >= 0; --j)
                if (checkCollision(bullets[i].getShape(), asteroids[j].getShape())){
                    
                    
                    float x = asteroids[j].getX();
                    float y = asteroids[j].getY();

                    for (int m = j; m <asteroids.size()-1  ;++m)
                        asteroids[m]=asteroids[m+1];
                    asteroids.pop_back();

                    for (int n = i; n <bullets.size()-1  ;++n)
                        bullets[n]=bullets[n+1];
                    bullets.pop_back();
                    
                    s2=s2 +10;
                    std::string  s1 = std::to_string(s2);
                    text.setString(s1);
                    
                    asteroid temp1(x,y);
                    asteroids_small.push_back(temp1);
                    asteroid temp2(x,y,20);
                    asteroids_small.push_back(temp2);
                    break;
                }
        
        
        //Small asteroids vs bullet collision check
        for (int i=bullets.size()-1 ; i >=0 ; --i)
            for (int j= asteroids_small.size()-1; j >= 0; --j)
                if (checkCollision(bullets[i].getShape(), asteroids_small[j].getShape())){
                    
                    for (int m = j; m < asteroids_small.size()-1  ;++m)
                        asteroids_small[m]=asteroids_small[m+1];
                    asteroids_small.pop_back();
                    
                    for (int n = i; n < bullets.size()-1  ;++n)
                        bullets[n]=bullets[n+1];
                    bullets.pop_back();
                    
                    s2=s2 +30;
                    std::string  s1 = std::to_string(s2);
                    text.setString(s1);
                    break;
                }
        
        //Small asteroids vs ship collision check
        for (int i = asteroids_small.size()-1 ; i >=0 ; --i)
            
            if (checkCollision(ship1.getShape(), asteroids_small[i].getShape())){
                
                for (int m = i; m <asteroids_small.size()-1  ;++m) {
                    asteroids[m]=asteroids_small[m+1];
                }
                asteroids_small.pop_back();
                
                ships_counter--;
                break;
            }
        
        
        //asteroids vs ship collision check
        for (int i = asteroids.size()-1 ; i >=0 ; --i)
            
            if (checkCollision(ship1.getShape(), asteroids[i].getShape())){
                
                for (int m = i; m <asteroids.size()-1  ;++m) {
                    asteroids[m]=asteroids[m+1];
                }
                asteroids.pop_back();
                
                ships_counter--;
                break;
            }
        
        std::string  s3 = std::to_string(ships_counter);
        text3.setString(s3);
       
        
        
        ship1.move(window);
    
    //Draw world and display
        
        window.clear(sf::Color::Black);
        
        window.draw(sprite);
        
        for (int i = 0; i< asteroids.size() ; ++i){
            asteroids[i].draw(window);
        }
        
        for (int i = 0; i< asteroids_small.size() ; ++i){
            asteroids_small[i].draw(window);
        }
        for (int i = 0; i< bullets.size() ; ++i)
            bullets[i].draw(window);
        
        ship1.drawship(window);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.display();
        
        
        
        if (ships_counter <= 0 )
            break;
    }
    
    //End Screen
    
    sf::Text text1;
    text1.setFont(font); // font is a sf::Font
    
    // set the string to display
    text1.setString("Game Over");
    
    // set the character size
    text1.setCharacterSize(100); // in pixels, not points!
    
    // set the color
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(600, 320);
    
    window.clear(sf::Color::Black);
    window.draw(sprite);
    window.draw(text1);
    window.display();
    sf::sleep(sf::seconds(3));

    return 0;
}
