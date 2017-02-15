//
//  Node.cpp
//  LinkedListProject
//
//  Created by Abhay Singhal on 2/15/17.
//
//

#include "Node.hpp"

Node::Node(ofVec2f start, ofVec2f target)
{
    _nextNode = nullptr;
    _data = new Bullet(start, target);
}

Node::~Node()
{
    _nextNode = nullptr;
    delete _nextNode;
    delete _data;
}

Node* Node::GetNext()
{
    return _nextNode;
}

Bullet& Node::GetData()
{
    return *_data;
}

Bullet Node::GetCopy()
{
    return *_data;
}

void Node::SetNext(Node* &n)
{
    if(!_nextNode)
    {
        _nextNode = n;
        return;
    }
}

void Node::SetData(Bullet& b)
{
    Bullet* garbage = _data;
    _data = &b;
    delete garbage;
}
