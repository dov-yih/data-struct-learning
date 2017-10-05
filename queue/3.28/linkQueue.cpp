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
            *head = Q.rear,
            *p;
    node->data = e;
    p = head->next;
    node->next = p;
    head->next = node;
    return true;
}
bool delQueue (Queue &Q, ElemType &e )
{
    if (Q.rear->next == Q.rear->next->next)
    {
        return false;
    }
    LNode *p,*to_free;
    p = Q.rear;
    while ( p->next->next != Q.rear)
    {
        p = p->next;
    }
    e = p->next->data;
    to_free = p->next;
    p->next = p->next->next;
    free(to_free);
    return true;
}