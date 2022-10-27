//
// Created by swat on 2022/10/27.
//

#include <stdlib.h>
#include "expression_evaluation.h"
#include "sq_stack.h"
#include "string.h"
#include "stdio.h"

int main(){

    /**
     * 1.设定运算符栈；
     * 2.从左到右遍历中缀表达式的每个数字和运算符；
     * 3.若当前字符是数字，则直接输出成为后缀表达式的一部分；
     * 4.若当前字符为运算符，则判断其与栈顶运算符的优先级，若优先级大于栈顶运算符，则进栈；若优先级小于栈顶运算符，退出栈顶运算符成为后缀表达式的一部分，然后将当前运算符放入栈中；
     * 5.若当前字符为“(”，进栈；
     * 6.若当前字符为“)”，则从栈顶起，依次将栈中运算符出栈成为后缀表达式的一部分，直到碰到“(”。将栈中“(”出栈，不需要成为后缀表达式的一部分，然后继续扫描表达式直到最终输出后缀表达式为止。
     */

    char str[] = "25 * 18 + 1 / ( 35 * 2 + 8 )";

    int len;
    char** t = explode(' ', str, &len);

    for(int i=0; i < len; i++){
        printf("%s\n", t[i]);
    }

    return 0;
}

char** explode(char se, const char* str, size_t* len){
    char* string = strdup(str);

    int currentLen = 0;

    char *ptr = strtok(string, &se);

    while (ptr != NULL){
        currentLen++;
        ptr = strtok(NULL, &se);
    }

    char** ret = malloc(sizeof(size_t)*13);

    ptr = strtok(string, &se);

    int i = 0;
    while (ptr != NULL){
        ptr = strtok(NULL, &se);
        ret[i] = malloc(sizeof(char*));
        strcpy(ret[i], ptr);
    }

    free(string);

    *len = currentLen;
    return ret;
}