//
// Created by 亮王 on 2022/9/10.
//

#include "dLinkedList.h"


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

bool InsertPriorNode(DNode *p, DNode *s){

    //头节点不允许前插操作
    if (p == NULL || s == NULL || p->prior == NULL) return false;

    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    s->next = p;

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

bool DeleteNextDNode(DNode *p){
    if (p == NULL || p->next == NULL) return false;
    DNode *tmp = p->next;
    p->next = tmp->next;
    if (tmp->next != NULL){
        tmp->next->prior = p;
    }
    free(tmp);
    return true;
}

void DestroyList(DLinkList l){
    DNode *p = l->prior;
    DNode *n = l->next;
    while (p != NULL || n != NULL){
        if (p != NULL){
            DNode *tmp = p;
            p = p->prior;
            free(tmp);
        }
        if (n != NULL){
            DNode *tmp2 = n;
            n = n->next;
            free(tmp2);
        }
    }
    free(l);
}

void testNextInsert(){

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

void testPriorInsert(){

    DLinkList l = InitDLinkList();

    DNode *s = (DNode*) malloc(sizeof(DNode));
    s->data = 4;

    InsertNextNode(l, s);

    DNode *w = (DNode*) malloc(sizeof(DNode));
    w->data = 3;

    InsertPriorNode(s, w);

    DNode *a = (DNode*) malloc(sizeof(DNode));
    a->data = 2;

    InsertPriorNode(w, a);

    DNode *t = (DNode*) malloc(sizeof(DNode));
    t->data = 1;

    InsertPriorNode(a, t);

    DumpDList(l);
}

void testDel(){

    DLinkList l = InitDLinkList();

    DNode *a = (DNode*) malloc(sizeof(DNode));
    a->data = 1;

    DNode *b = (DNode*) malloc(sizeof(DNode));
    b->data = 2;

    DNode *c = (DNode*) malloc(sizeof(DNode));
    c->data = 3;

    InsertNextNode(l, a);
    InsertNextNode(a, b);
    InsertNextNode(b, c);

    DumpDList(l);

    DeleteNextDNode(a);

    DumpDList(l);

}

void testDestroy(){

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

    DestroyList(w);
}

int main(){
    testDestroy();
    return  0;
}