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

    //超过了C的范围
    if (A->len + B->len > C->max_len) return false;

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < A->len || j < B->len){
        if (i < A->len && j < B->len){
            int tmp = A->data[i];
            if (B->data[j] < tmp){
                tmp = B->data[j];
                j++;
            } else{
                i++;
            }
            C->data[k] = tmp;
        } else if(i < A->len){
            C->data[k] = A->data[i];
            i++;
        } else if (j < B->len){
            C->data[k] = B->data[j];
            j++;
        }
        k++;
    }

    C->len = A->len+B->len;
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

void init_sq(SqList *l, int index, int len){
    l->len = 0;
    for (int i = 0; i < len; ++i) {
        l->data[i] = index;
        index++;
        l->len++;
    }
}


bool reverse_list(int* A, int left,  int right, int array_size){
    if (left>= right || right >= array_size) return false;
    int mid = (left+right) /2;
    for (int i=0; i<= mid-left;i++){
        int temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
    return true;
}


void exchange_list(int* A, int m, int n, int array_size){
    reverse_list(A, 0, m+n-1, array_size);
    reverse_list(A, 0, n-1, array_size);
    reverse_list(A, n, m+n-1, array_size);
}

void searchExchangeInsert(SqList *l, int x){

    int low = 0, high = l->len -1, mid;

    while (low <= high){
        mid = (low + high) / 2;
        if (l->data[mid] == x){
            break;
        } else if (l->data[mid] < x){
            low = mid + 1;
        } else{
            high = mid -1;
        }
    }

    if (l->data[mid] == x && mid != l->len-1){
        int t = l->data[mid];
        l->data[mid] = l->data[mid+1];
        l->data[mid+1] = t;
    }

    if (low > high){
        int i =l->len -1;
        for (; i > high ; i--) {
            l->data[i+1]=l->data[i];
        }
        l->data[i+1];
    }
}


bool fast_find(SqList *l, int x){

    if (l->len <= 0) return false;

    int mid = (l->len - 1)/2;

    int i =0, j = l->len;

    while ( i<=mid || j >= mid ){

        if (i <= mid){

            if (l->data[i] == x){

            }

        }


    }



}


int main(){

    int p[7];

    int k = 1;
    for (int i=0; i < 3; i++){
        p[i] = k+10;
        k++;
    }

    k = 1;
    for (int i = 3; i < 7; ++i) {
        p[i] = k+20;
        k++;
    }

    for (int i = 0; i < 7; ++i) {
        printf("k:%d, v:%d\n", i, p[i]);
    }

    exchange_list(p, 3, 4, 7);

    printf("\n\n");

    for (int i = 0; i < 7; ++i) {
        printf("k:%d, v:%d\n", i, p[i]);
    }

    return 0;
}