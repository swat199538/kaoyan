#include <stdlib.h>

#define INIT_SIZE 10

typedef struct {
    int *data;
    int max_size;
    int length;
} SeList;

void InitList(SeList* t);

void IncreaseSize(SeList* t, int len);

int ListDelete(SeList* l, int i, int* e);

int ListAdd(SeList* l, int i, int e);