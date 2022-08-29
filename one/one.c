#include "one.h"

void InitList(SeList* t){
    t->data = (int*)malloc(sizeof(int) * INIT_SIZE);
    t->length = 0;
    t->max_size = INIT_SIZE;
}


void IncreaseSize(SeList* l, int len){
    int *t = l->data;
    l->data = (int*) malloc(sizeof(int) * (len+INIT_SIZE));
    for (int i=0; i < l->length; i++){
        //要判断内存的长度，存在越界风险
        l->data[i] = t[i];
    }
    l->max_size = len+INIT_SIZE;
    free(t);
}

//i 是数组下标
int ListDelete(SeList* l, int i, int* e){

    if (i > l->length || i < 0) return 0;

    *e = l->data[i];

    for (int j=i; j < l->length; j++)
        l->data[j] = l->data[j+1];

     l->length--;
    return 1;
}


int ListAdd(SeList* l, int i, int e){

    if (i < 0 || i > l->length) return 0;

    for (int j= l->length; j >= i; j--)
        l->data[j] = l->data[j -1];

    l->data[i] = e;
    l->length++;

    return 1;
}


int main(){
    SeList t;
    InitList(&t);
    IncreaseSize(&t, 20);
    return 0;
}