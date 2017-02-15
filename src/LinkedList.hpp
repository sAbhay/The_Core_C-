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
        LinkedList();
        ~LinkedList();
    
        void AddBullet();
        void Remove(int index);
        void Remove(Bullet& b);
        Bullet& Get(int i);
    
    int GetLength();
    
    private:
        int _length;
        Node* _firstNode;
};

#endif /* LinkedList_hpp */
