//
// Created by yidafu on 2017/10/5.
//

#ifndef INC_3_28_LINKQUEUE_H
#define INC_3_28_LINKQUEUE_H
typedef int ElemType;
struct LNode {
    ElemType data;
    LNode *next;
};
typedef struct {
//    LNode *head;
    LNode *rear;
} Queue;

bool initQueue ( Queue &Q );
bool enQueue ( Queue &Q , ElemType e );
bool delQueue (Queue &Q, ElemType &e );
#endif //INC_3_28_LINKQUEUE_H
