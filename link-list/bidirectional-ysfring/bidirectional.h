//
// Created by yidafu on 2107/10/05.
//
#ifndef __BIDIRECTION__
#define __BIDIRECTION__

#define ElemType person

typedef struct {
    int locate;
    int passwd;
} person;

struct LNode {
    LNode *prior;
    ElemType data;
    LNode *next;
};

typedef struct {
    LNode *head;
    LNode *tail;
    int len;
} biLinkList;

int initList( biLinkList &bL );
bool insertList ( biLinkList &bL, int pos, ElemType &e );
bool appendList ( biLinkList &bL, ElemType &e);
void destroyList ( biLinkList &bL ) ;
void clearList ( biLinkList &bL );
bool isEmptyList ( biLinkList &bL );
int listLength ( biLinkList &bL );
bool getElem ( biLinkList &bL, int i, ElemType &e );
bool deleteList ( biLinkList &bL, int pos, ElemType &e );
int locateElem ( biLinkList &bL, ElemType &e,
                 bool (*compare)( ElemType &origin, ElemType &target));

// in test.cpp
void test();

// in ysfring.cpp
void ysfring (biLinkList &bL, int locatePos );
#endif// __BIDIRECTION__
