//
// Created by yidafu on 2017/10/12.
//

#ifndef BEELZEBUB_LANGUAGE_STACK_H
#define BEELZEBUB_LANGUAGE_STACK_H

#define _INIT_LIST_SIZE_ 20
#define INCRASE_LENGTH 10
#define ElemType char
;
class Stack {
private:
    ElemType *base;
    int _top;
    int listSize;
public:
    Stack();
    ~Stack();
    void clear();
    bool isEmpty();
    int length();
    ElemType top();
    bool push(ElemType &e);
    ElemType pop();
    bool pop(ElemType &e);
    void traverse(void (*visit)(ElemType));
};


#endif //BEELZEBUB_LANGUAGE_STACK_H
