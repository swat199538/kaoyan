//
// Created by 亮王 on 2022/9/10.
//

#ifndef SINGLYLINKEDLIST_DLINKEDLIST_H
#define SINGLYLINKEDLIST_DLINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prior;
} DNode, *DLinkList;


bool EmptyList(DLinkList l);

DLinkList InitDLinkList();

bool InsertNextNode(DNode *p, DNode *s);

bool InsertPriorNode(DNode *p, DNode *s);

bool DeleteNextDNode(DNode *p);

DNode* GetElement(DLinkList l, int index);

void DumpDList(DLinkList l);

void DestroyList(DLinkList l);


#endif //SINGLYLINKEDLIST_DLINKEDLIST_H
