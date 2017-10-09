//
// Created by yidafu on 2017/10/5.
//
typedef int ElemType;
#ifndef BIDIRECTIONAL_STACK_BIDIRECTIONAL_H
#define BIDIRECTIONAL_STACK_BIDIRECTIONAL_H
typedef struct {
    ElemType *base;
    int curOlder;  // 双向栈‘开头’处的栈顶游标
    int curYounger;  // 双向栈‘结尾’处的栈顶游标
    int length;
} biStack;
#define BIDIRECTION_STACK_SIZE 50

bool initList ( biStack &bS );
bool push ( biStack &bS, int direction, ElemType value );
bool pop ( biStack &bS, int direction );
#endif BIDIRECTIONAL_STACK_BIDIRECTIONAL_H
