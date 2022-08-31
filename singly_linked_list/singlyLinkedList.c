//
// Created by swat on 2022/8/31.
//

#include "singlyLinkedList.h"


LinkList InitList(){
    LinkList l = (LNode*) malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;
    return l;
}

void DestroyList(LinkList l){
    LNode* node = l->next;
    while (node){
        LNode* next = node->next;
        free(node);
        node = next;
    }
    free(l);
}

int ListInsert(LinkList l, int i, int e){
    LNode *p = l;

    int j = 0;

    while (p && (j < i-1)){
        p = p->next;
        j++;
    }

    if(!p || (j > i-1)) return 0;

    LNode *c = (LNode*)malloc(sizeof(LNode));
    c->data = e;
    c->next = p->next;
    p->next = c;

    return 1;
}

void DumpList(LinkList l){
    LNode *node = l->next;
    int i = 0;
    while (node){
        printf("key:%d, value:%d\n", i+1, node->data);
        node = node->next;
        i++;
    }
}

int main(){

    LinkList l = InitList();

    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);
    ListInsert(l, 1, 0);

    DumpList(l);

    DestroyList(l);

    return 0;
}