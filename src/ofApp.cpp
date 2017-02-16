#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    frame = 0;
    player = Player();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    frame++;
    
    if(frame >= 1.5*ofGetFrameRate())
    {
        b.AddBullet(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(mouseX, mouseY));
        frame = 0;
    }
    
    for(int i = 0; i < b.GetLength(); i++)
    {
        b.Get(i).Update();
        player.CheckIfHit(b.Get(i));
    }
    
    player.Update(mouseX, mouseY);
    
    if(player.IsDead())
    {
        ofBackground(rand() % 255, rand() % 255, rand() % 255);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    if(button == 0)
    {
        player.SetDead(false);
    }
}
