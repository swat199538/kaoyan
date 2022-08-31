//
// Created by swat on 2022/8/31.
//

#ifndef ONE_SINGLYLINKEDLIST_H
#define ONE_SINGLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct LNode{
    int data;
    struct LNode* next;
} LNode, *LinkList;

LinkList InitList();

void DestroyList();

int ListInsert(LinkList l, int i, int e);

void DumpList(LinkList l);

#endif //ONE_SINGLYLINKEDLIST_H
