#include "LinkedList.h"

LinkedList::LinkedList(){
    head = NULL;
    length = 0;
    tail = NULL;
}

void LinkedList::addTail(int d){
    Node* temp = new Node(d, NULL);
    if(head == NULL){
        head = temp;
        tail = temp;
        mid = temp;
        length++;
        return;
    }
    tail->link = temp;
    tail = temp;
    length++;
    if(length % 2 != 0){
        mid = mid->link;
    }
    return;
}

void LinkedList::removeHead(){
    if(head == NULL){
        return;
    }
    Node* temp = head->link;
    delete head;
    head = temp;
    length--;
    if(length % 2 != 0){
        mid = mid->link;
    }
}

void LinkedList::print(){
    if(head == NULL){
        std::cout << "empty";
        return;
    }
    Node *temp = head;
    std::cout << temp->data;
    temp = temp->link;
    while(temp != NULL){
        std::cout << "->" << temp->data;
        temp = temp->link;
    }
}

std::vector<int> LinkedList::findMid(){
    std::vector<int> v;
    if(head == NULL){
        v.push_back(0);
        return v;
    }
    if(length % 2 == 0){
        v.push_back(mid->data);
        v.push_back(mid->link->data);
    } else {
        v.push_back(mid->data);
    }
    return v;
}
