//
// Created by swat on 2022/10/27.
//

#include "sq_stack.h"
#include "stdlib.h"

/**
 * 初始化栈
 *
 * @return
 */
SqStack* initSqStack(){
    SqStack* s = malloc(sizeof(SqStack));
    s->data = NULL;
    s->data = NULL;
    return s;
}

bool SqStack_push(SqStack* s, void* e){
    SqNode n = malloc(sizeof(SqStack));
    SqNode tmp = s->next;
    n->data = e;
    n->next = tmp;
    s->next = n;
    return true;
}

SqNode SqStack_pop(SqStack* s){
    if(s->next == NULL) return NULL;
    SqNode tmp = s->next;
    s->next = tmp->next;
    return tmp;
}

void SqlStack_delNode(SqNode n){
    free(n);
}