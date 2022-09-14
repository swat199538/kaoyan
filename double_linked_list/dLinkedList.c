//
// Created by 亮王 on 2022/9/10.
//

#include "dLinkedList.h"

bool Empty(DLinkList l){

    return true;
}

DLinkList InitDLinkList(){
    DLinkList l = (DNode*) malloc(sizeof(DNode));
    if(l == NULL) return NULL;
    l->data = 0;
    l->next = NULL;
    l->prior = NULL;
    return l;
}

bool EmptyList(DLinkList l){
    if (l->next == NULL) return true;
    return false;
}

bool InsertNextNode(DNode *p, DNode *s){

    if (p == NULL || s == NULL) return false;

    s->next = p->next;
    if (p->next != NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;

    return true;
}

void DumpDList(DLinkList l){

    if (l->prior != NULL){
        printf("请输入头结点\n");
    }

    DNode *n = l->next;
    int i = 1;
    while (n!=NULL){
        printf("key:%d  value:%d\n", i, n->data);
        n = n->next;
        i++;
    }
}


void testInsert(){

    DLinkList l = InitDLinkList();

    DNode *s = (DNode*) malloc(sizeof(DNode));
    s->data = 1;

    DNode *w = (DNode*) malloc(sizeof(DNode));
    w->data = 2;

    DNode *a = (DNode*) malloc(sizeof(DNode));
    a->data = 3;

    DNode *t = (DNode*) malloc(sizeof(DNode));
    t->data = 4;

    InsertNextNode(l, s);
    InsertNextNode(s, w);
    InsertNextNode(w, a);
    InsertNextNode(a, t);

    DumpDList(l);
}

int main(){
    testInsert();
    return  0;
}