//
// Created by swat on 2022/8/31.
//

#include "singlyLinkedList.h"


void DumpList(LinkList l){
    LNode *node = l->next;
    int i = 0;
    while (node){
        printf("key:%d, value:%d\n", i+1, node->data);
        node = node->next;
        i++;
    }
}

//带头节点
bool ListInsert(LinkList l, int i, int e){

    LNode *next = l;

    int j = 0;

    while (next!=NULL && (j < i -1)){
        next = next->next;
        j++;
    }

    if (next == NULL || j >= i){
        return false;
    }

    LNode *current = (LNode*) malloc(sizeof(LNode));
    current->data = e;
    current->next = next->next;
    next->next = current;

    return true;
}

bool ListDelete(LinkList l, int i, int *e){

    LNode *node = l;

    int j = 0;
    while (node != NULL && j < i-1){
        node = node->next;
        j++;
    }

    if (node == NULL || j >= i) return false;

    LNode *tmp = node->next;

    *e = tmp->data;
    node->next = tmp->next;

    free(tmp);
    return true;
}

void InitLinkListHead(LinkList l){

    l = (LNode*) malloc(sizeof(LNode));

    l->data = 0;
    l->next = NULL;

    int value;
    while (scanf("%d", &value) != EOF){
        LNode *q = (LNode*) malloc(sizeof(LNode));
        q->data = value;
        q->next = l->next;
        l->next = q;
    }
}

static void testInsert()
{
    LinkList l = (LNode*) malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;


    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);

    if (!ListInsert(l, 0, 0)){
        printf("插入失败\n");
    }

    if (!ListInsert(l, 5, 4)){
        printf("插入4失败\n");
    }

    if (ListInsert(l, 4, 4)){
        printf("插入4成功\n");
    }


    DumpList(l);
}

static void testDel(){

    LinkList l = (LNode*) malloc(sizeof(LNode));
    l->next = NULL;
    l->data = 0;
    int e;
    ListInsert(l, 1, 1);
    ListInsert(l, 2, 2);
    ListInsert(l, 3, 3);

    ListDelete(l, 2, &e);

    DumpList(l);
    printf("============\n");

    if (!ListDelete(l, 5, &e)){
        printf("%d删除失败\n", 5);
    }

    if (!ListDelete(l, 0, &e)){
        printf("%d删除失败\n", 0);
    }

    DumpList(l);
}

static void testInitLinkListHead(){
    LinkList list;
    InitLinkListHead(list);
    DumpList(list);
}

int main(){
    testInitLinkListHead();
    return 0;
}