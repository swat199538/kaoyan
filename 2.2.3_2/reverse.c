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


int del_range(SqList *L, int s, int t){

    if (L->len <= 0 || s >= t) return 0;

    int k = 0;

    for(int i=0; i < L->len; i++){
        int data = L->data[i];
        if (data >= s && data <= t){
            k++;
        } else{
            L->data[i-k] = L->data[i];
        }
    }

    L->len -= k;
    return 1;
}

int main(){
    SqList* L = (SqList *) malloc(sizeof(SqList));
    L->len = 0;
    for (int i = 0; i < MAX_LEN; ++i) {
        L->data[i] = i + 1;
        L->len++;
    }

    printList(L);

    printf("\n\n");

    del_range(L, 1, 9);

    printList(L);

    return 0;
}