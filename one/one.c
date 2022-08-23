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

int main(){
    SeList t;
    InitList(&t);
    IncreaseSize(&t, 20);
    return 0;
}