//
// Created by 亮王 on 2022/10/7.
//

#ifndef SEQUENCELIST_REVERSE_H
#define SEQUENCELIST_REVERSE_H

#include "stdbool.h"

#define MAX_LEN 10

typedef struct SqList{
    int data[MAX_LEN];
    int len;
} SqList;

typedef struct SqList2{
    int* data;
    int len;
    int max_len;
} SqList2;

void reverse(SqList *L);

void  del_x_elem(SqList *L, int x);

void printList(SqList *l);

void printList2(SqList2 *l);

int del_range(SqList *L, int s, int t);

int del_range_2(SqList *L, int s, int t);

int del_same(SqList *l);

SqList2* merge_list(SqList2 *l1, SqList2 *l2);

bool merge_order_list(SqList *A, SqList *B, SqList2 *c);

bool reverse_list(int* l, int left, int right, int array_size);

void exchange_list(int*l , int m, int n, int array_size);

#endif //SEQUENCELIST_REVERSE_H
