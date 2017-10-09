//
// Created by yidafu on 2107/10/05.
//
#include <iostream>
#include "bidirectional.h"

int initList( biLinkList &bL )
{
    bL.head = bL.tail = NULL;
    bL.len = 0;
    return 1;
}

///
/// \param bL 双向链表
/// \param pos 插入的位置，应该是在 1 到 链表末尾的数字
/// \param e 插入的值
/// \return 插入成功 true 失败 false
bool insertList ( biLinkList &bL, int pos, ElemType &e )
{
    if ( pos < 1 ) {
        return false;
    }
    LNode *head,*tail,
          *node = new LNode;
    node->data = e;
    head = bL.head;
    tail = bL.tail;
    if ( pos == 1 ) {
        if ( bL.head == NULL ) {
            // 空表
            bL.head = bL.tail = node;
            node->prior = node->next = node;
        } else {
            // 非空表
            node->next = head;
            head->prior = node;
            bL.head = node;

            node->prior = bL.tail;
            tail->next = bL.head;
        }
    } else {
//        TODO 这里的插入边界的处理
        LNode *current = bL.head;
        int traveler = 1;
        while ( traveler < pos - 1 ) {
            current = current->next;
            traveler ++;
        }

        if ( current == bL.head ) {
            return false;
        } else {
            node->next = current->next;
            node->prior = current;
            current->next->prior = node;
            current->next = node;
        }
    }
    bL.len ++;
    return true;
}

/// 在链表末尾添加一个元素
/// \param bL
/// \param e
/// \return
bool appendList ( biLinkList &bL, ElemType &e)
{
   LNode *node = new LNode;
    node->data = e;
    if( bL.head == NULL ) {
        // 空表
        bL.head = bL.tail = node;
        node->prior = node->next = node;
    } else {
        // 非空表
        node->prior = bL.tail;
        node->next = bL.head;

        bL.tail->next = node;
        bL.head->prior = node;

        bL.tail = node;
    }
    bL.len ++;
}

/// 销毁链表
/// \param bL
void destroyList ( biLinkList &bL )
{
    LNode *traveler = bL.head,
            *todelete;
    if ( bL.head == NULL ) {
        return;
    }
    while ( traveler != bL.tail ) {
        todelete = traveler;
        traveler = traveler->next;
        delete todelete;
    }
    delete bL.tail;
    bL.tail = bL.head = NULL;
    bL.len = 0;
}

/// 清空链表
/// \param bL
void clearList ( biLinkList &bL )
{
    destroyList( bL );
}

/// 判断链表是否为空
/// \param bL
/// \return
bool isEmptyList ( biLinkList &bL )
{
    return bL.head == NULL;
}

/// 查询链表长度
/// \param bL
/// \return 链表长度值
int listLength ( biLinkList &bL )
{
    return bL.len;
//    if ( ! bL.head ) {
//        return 0;
//    }
//    int len = 1;
//    LNode *traveler = bL.head;
//    while ( traveler != bL.tail ) {
//        traveler = traveler->next;
//        len ++;
//    }
//    return len;
}

/// 获得合法的指定位置元素
/// \param bL
/// \param pos  指定的位置，1 到 length
/// \param e 返回的元素
/// \return
bool getElem ( biLinkList &bL, int pos , ElemType &e )
{
    if ( pos  < 1 || ! bL.head || pos  > bL.len ) {
        return false;
    }
    LNode *traveler = bL.head;
    if ( pos  == 1 ) {
        e = traveler->data;
    } else {
        traveler = traveler->next;
        int travelerPos = 2;
        while ( traveler != bL.head && travelerPos < pos  ) {
            traveler = traveler->next;
            travelerPos ++;
        }
//        if ( traveler == bL.head ) {
//            return  false;
//        }
        e = traveler->data;
    }
    return true;
}

/// 删除指定位置的元素
/// \param bL
/// \param pos 删除元素的位置
/// \param e 删除的元素的值
/// \return
bool deleteList ( biLinkList &bL, int pos, ElemType &e )
{
    if ( pos < 1 || ! bL.head || pos > bL.len ) {
        return false;
    }
    if ( pos == 1 ) {

        e = bL.head->data;

        if ( bL.len == 1 ) {
            // 删除位置为 1，表长也为 1
            delete bL.head;
            bL.head = bL.tail = NULL;
        } else {
            // 删除位置为 1，表长不为一
            LNode *toDelelte = bL.head;

            bL.head = bL.head->next;
            bL.head->prior = bL.tail;
            bL.tail->next = bL.head;

            delete toDelelte;
        }
    } else {
        LNode *traveler = bL.head;
        int travelerPos = 1;
        while ( traveler != bL.tail && travelerPos < pos - 1 ) {
            traveler = traveler->next;
            travelerPos ++;
        }
        if ( traveler == bL.tail ) {
            return  false;
        } else {
            LNode *toDelete = traveler->next;
            e = toDelete->data;
            traveler->next = toDelete->next;
            traveler->next->prior = traveler;
            if ( toDelete == bL.tail ) {
                bL.tail = traveler;
//                bL.head = traveler;
            }
            delete toDelete;
        }
    }
    bL.len --;
    return true;
}

/// 查看某一指定值是否存在
/// \param bL
/// \param e 要查找的值
/// \param compare 查找值与链表里面的值是否相等的比较函数
/// \return 存在返回索引，不存在返回 0
int locateElem ( biLinkList &bL, ElemType &e,
                 bool (*compare)( ElemType &origin, ElemType &target))
{
    int comparePos = 0;
    LNode *compareElem = bL.head;
    while( comparePos < bL.len && !compare(e,compareElem->data ) ) {
        comparePos ++;
        compareElem = compareElem->next;
    }
    if ( compareElem != bL.head ) {
        return ++ comparePos;
    }
    return 0;

}