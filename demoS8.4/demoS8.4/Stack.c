#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define DataType int

typedef struct Stack
{
    DataType* data;
    int top;
    int capacity;
}Stack;

//初始化函数声明
void StackInit(struct Stack* ps)
{
    assert(ps);
    ps->data = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

//销毁函数声明
void StackDestory(struct Stack* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = ps->top = 0;
}

//进栈函数声明
void StackPush(struct Stack* ps, DataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        int* tmp = realloc(ps->data, sizeof(int) * newCapacity);
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        ps->data = tmp;
    }

    ps->data[ps->top] = x;
    ps->top++;
}

//出栈函数声明
void StackPop(struct Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

//取栈顶元素函数声明
DataType StackTop(struct Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    //assert(!StackEmpty(ps));
    return ps->data[ps->top - 1];
}

//计算栈中元素数量函数声明
int StackSize(struct Stack* ps)
{
    assert(ps);
    return ps->top;
}

//判断栈是否为空函数声明
int StackEmpty(struct Stack* ps)
{
    assert(ps);
    return ps->top == 0 ? 1 : 0;
}