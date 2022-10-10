//
// Created by 亮王 on 2022/10/7.
//

#ifndef SEQUENCELIST_REVERSE_H
#define SEQUENCELIST_REVERSE_H

#define MAX_LEN 10

typedef struct SqList{
    int data[MAX_LEN];
    int len;
} SqList;

void reverse(SqList *L);

void  del_x_elem(SqList *L, int x);

void printList(SqList *l);

int del_range(SqList *L, int s, int t);

#endif //SEQUENCELIST_REVERSE_H
