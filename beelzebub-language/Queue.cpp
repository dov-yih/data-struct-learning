//
// Created by yidafu on 2017/10/12.
//
#include <iostream>
#include "Queue.h"

Queue::Queue() {
    this->front = this->rear = new Node();
    this->rear->next = NULL;
}

void Queue::enQueue(ElemType &e) {
    Node *node = new Node;
    node->data = e;
    node->next = NULL;
    this->rear->next = node;
    this->rear = this->rear->next;
//    return false;
}

bool Queue::delQueue() {
    if ( this->front == this->rear ) {
        return false;
    }

    Node *toDelete;
    toDelete = this->front->next;
    this->front->next = this->front->next->next;
    delete toDelete;
    return true;
}

bool Queue::delQueue(ElemType &e) {
    if ( this->front == this->rear ) {
        return false;
    }

    Node *toDelete;
    toDelete = this->front->next;
    this->front->next = this->front->next->next;
    // 修正尾指针
    if ( this->front->next == NULL ) {
        this->rear = this->front;
    }
    e = toDelete->data;
    delete toDelete;
    return true;
}

void Queue::clear() {
    if ( this->front != this->rear ) {
        while (this->front->next != NULL ) {
            Node *toDelete = this->front->next;
            this->front->next = this->front->next->next;
            delete toDelete;
        }
        this->rear = this->front;
        this->rear->next = NULL;
    }
}

int Queue::length() {
    if ( this->front == this->rear ) {
        return 0;
    }
    Node *traveler = this->front->next;
    int count = 1;
    while ( traveler->next != NULL ) {
        traveler = traveler->next;
        count ++;
    }
    return count;
}

bool Queue::isEmpty( ) {
//    return this->front->next == NULL;
    return this->front == this->rear;
}


bool Queue::getHead( ElemType &e ) {
    if ( this->front == this->rear ) {
        return false;
    } else {
        e = this->front->next->data;
        return true;
    }
}
Queue::~Queue() {
    this->clear();
    delete this->front;
    this->front = this->rear = NULL;
}
