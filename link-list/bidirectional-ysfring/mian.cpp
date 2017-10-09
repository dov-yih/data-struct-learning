//
// Created by yidafu on 2017/10/05.
//
//typedef struct {
//    int location;
//    int pwd;
//} person;
//typedef int ElemType;
#include <iostream>
#include "bidirectional.h"

//#define ElemType person

int main ()
{
    using namespace std;

    biLinkList list;
    ElemType elem;
    initList(list);

    int peopleNum , beginLocate;

    cout << "input people number:";
    cin >> peopleNum;
    for ( int i = 1 ; i <= peopleNum ; i ++ ) {
        cout << endl << "place, type " << i << "'s passwd:";
        cin >> elem.passwd;
        elem.locate = i;
        appendList( list, elem );
    }

    cout << "input begin passwd:";
    cin >> beginLocate;
    ysfring( list, beginLocate);
    system("pause");
    return 0;
}
