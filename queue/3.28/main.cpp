#include <iostream>
#include "linkQueue.h"
int main() {
    Queue Q;
    int get;
    initQueue(Q);
    enQueue( Q, 3 );
    enQueue( Q, 1 );
    enQueue( Q, 4 );
    delQueue( Q, get );
    delQueue( Q, get );
    delQueue( Q, get );
    return 0;
}