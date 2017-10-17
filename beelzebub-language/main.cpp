#include <iostream>
#include <cstring>
#include "language.h"
#include "Deque.h"
#include "Stack.h"

char beelzebubWorlds[2][6] = {"sae","tAdA"};

using namespace std;
int main() {
//    stack_test();
//    queue_test();
//    deque_test();

    char ch;
    char str[50] = "A(abcd)(abcd)B";
//    cin.getline( str, 50 );

//    second_way( str );

    Queue *trans_result = new Queue;

    rule_one(str,trans_result);

    Queue *result = new Queue;

    rule_two(trans_result,result);

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