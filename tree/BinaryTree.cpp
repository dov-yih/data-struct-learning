//
// Created by yidafu on 2017/11/26.
//

#include "BinaryTree.h"
#include <queue>
using namespace std;
void BinaryTree::levelTraverse(void (* visit)(ElemType &e)){
    queue <Node *> level;
    level.push(this->root);
    while( ! level.empty() ) {
        Node* front = level.front();
        level.pop();
        if( front ) {
            level.push( front->childNode );
            level.push( front->nextSibling );
            visit( front->data );
        }
    }
}