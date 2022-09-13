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


int main(){

    DLinkList l = InitDLinkList();

    if (EmptyList(l)){
        printf("is empty \n");
    } else{
        printf("not empty \n");
    }

    return  0;
}