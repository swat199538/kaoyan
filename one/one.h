#include <stdlib.h>
#include <stdio.h>

#define INIT_SIZE 10

typedef struct {
    int *data;
    int max_size;
    int length;
} SeList;

void InitList(SeList* t);

void IncreaseSize(SeList* t, int len);

void DestroyList(SeList* l);

int ListDelete(SeList* l, int i, int* e);

int ListInsert(SeList* l, int i, int e);

void DumpListData(const SeList* l);

int GetElem(const SeList* l, int i, int* e);

int LocalElem(const SeList*l, int e, int* i);

int Empty(const SeList* l);