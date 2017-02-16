//
//  Player.hpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/16/17.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Bullet.hpp"

class Player
{
    public:
        Player();
        ~Player();
    
        void Update(float x, float y);
        void CheckIfHit(Bullet bullet);
    
        ofVec2f GetPos() { return pos; }
        float GetSize() { return size; }
        Boolean IsDead() { return dead; }
    
        void SetDead(bool d) { dead = d; }
    
    private:
        ofVec2f pos;
        float size;

        bool dead;
    
        void Draw(float x, float y);
        void CheckBoundaries();
};

#endif /* Player_hpp */
