#include "Node.h"
#include <iostream>
#include <vector>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    Node* head;
    Node* tail;
    Node* mid;
    int length;
    void addTail(int d);
    void removeHead();
    void print();
    std::vector<int> findMid();
};

#endif
