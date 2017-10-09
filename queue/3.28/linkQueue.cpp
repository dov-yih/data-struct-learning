//
// Created by yidafu on 2017/10/5.
//
#include <windef.h>
#include <cstdlib>
#include "linkQueue.h"
bool initQueue ( Queue &Q )
{
    //    head 表示头结点
    LNode *head = Q.rear = new LNode;
    head->next = head;
    return true;
}

bool enQueue ( Queue &Q , ElemType e )
{
    LNode *node = new LNode,
            *rear = Q.rear,
            *p;
    node->data = e;
    p = rear->next;
    node->next = p;
    rear->next = node;
    return true;
}
bool delQueue (Queue &Q, ElemType &e )
{
    if (Q.rear->next == Q.rear->next->next)
    {
        return false;
    }
    LNode *p,*to_delete;
    p = Q.rear;
    while ( p->next->next != Q.rear)
    {
        p = p->next;
    }
    e = p->next->data;
    to_delete = p->next;
    p->next = p->next->next;
    delete to_delete;
    return true;
}
