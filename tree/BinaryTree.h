//
// Created by yidafu on 2017/11/26.
//

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H


#include "Tree.h"

class BinaryTree: public Tree {
public:
    void levelTraverse(void (* visit)(ElemType &e));
};


#endif //TREE_BINARYTREE_H
