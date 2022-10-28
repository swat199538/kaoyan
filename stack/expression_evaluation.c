//
// Created by swat on 2022/10/27.
//

#include <stdlib.h>
#include <assert.h>
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

char** explode(char* a_str, const char a_delim, size_t* len){
    char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp){
        if(a_delim == *tmp){
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    *len = count;

    return result;
}