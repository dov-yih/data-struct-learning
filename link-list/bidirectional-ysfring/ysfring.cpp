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
        if ( stepNum == 0 ) {
            stepNum = bL.len ;
        }
        if ( stepNum < bL.len / 2 ) {
//            current = bL.head;
            for ( currentPos = 1; currentPos < stepNum; currentPos ++ ) {
                current = current->next;
            }
        } else {
//            current = bL.tail;
            for ( currentPos = 1 ; currentPos < stepNum; currentPos ++ ) {
                current = current->prior;
            }
        }
        toDelete = current;
        current->next->prior = current->prior->next;
        current->prior->next = current->next->prior;
        current = current->next;
        cout << pos ++ << "th located :" << toDelete->data.locate << endl;
        stepNum = toDelete->data.passwd;
        delete toDelete;
        bL.len --;
    }
    bL.head = bL.tail = NULL;
}
