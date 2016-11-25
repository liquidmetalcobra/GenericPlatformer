//
//  Camera.hpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//

#include <iostream>

class Camera
{
public:
    Camera();
    ~Camera();
    void update(int newX, int newY);
    
    int x;
    int y;
};
