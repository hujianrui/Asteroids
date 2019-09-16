//
//  collision.hpp
//  FinalProject
//
//  Created by Rongmin Jin on 9/18/18.
//  Copyright © 2018 Rongmin Jin. All rights reserved.
//

#ifndef collision_hpp
#define collision_hpp
#include "Header.h"
///template to check collision for 2 objects
template <typename T, typename U>
bool checkCollision(T T1, U T2) {
    return (T1.getGlobalBounds().intersects(T2.getGlobalBounds()));
}

#endif /* collision_hpp */
