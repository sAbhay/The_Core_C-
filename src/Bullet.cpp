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
    vel = ofVec2f(target.x, target.y);
    
    vel = vel - pos;
    vel.normalize();
    
    speed = 10;
    vel *= speed;
    
    size = 10;
    colour = ofColor(255);
}

void Bullet::Draw()
{
    ofSetColor(colour);
    ofDrawRectangle(pos.x, pos.y, size, size);
}

void Bullet::Move()
{
   pos += vel;
}

void Bullet::CheckBoundaries()
{
    if(pos.x <= size/2)
    {
        pos.x = size/2;
        vel.x *= -1;
    }
    
    if(pos.x >= ofGetWidth() - size/2)
    {
        pos.x = ofGetWidth() - size/2;
        vel.x *= -1;
    }
    
    if(pos.y <= size/2)
    {
        pos.y = size/2;
        vel.y *= -1;
    }
    
    if(pos.y >= ofGetHeight() - size/2)
    {
        pos.y = ofGetHeight() - size/2;
        vel.y *= -1;
    }
}

void Bullet::Update()
{
    Move();
    CheckBoundaries();
    Draw();
}
