#include "sequenceList.h"

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

void DestroyList(SeList* l){
    l->length = 0;
    l->max_size = 0;
    free(l->data);
}

int ListDelete(SeList* l, int i, int* e){

    if(i < 1 || i > l->length) return 0;

    *e = l->data[i - 1];

    for (int j=i; j < l->length; j++){
        l->data[j-1] = l->data[j];
    }

    l->length--;
    return 1;
}

int ListInsert(SeList* l, int i, int e){
    if(i < 1 || i > l->length+1) return 0;
    if(l->length >= l->max_size) return 0;

    for (int j = l->length; j > i-1; --j) {
        l->data[j] = l->data[j-1];
    }

    l->data[i-1] = e;
    l->length++;

    return 1;
}

void DumpListData(SeList l){
    printf("list length is %d \n", l.length);
    printf("list max length is %d \n", l.max_size);
    for (int i=0; i < l.length; i++){
        printf("index:%d, value:%d \n", i+1, l.data[i]);
    }
}

int GetElem(SeList l, int i, int* e){
    if(i < 1 || i > l.length) return 0;
    *e = l.data[i-1];
    return 1;
}

int LocalElem(SeList l, int e, int* i){

    if(l.length <= 0) return 0;

    for (int j=0; j < l.length; j++){
        if(l.data[j] == e){
            *i = j+1;
            return 1;
        }
    }

    return 0;
}

int Empty(SeList l){
    return l.length == 0;
}

bool ListDelMin(SeList* l, int* data){
    //1.遍历整个顺序表记录下最小的元素和位置
    //2.将最后一个元素的值填充到最小元素位置
    //3.将最小元素值通过指针传出去
    //空数组无法删除
    if (l->length <= 0) return false;

    int minIndex = 0;
    int minValue = l->data[0];

    for(int i =1; i < l->length; i++){
        if (l->data[i] < minValue){
            minValue = l->data[i];
            minIndex = i;
        }
    }
    *data = minValue;
    l->data[minIndex] = l->data[l->length - 1];
    return true;
}

static void TestInsert(){
    SeList l;

    InitList(&l);

    ListInsert(&l, 1, 1);
    ListInsert(&l, 1, 2);
    ListInsert(&l, 1, 3);
    ListInsert(&l, 1, 4);
    ListInsert(&l, 1, 5);
    ListInsert(&l, 1, 6);
    ListInsert(&l, 1, 7);
    ListInsert(&l, 1, 8);
    ListInsert(&l, 1, 9);
    ListInsert(&l, 1, 10);
    ListInsert(&l, 1, 11);

    IncreaseSize(&l, 5);

    ListInsert(&l, 1, 12);
    ListInsert(&l, 1, 13);
    ListInsert(&l, 1, 14);
    ListInsert(&l, 1, 15);
    ListInsert(&l, 1, 16);

    DumpListData(l);

    DestroyList(&l);
}

static void TestDel(){
    SeList l;

    InitList(&l);

    ListInsert(&l, 1, 1);
    ListInsert(&l, 2, 2);
    ListInsert(&l, 3, 3);

    DumpListData(l);

    int e;

    ListDelete(&l, 2, &e);

    printf("e value is %d\n", e);

    DumpListData(l);
    DestroyList(&l);
}

static void TestGet(){
    SeList l;

    InitList(&l);

    ListInsert(&l, 1, 1);
    ListInsert(&l, 2, 2);
    ListInsert(&l, 3, 3);

    int e;

    GetElem(l, 2, &e);

    printf("e value is %d \n", e);

    DestroyList(&l);
}

static void TestLocal(){

    SeList l;

    InitList(&l);

    ListInsert(&l, 1, 1);
    ListInsert(&l, 2, 2);
    ListInsert(&l, 3, 3);
    ListInsert(&l, 5, 4);

    int key;

    if(LocalElem(l, 4, &key)){
        printf("located key is %d\n", key);
    } else{
        printf("not found \n");
    }

    DestroyList(&l);

}

static void TestEmpty(){

    SeList  l;

    InitList(&l);

    ListInsert(&l, 1, 1);
    ListInsert(&l, 1, 1);
    ListInsert(&l, 1, 1);

    int e;
    ListDelete(&l, 1, &e);
    ListDelete(&l, 1, &e);

    if(Empty(l)){
        printf("is empty\n");
    } else{
        printf("not empty\n");
    }

    DestroyList(&l);
}

static void TestDelMin(){
    SeList l;
    InitList(&l);
    ListInsert(&l, 1, 10);
    ListInsert(&l, 2, 2);
    ListInsert(&l, 3, 3);

    DumpListData(l);

    int *min;

    ListDelMin(&l, min);

    printf("min value is %d \n", *min);

    DumpListData(l);
}

int main(){
    TestDelMin();
    return 0;
}