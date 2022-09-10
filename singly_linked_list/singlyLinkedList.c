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

LinkList InitLinkListHead(){

    LinkList l = (LNode*)malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;

    int value = 0;

    while (value != 1909){
        scanf("%d", &value);
        if(value == 1909) break;
        LNode *current = (LNode*) malloc(sizeof(LNode));
        current->data = value;
        current->next = l->next;
        l->next = current;
    }

    return l;
}

LinkList InitLinkListTail(){
    LinkList l = (LNode*) malloc(sizeof(LNode));
    l->next = NULL;
    l->data = 0;
    LNode *node =l;
    int value = 0;
    while (value != 1909){
        scanf("%d", &value);
        if(value == 1909) break;
        LNode *current = (LNode*) malloc(sizeof(LNode));
        current->next = NULL;
        current->data = value;
        node->next = current;
        node = current;
    }
    return l;
}

void DestroyList(LinkList l){
    LNode *node = l->next;
    while (node != NULL){
        LNode *tmp = node;
        node = tmp->next;
        free(tmp);
    }
    free(l);
}

LinkList LinkListReverse(LinkList l){

    LinkList newList = (LNode*) malloc(sizeof(LNode));

    LNode *node = l->next;

    while (node != NULL){
        LNode *current = (LNode*) malloc(sizeof(LNode));
        current->data = node->data;
        current->next = newList->next;
        newList->next = current;
        node = node->next;
    }

    return newList;
}

int ListIndexOfElem(LinkList l, int e){
    int i = 1;
    LNode *node = l->next;
    while (node != NULL){
        if(node->data == e){
            return i;
        }
        i++;
        node = node->next;
    }
    return -1;
}

bool DeleteNode(LNode* node){
    if (node == NULL) return false;
    LNode *tmp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    free(tmp);
    return true;
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
    LinkList list = InitLinkListHead();
    DumpList(list);
}

static void testInitLinkListTail(){
    LinkList l = InitLinkListTail();
    DumpList(l);
}

static void testDestroy(){
    LinkList l = InitLinkListTail();
    DumpList(l);
    DestroyList(l);
}

static void testReverse(){
    LinkList l = InitLinkListTail();
    DumpList(l);
    LinkList tmp = l;
    l = LinkListReverse(l);
    DestroyList(tmp);
    DumpList(l);
}

static void testIndexOf(){

    LinkList l = InitLinkListTail();

    int index = ListIndexOfElem(l, 4);

    if(index != -1){
        printf("index is %d\n", index);
    } else{
        printf("not found\n");
    }
}

static void testDelNode(){

    LinkList l = InitLinkListTail();

    DumpList(l);

    LNode *node = l;

    for (int i = 0; i < 2; i++){
        node = node->next;
    }

    printf("node value is %d\n", node->data);

    DeleteNode(node);

    DumpList(l);
}

int main(){
    testDelNode();
    return 0;
}