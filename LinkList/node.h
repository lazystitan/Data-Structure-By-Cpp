//
// Created by Riton on 2019/6/29.
//

#ifndef CMAKETEST_NODE_H
#define CMAKETEST_NODE_H

class Node {
private:
public:
    int value;
    Node *next;
    Node(int value, Node *next);
};

Node::Node(int value, Node *next) {
    this->value = value;
    this->next = next;
}




#endif //CMAKETEST_NODE_H
