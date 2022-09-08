//
// Created by swat on 2022/8/31.
//

#ifndef ONE_SINGLYLINKEDLIST_H
#define ONE_SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode{
    int data;
    struct LNode* next;
} LNode, *LinkList;


void DumpList(LinkList l);

bool ListInsert(LinkList l, int i, int e);

bool ListDelete(LinkList l, int i, int *e);

LinkList InitLinkListHead();

LinkList InitLinkListTail();

void DestroyList(LinkList l);

#endif //ONE_SINGLYLINKEDLIST_H
