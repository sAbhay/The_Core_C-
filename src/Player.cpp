//
//  Player.cpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/16/17.
//
//

#include "Player.hpp"

Player::Player()
{
    pos.set(0, 0);
    size = 15;
    
    dead = false;
}

Player::~Player()
{
    
}

void Player::Draw(float x, float y)
{
    ofSetColor(255);
    pos.set(x, y);
    ofDrawCircle(pos.x, pos.y, size);
}

void Player::CheckBoundaries()
{
    if(pos.x <= size/2)
    {
        pos.x = size/2;
    }
    
    if(pos.x >= ofGetWidth() - size/2)
    {
        pos.x = ofGetWidth() - size/2;
    }
    
    if(pos.y <= size/2)
    {
        pos.y = size/2;
    }
    
    if(pos.y >= ofGetHeight() - size/2)
    {
        pos.y = ofGetHeight() - size/2;
    }
}

void Player::Update(float x, float y)
{
    Draw(x, y);
    CheckBoundaries();
}

void Player::CheckIfHit(Bullet b)
{
    ofVec2f bPos = b.GetPos();
    float bSize = b.GetSize();
    
    if(pos.distance(bPos) < bSize + size)
    {
        dead = true;
    }
}
