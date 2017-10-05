//
// Created by yidafu on 2017/10/5.
//
#include <malloc.h>
#include "bidirectional.h"
typedef int ElemType;

bool initList ( biStack &bS )
{
    bS.base = (ElemType *) malloc( BIDIRECTION_STACK_SIZE * sizeof(ElemType) );
    if (bS.base == NULL ) {
        return false;
    }
    bS.curOlder = bS.curYounger = 0;
    bS.length = 0;
    return true;
}

bool push ( biStack &bS, int direction, ElemType value )
{
    // 0 从‘前面’push，1 从‘后面’push
    if ( ( bS.curYounger + 1 == bS.curOlder ) ) {
        return false; // 空间已满
    }
    bS.base[ direction ? bS.curYounger : bS.curOlder ] = value;
    bS.length ++;
    // 得出下一次将要被push的位置
    int pushPos = !direction ? bS.curOlder - 1 : bS.curYounger + 1 ;
    // 纠正 -- < 0
    pushPos = pushPos == -1 ? 49 : pushPos ;
    // 纠正 ++ > 50
    pushPos = ( pushPos ) % BIDIRECTION_STACK_SIZE;
    !direction ? bS.curOlder = pushPos : bS.curYounger = pushPos;
    return true;
}

bool pop ( biStack &bS, int direction )
{

    // 0 从‘前面’push，1 从‘后面’push
    if ( bS.curYounger == bS.curOlder) {
        return false; // 空间已空
    }
    int popPos = !direction ? bS.curOlder + 1 : bS.curYounger - 1 ;
    // 纠正 -- < 0
    popPos = popPos == -1 ? 49 : popPos ;
    // 纠正 ++ > 50
    popPos = ( popPos ) % BIDIRECTION_STACK_SIZE;
    bS.length --;
    !direction ? bS.curOlder = popPos : bS.curYounger = popPos;
    return true;
}
