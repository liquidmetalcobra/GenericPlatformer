//
//  Camera.cpp
//  GenericPlatformer
//
//  Created by Sasha Han on 11/24/16.
//
//

#include "Camera.hpp"


Camera::Camera()
{
    x = 0;
    y = 0;
}
Camera::~Camera()
{
    
}
void Camera::update(int newX, int newY)
{
    x = newX;
    y = newY;
}