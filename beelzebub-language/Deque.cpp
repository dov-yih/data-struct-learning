//
// Created by yidafu on 2017/10/15.
//

#include "Deque.h"
Deque::Deque() : Queue() {};
bool  Deque::enFront(ElemType &e) {
    Node *node = new Node;
    node->data = e;
    node->next = this->front->next;
    this->front->next = node;
    if ( this->front == this->rear ) {
        this->rear = node;
    }

}
Deque::~Deque() {}