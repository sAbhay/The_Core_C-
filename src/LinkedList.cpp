//
//  LinkedList.cpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    _length = 1;
    _firstNode = new Node(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(0, 0));
}

LinkedList::~LinkedList()
{
    int maxLength = _length - 1;
    
    for(int i = maxLength; i > 0; i--)
    {
        Remove(i);
    }
    delete _firstNode;
}

void LinkedList::AddBullet(ofVec2f start, ofVec2f target)
{
    Node* currentNode = _firstNode;
    
    while(currentNode -> GetNext())
    {
        currentNode = currentNode -> GetNext();
    }
    
    Node* newNode = new Node(start, target);
    currentNode -> SetNext(newNode);
    _length++;
    newNode = 0;
    delete newNode;
}

void LinkedList::Remove(int index)
{
    assert(index >= 0 && index < _length);
    
    Node* currentNode = _firstNode;
    Node* previousNode = _firstNode;
    int i = 0;
    while(currentNode != NULL)
    {
        if(i == index)
        {
            if(i == 0)
            {
                Node* garbage = _firstNode;
                _firstNode = NULL;
                delete garbage;
            }
            else
            {
                Node* nextNode = currentNode -> GetNext();
                previousNode -> SetNext(nextNode);
                delete currentNode;
            }
            _length--;
            break;
        }
        
        previousNode = currentNode;
        currentNode = currentNode -> GetNext();
        i++;
    }
}

Bullet& LinkedList::Get(int i)
{
    assert(i >= 0 && i < _length);
    
    int j = 0;
    Node* n = _firstNode;
    
    while(n != NULL)
    {
        if(i == j)
        {
            return n -> GetData();
        }
        
        n = n -> GetNext();
        j++;
    }
}
