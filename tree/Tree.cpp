//
// Created by yidafu on 2017/11/9.
//
#include <iostream>
#include "Tree.h"

Tree::Tree() {
    this->root = NULL;
}

Tree::~Tree() {
    this->clear( *this->root );
}

bool Tree::create( Node &toCrate ) {
    char ch;
    scanf( "%c", &ch );
    if( ch != flag ) {
        Node *newNode = new Node;
        newNode->data = ch;
        this->create( *toCrate.childNode );
        this->create( *toCrate.nextSibling );
    }
    return true;
}

void Tree::clear( Node &to_delete) {
    if( &to_delete ) {
        this->clear( *to_delete.childNode );
        this->clear( *to_delete.nextSibling );
        delete to_delete;
    }
}