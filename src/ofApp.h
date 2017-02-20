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
        void pSetHSV(float h, float s, float v, float a);
		
    private:
        LinkedList b = LinkedList(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(mouseX, mouseY));
        int frame;
        Player player;
};
