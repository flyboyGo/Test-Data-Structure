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
            //������������,����ջ��������
            //˵�� ǰ����������,��ƥ��,����0(false)
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

    //���ջ��Ϊ��,˵��ջ�л���������δ��
    //û��ƥ��,����0(false)
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