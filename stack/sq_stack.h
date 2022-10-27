//
// Created by swat on 2022/10/27.
//

#ifndef REVERSE_SQ_STACK_H
#define REVERSE_SQ_STACK_H

#include "stdbool.h"

typedef struct SqStack{
    struct SqStack* next;
    void* data;
} SqStack, *SqNode;

#define StackValue(n) ((n)->data)

SqStack* initSqStack();

SqNode SqStack_pop(SqStack* s);

bool SqStack_push(SqStack* s, void* e);

bool SqStack_top(SqStack* s, void* e);

void SqlStack_delNode(SqNode n);

#endif //REVERSE_SQ_STACK_H
