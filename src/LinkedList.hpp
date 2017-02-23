//
//  LinkedList.hpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include "Node.hpp"
#include "Bullet.hpp"

class LinkedList
{
    public:
        LinkedList(ofVec2f start, ofVec2f target);
        ~LinkedList();
    
        void AddBullet(ofVec2f start, ofVec2f target);
        void Remove(int index);
        void Remove(Bullet& b);
        Bullet& Get(int i);
        void Clear();
    
    int GetLength() { return _length; }
    
    private:
        int _length;
        Node* _firstNode;
};

#endif /* LinkedList_hpp */
