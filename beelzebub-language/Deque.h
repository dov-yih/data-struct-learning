//
// Created by yidafu on 2017/10/15.
//

#ifndef BEELZEBUB_LANGUAGE_DEQUE_H
#define BEELZEBUB_LANGUAGE_DEQUE_H


#include "Queue.h"


/// 在队列的基础上增加一种在队首插入的操作
class Deque: public Queue {
public:
    Deque();
    bool enFront(ElemType &e);
    ~Deque();
};


#endif //BEELZEBUB_LANGUAGE_DEQUE_H
