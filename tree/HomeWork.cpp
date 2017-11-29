//
// Created by yidafu on 2017/11/26.
//

#include "Tree.h"

void Tree::childSwap(Node* &TNode) {
    if( TNode ) {
        this->childSwap(TNode->childNode);
        this->childSwap(TNode->nextSibling);
        Node* temp = TNode->childNode;
        TNode->childNode = TNode->nextSibling;
        TNode->nextSibling = temp;
    }
}
