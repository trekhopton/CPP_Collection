#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int d, Node* l);
    int data;
    Node* link;
};

#endif
