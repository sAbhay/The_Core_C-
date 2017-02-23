#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    frame = 1.5 * ofGetFrameRate();
    count = 0;
    player = Player();
    
    colourMode = (int) rand() % 6;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);

    frame++;
    if(!player.IsDead()) count++;
    
    if(frame >= 1.5*ofGetFrameRate())
    {
        if(!player.IsDead()) b.AddBullet(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(mouseX, mouseY));
        frame = 0;
    }
    
//    StringSize();
    ofDrawBitmapString((int) (count/ofGetFrameRate()), ofGetWidth()/1.1, ofGetHeight()/10);
    
    for(int i = 0; i < b.GetLength(); i++)
    {
        b.Get(i).Update();
        player.CheckIfHit(b.Get(i));
        
        ofVec2f p[3];
        p[0] = ofVec2f(b.Get(i).GetPos());
        p[1] = p[0];
        p[2] = p[1];
        
        for(int j = 0; j < b.GetLength(); j++)
        {
            if(i != j)
            {
                ofVec2f p1 = b.Get(i).GetPos();
                ofVec2f p2 = b.Get(j).GetPos();
            
                if(ofDist(p1.x, p1.y, p2.x, p2.y) <= 300)
                {
                    if(p[1] != p[0])
                    {
                        p[2] = b.Get(j).GetPos();
                    }
                    else
                    {
                        p[1] = b.Get(j).GetPos();
                    }
                }
            }
        }
        
        switch(colourMode)
        {
            case 0: ofSetColor(0.0f , 255.0f, p[0].x/ofGetWidth() * 255.0f, 25.0f);
            break;
            
            case 1: ofSetColor(255.0f , 0.0f, p[0].x/ofGetWidth() * 255.0f, 25.0f);
            break;
            
            case 2: ofSetColor(p[0].x/ofGetWidth() * 255.0f , 255.0f, 0.0f, 25.0f);
            break;
            
            case 3: ofSetColor(p[0].x/ofGetWidth() * 255.0f , 0.0f, 255.0f, 25.0f);
            break;
            
            case 4: ofSetColor(255.0f , p[0].x/ofGetWidth() * 255.0f, 0.0f, 25.0f);
            break;
            
            case 5: ofSetColor(0.0f , p[0].x/ofGetWidth() * 255.0f, 255.0f, 25.0f);
            break;
        }
    
        ofDrawTriangle(p[0].x, p[0].y, p[1].x, p[1].y, p[2].x, p[2].y);
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
        
        colourMode = (int) rand() % 6;
        
//        b.Clear();

        b.Remove(1);
    }
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        colourMode = (int) rand() % 6;
    }
}
