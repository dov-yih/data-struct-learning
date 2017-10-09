//
// Created by yidafu on 2017/10/7.
//
#include <iostream>
#include "bidirectional.h"

using namespace std;


bool myCompare(ElemType &origin, ElemType &target ) {
//    return origin == target;
}

void test()
{

    person val = {3,4};
    ElemType get;
    biLinkList list;

    initList(list);
//    destroyList(list);

    appendList(list,val);

    insertList(list,1,val );
    insertList(list,1,val );
    insertList(list,1,val );
    cout << listLength(list) << endl;
    insertList(list,3,val );
    insertList(list,5,val );

    appendList(list,val);

    cout << listLength(list) << endl;

    appendList(list,val);
    appendList(list,val);
    int test = locateElem(list, get, myCompare );
    deleteList(list,listLength(list),get);

    getElem(list, 10, get);

    cout << isEmptyList(list);

    destroyList(list);
}
