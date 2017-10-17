//
// Created by yidafu on 2017/10/12.
//

#include <malloc.h>
#include <iostream>
#include "Stack.h"
//typedef char ElemType;

Stack::Stack(): _top(0),listSize(_INIT_LIST_SIZE_) {
    this->base = (ElemType *) malloc( _INIT_LIST_SIZE_ * sizeof(ElemType));
    if( !this->base ) {
        std::cout << "init fialed!"<<std::endl;
    }
}

Stack::~Stack() {

    delete[] this->base;
}
int Stack::length() {
    return this->_top;
}

bool Stack::push(ElemType &e) {
    if ( this->_top >= this->listSize ) {
        // 栈满重新分派空间
        ElemType *newbase = (ElemType *) realloc(this->base,( this->listSize + INCRASE_LENGTH ) * sizeof(ElemType) );
        if ( ! newbase ) {
            printf("fial to push into stack! no space now!\n");
            return false;
        }
        this->base = newbase;
        this->listSize += INCRASE_LENGTH ;
    }
    this->base[this->_top ++ ] = e;
    return true;
}
//
ElemType Stack::pop() {
//    char a = 'e';
    if( this->isEmpty() ) {
        // do nothing
    } else {
        return this->base[ -- this->_top ];
    }
}
bool Stack::pop(ElemType &e) {
    if( this->isEmpty() ) {
        return false;
    } else {
        e = this->base[ -- this->_top ];
        return true;
    }
}
bool Stack::isEmpty() {
    return this->_top == 0;
}
void Stack::clear() {
    this->_top = 0;
}
ElemType Stack::top() {
    return this->base[this->_top - 1 ];
}

void Stack::traverse(void (*visit)(ElemType)) {
    for ( int index = 0 ; index < this->_top ; index ++ ) {
        visit(this->base[index]);
    }
}