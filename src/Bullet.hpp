//
//  Bullet.hpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "ofMain.h"

class Bullet
{
    public:
        Bullet(ofVec2f start, ofVec2f target);
        Bullet();
        ~Bullet();
    
        ofVec2f GetPos();
        void Update();
    
    
    private:
        ofVec2f pos;
        ofVec2f vel;
        float size;
        float speed;
        void Draw();
        void Move();
        void CheckBoundaries();
};

#endif /* Bullet_hpp */
