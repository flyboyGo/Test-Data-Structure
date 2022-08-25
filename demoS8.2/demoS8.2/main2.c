#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

int isValid(char* s)
{
    struct Stack  st;
    StackInit(&st);
    while (*s)
    {
        if (*s == '('
            || *s == '['
            || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        else
        {
            //遇到到右括号,但是栈中无数据
            //说明 前面无左括号,不匹配,返回0(false)
            if (StackEmpty(&st))
            {
                StackDestory(&st);
                return 0;
            }

            char top = StackTop(&st);
            StackPop(&st);
            if ((*s == '}' && top != '{')
                || (*s == ')' && top != '(')
                || (*s == ']' && top != '['))
            {
                StackDestory(&st);
                return 0;
            }
            else
            {
                ++s;
            }
        }
    }

    //如果栈不为空,说明栈中还有左括号未出
    //没有匹配,返回0(false)
    int ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}

void Test2()
{
    char s[] = "([{}])";
    if (isValid(s) == 1)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}

int main() {
    Test2();
    return 0;
}