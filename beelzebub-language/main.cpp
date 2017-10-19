#include <iostream>
#include <cstring>
#include "language.h"
#include "Deque.h"
#include "Stack.h"

char beelzebubWorlds[2][6] = {"sae","tAdA"};

using namespace std;

Queue test() {
    Queue queue;
    char ch = 'A';
    queue.enQueue(ch);
    queue.enQueue(ch);
    queue.enQueue(ch);
    return queue;
}
int main() {
//    stack_test();
//    queue_test();
//    deque_test();

    char str[50] = "A(ab(efg)cd)B";
    Queue get = test();
    cin.getline( str, 50 );

    Queue *trans_result = new Queue;

    rule_one(str,trans_result);

    Queue *result = new Queue;

    rule_two(trans_result,result);


    char ch;
    while ( ! result->isEmpty() ) {
        result->delQueue(ch);
        cout << ch;
    }
    cout << endl;

    delete result;
    cin.get();
    cin.get();
    return 0;
}