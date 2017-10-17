//
// Created by yidafu on 2017/10/15.
//

#include <iostream>
#include "language.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"


void print (ElemType e){
    std::cout << e << "|---|";
}
void stack_test(){
    Stack *s = new Stack;
    char ch = 'e';
    // 入栈测试
    s->push(ch);
    ch ++;
    s->push(ch);
    ch ++;
    s->push(ch);
    ch ++;
    s->push(ch);
    s->push(ch);
    ch ++;
    s->push(ch);
    ch ++;
    s->push(ch);
    ch ++;
    s->push(ch);

    // 遍历测试
    s->traverse(print);
    std::cout << std::endl;

    // 循环出栈测试
    while ( ! s->isEmpty() ) {
        s->pop(ch);
        printf("%c",ch) ;
    }

    // 越界删除测试
    bool test_bool = s->pop(ch);
    delete s;
}

void queue_test() {
    Queue *queue = new Queue;

//    // 空队列清空测试
//    queue->clear();

    char ch = 66;

    // 入队测试
    queue->enQueue(ch);
    ch ++;
    queue->enQueue(ch);
    ch ++;

//    // 中途析构测试
//    delete queue;

    queue->enQueue(ch);
    ch ++;
    queue->enQueue(ch);
    ch ++;

    int queue_length = queue->length();

    queue->getHead(ch);

    while ( ! queue->isEmpty() ) {
        queue->delQueue(ch);
        std::cout << ch << "\t";
    }

//    // 清除测试
//    queue->clear();

//    // 出队测试
//    queue->delQueue(ch);
//    std::cout << ch << "---";
//    queue->delQueue(ch);
//    std::cout << ch << "---";
//    queue->delQueue(ch);
//    std::cout << ch << "---";
//    queue->delQueue(ch);
//    std::cout << ch << "---";
//
//    // 删除越界测试
//    bool test_bool = queue->delQueue(ch);
//    std::cout << ch << "---";

    // 析构测试
    delete queue;
}

void deque_test() {
    Deque deque;
    char ch = 66;
    deque.enQueue(ch);
    ch ++;
    deque.enQueue(ch);
    ch ++;
    deque.enQueue(ch);
    ch ++;
    deque.enQueue(ch);
    ch ++;
    deque.enFront(ch);
    delete &deque;
}