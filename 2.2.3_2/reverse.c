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

void printList2(SqList2 *l){
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

//仔细考虑了一下不符合题目要求
//最主要题目要求当中重点说明了是有序的顺序表，这个不能体现出有序
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


//符合题目4的有序顺序表
int del_range_2(SqList *L, int s, int t){

    //不允许为空，不允许 s大于等于t
    if(L->len <= 0 || s >= t) return 0;

    int i =0, j;

    for (; i < L->len && L->data[i] < s; i++);

    if (i >= L->len) return 0;

    for (j=i; j < L->len && L->data[j] <= t; j++);

    for (; j < L->len; i++, j++){
        L->data[i] = L->data[j];
    }

    L->len = i;

    return 1;
}

//从有序顺序表中删除所有其值重复的元素，使表中所有元素均不相同
int del_same(SqList *l){

    if (l->len <= 0) return 0;

    int i = 0, j = 1;

    for(; j < l->len; j++){
        if (l->data[i] != l->data[j]){
            i++;
            l->data[i] = l->data[j];
        }
    }

    l->len = i + 1;

    return 1;
}

//合并两个顺序表
SqList2* merge_list(SqList2 *l1, SqList2 *l2){

    if (l1->len <=0 && l2->len <= 0) return NULL;

    SqList2 *l3 = (SqList2 *) malloc(sizeof(SqList2));

    l3->len = l1->len + l2->len;
    l3->data = (int*) malloc(sizeof(int) * l3->len);

    int j = 0;

    for (int i = 0; i < l1->len; ++i, ++j) {
        l3->data[j] = l1->data[i];
    }

    for (int i = 0; i < l2->len; ++i, ++j) {
        l3->data[j] = l2->data[i];
    }

    free(l1);
    free(l2);

    return l3;
}

//有序顺序表A和有序顺序表B合并到新有序顺序表C
bool merge_order_list(SqList *A, SqList *B, SqList2 *C){


    return true;
}

void init_sq2(SqList2* l, int index, int len){

    l->len = len;
    l->data = (int*) malloc(sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        l->data[i] = index;
        index++;
    }
}


int main(){

    SqList2 *l1 = (SqList2*) malloc(sizeof(SqList2));
    SqList2 *l2 = (SqList2*) malloc(sizeof(SqList2));

    init_sq2(l1, 1, 3);
    init_sq2(l2, 4, 3);

    SqList2 *l3 = merge_list(l1, l2);

    printList2(l3);

    return 0;
}