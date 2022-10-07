//
// Created by 亮王 on 2022/10/7.
//

#include "reverse.h"
#include "stdio.h"
#include "stdlib.h"


void printList(SqList *l){
    if(l->len <= 0) return;

    for(int i=0; i < l->len; i++){
        printf("%d \n", l->data[i]);
    }
}

void reverse(SqList *L){
    if(L->len <= 0) return;
    int tmp;
    for (int i=0; i < L->len / 2; i++){
        tmp = L->data[i];
        L->data[i] = L->data[L->len-i-1];
        L->data[L->len-i-1] = tmp;
    }
}


int main(){
    SqList* L = (SqList *) malloc(sizeof(SqList));
    L->len = 0;
    for (int i = 0; i < MAX_LEN; ++i) {
        L->data[i] = i + 1;
        L->len++;
    }
    printList(L);
    reverse(L);
    printList(L);
    return 0;
}