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

int Length(LinkList l);

void LocateElem(LinkList l, int e);

int GetElem(LinkList l, int i);

bool ListInsert(LinkList  l, int i, int e);

bool ListDelete(LinkList l, int i, int* e);

void PrintList(LinkList l);

bool isTail(LinkList l, LNode *node);

#endif
