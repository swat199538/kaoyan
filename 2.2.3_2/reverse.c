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

void  del_x_elem(SqList *L, int x){
    int k=0, i=0;
    for (; i < L->len; i++){
        if (L->data[i] != x){
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->len = k;
}


int main(){
    SqList* L = (SqList *) malloc(sizeof(SqList));
    L->len = 0;
    for (int i = 0; i < MAX_LEN; ++i) {
        L->data[i] = i + 1;
        L->len++;
    }

    L->data[5] = 1;
    L->data[8] = 1;

    printList(L);

    del_x_elem(L, 1);

    printList(L);

    return 0;
}