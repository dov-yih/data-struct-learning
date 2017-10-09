//
// Created by yidafu on 2017/10/7.
//
#include <iostream>
#include "bidirectional.h"
using namespace std;

bool equal ( ElemType &origin, ElemType &target )
{
    return ( ( origin.locate == target.locate )
             && ( origin.passwd = target.passwd ) );
}
void ysfring (biLinkList &bL, int stepNum )
{
    LNode *current = bL.head, *toDelete ;
    int currentPos,
        pos = 1;
    ElemType *Elem;
    while (bL.len > 0 ) {
        stepNum = stepNum % bL.len;

        // 如果 stepNum == 1 ，那就是当前位置的指针被删除
        // > 1 的话就是，再往前面 stepNum - 1 个

        // 找到下一个要被删除的指针位置
        if ( stepNum < bL.len / 2 && stepNum != 0 ) {
            // 对 stepNum 不处理
            for ( currentPos = 1; currentPos < stepNum; currentPos ++ ) {
                current = current->next;
            }
        } else {
            // 反向的话要对 stepNum 进行处理
            // 如果 stepNum == 0
            stepNum = stepNum != 0 ? bL.len - stepNum : 0;
//            stepNum = bL.len - stepNum;

            for ( currentPos = 0 ; currentPos <= stepNum; currentPos ++ ) {
                current = current->prior;
            }
        }

        // 删除这个不幸的节点
        toDelete = current;
        current->next->prior = current->prior;
        current->prior->next = current->next;
        current = current->next;
        cout << pos ++ << "th located :" << toDelete->data.locate << endl;
        stepNum = toDelete->data.passwd;
        delete toDelete;
        bL.len --;
    }
    bL.head = bL.tail = NULL;
}
