//
//  Node.hpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Bullet.hpp"

class Node
{
    public:
        Node();
        ~Node();
    
        void    SetNext(Node* &n);
        void    SetData(Bullet& b);
        Node*   GetNext();
        Bullet& GetData();
        Bullet  GetCopy();
        void      operator=(const Node& n);
    
private:
    Bullet* _data;
    Node*     _nextNode;

};

#endif /* Node_hpp */
