#include "Tree.h"

Tree::Tree(){
    root = NULL;
}

std::string Tree::getInfix(){
    std::string output;
    output = getInfix(root, output);
    return output;
}

std::string Tree::getInfix(Node* p, std::string output){
    if(p->type == 'e'){
        output = "Error";
        return output;
    }
    if(p == NULL || output == "Error"){
        return "";
    }
    if(p->full == 0){
        output = "Error";
        return output;
    }
    if(p == root){
        if(p->left == NULL){
            if(p->type == 'n'){
                output = p->data;
            } else {
                output = "Error";
                return output;
            }
        }
        else if(p->left->type == 'o'){
            if(p->data == "/" && p->right->data == "0"){
                output = "Error";
                return output;
            }
            output = getInfix(p->left, output) + " " + p->data + " " + getInfix(p->right, output);
        }
        else if(p->left->type == 'n'){
            output = p->left->data + p->data + getInfix(p->right, output);
        }
        return output;
    }
    if(p->left == NULL){
        if(p->type == 'n'){
            output = p->data;
        } else {
            output = "Error";
            return output;
        }
    }
    else if(p->left->type == 'o'){
        if(p->data == "/" && p->right->data == "0"){
            output = "Error";
            return output;
        }
        output = "(" + getInfix(p->left, output) + " " + p->data + " " + getInfix(p->right, output) + ")";
    }
    else if(p->left->type == 'n'){
        output = "(" + p->left->data + " " + p->data + " " + getInfix(p->right, output) + ")";
    }
    return output;
}

Node* Tree::insert(std::string val, Node* p) {
    if (p == NULL) {
        Node* temp = new Node;
        if(val == "*" || val == "/" || val == "+" || val == "-"){
            // operator empty
            temp->type = 'o';
            temp->full = 0;
        } else if(isdigit(val[0])) {
            // number full
            temp->type = 'n';
            temp->full = 1;
        } else {
            // error
            temp->type = 'e';
            temp->full = 1;
        }
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if(p->left == NULL){
        p->left = insert(val, p->left);
    }
    else if(p->left->full == 0){
        if(p->full ==0){
            p->left = insert(val, p->left);
        } else {
            p->type = 'e';
        }
    }
    else if(p->left->full == 1){
        if(p->full == 0){
            p->full = 1;
            p->right = insert(val, p->right);
        } else {
            p->type = 'e';
        }
    }
    return p;
}

void Tree::insert(std::string val) {
    root = insert(val, root);
}
