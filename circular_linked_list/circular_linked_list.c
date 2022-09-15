//
// Created by 亮王 on 2022/9/15.
//

#include "circular_linked_list.h"


LinkList InitList(){
    LinkList l = (LNode*) malloc(sizeof(LNode));
    if (l == NULL) return NULL;
    l->next = l;
    return l;
}

bool Empty(LinkList l){
    if (l->next == l) return true;
    return false;
}

bool isTail(LinkList l, LNode *node){

    if (node->next == l){
        return true;
    }

    return false;
}

int main(){

    LinkList  l = InitList();

    if (Empty(l)){
        printf("is empty\n");
    } else{
        printf("not empty\n");
    }

    return 0;
}