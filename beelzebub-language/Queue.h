//
// Created by yidafu on 2017/10/12.
//

#ifndef BEELZEBUB_LANGUAGE_QUEUE_H
#define BEELZEBUB_LANGUAGE_QUEUE_H
#define ElemType char
struct Node {
    ElemType data;
    Node *next;
};

class Queue {
protected:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    void clear();
    bool isEmpty();
    int length();
//    ElemType getHead();
    bool getHead(ElemType &e);
    void enQueue(ElemType &e);
    bool delQueue();
    bool delQueue(ElemType &e);
};


#endif //BEELZEBUB_LANGUAGE_QUEUE_H
