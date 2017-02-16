#pragma once

#include "ofMain.h"
#include "Bullet.hpp"
#include "LinkedList.hpp"
#include "Player.hpp"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void draw();
		void mousePressed(int x, int y, int button);
		
    private:
        LinkedList b;
        int frame;
        Player player;
};
