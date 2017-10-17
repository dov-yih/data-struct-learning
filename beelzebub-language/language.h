//
// Created by yidafu on 2017/10/15.
//

#ifndef BEELZEBUB_LANGUAGE_LANGUAGE_H_H
#define BEELZEBUB_LANGUAGE_LANGUAGE_H_H

#include "Deque.h"


// unit_test.cpp
void stack_test();
void queue_test();
void deque_test();


// language_rules.cpp
void rule_one(char *str,Queue *trans_result);
char * rule_one_v1(char &beelzebubWorld);
void rule_two(Queue *trans_result,Queue *result);
void second_way( char *str );

#endif //BEELZEBUB_LANGUAGE_LANGUAGE_H_H
