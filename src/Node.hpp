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

class Node
{
    public:
        Node();
        ~Node();
    
        void SetNext(Node* &n);
        void SetData();
    
};

#endif /* Node_hpp */
