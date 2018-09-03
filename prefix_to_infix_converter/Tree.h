#ifndef TREE_H
#define TREE_H
#include <iostream>

struct Node {
    std::string data;
    char type;
    bool full;
    Node* left;
    Node* right;
};


class Tree {
    public:
        Tree();
        std::string getInfix();
        std::string getInfix(Node*, std::string);
        void insert(std::string);
        Node* insert(std::string, Node*);
    private:
        Node* root;
};

#endif
