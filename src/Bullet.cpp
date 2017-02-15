//
//  Bullet.cpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#include "Bullet.hpp"

Bullet::Bullet(ofVec2f start, ofVec2f target)
{
    pos = ofVec2f(start.x, start.y);
    vel = ofVec2f(target.y, target.y);
    
    vel = vel - pos;
    vel.normalize();
    
    speed = 20;
    vel *= speed;
}

Bullet::~Bullet()
{
    delete &pos;
    delete &vel;
    delete &speed;
    delete &size;
}

void Bullet::Draw()
{
    ofDrawRectangle(pos, size, size);
}

void Bullet::Move()
{
   pos += vel;
}

void Bullet::CheckBoundaries()
{
    if(pos.x <= 0)
    {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if(pos.x >= ofGetWidth())
    {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if(pos.y <= 0)
    {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if(pos.y >= ofGetHeight())
    {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Bullet::Update()
{
    Move();
    CheckBoundaries();
    Draw();
}
