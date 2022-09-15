//
// Created by 亮王 on 2022/9/15.
//

#ifndef DLINKED_CIRCULAR_LINKED_LIST_H
#define DLINKED_CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
    int data;
    struct LNode* next;
} LNode, *LinkList;


LinkList InitList();

bool Empty(LinkList l);

bool isTail(LinkList l, LNode *node);



#endif
