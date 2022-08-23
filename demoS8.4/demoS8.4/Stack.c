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

//��ʼ����������
void StackInit(struct Stack* ps)
{
    assert(ps);
    ps->data = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

//���ٺ�������
void StackDestory(struct Stack* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = ps->top = 0;
}

//��ջ��������
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

//��ջ��������
void StackPop(struct Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

//ȡջ��Ԫ�غ�������
DataType StackTop(struct Stack* ps)
{
    assert(ps);
    assert(ps->top > 0);
    //assert(!StackEmpty(ps));
    return ps->data[ps->top - 1];
}

//����ջ��Ԫ��������������
int StackSize(struct Stack* ps)
{
    assert(ps);
    return ps->top;
}

//�ж�ջ�Ƿ�Ϊ�պ�������
int StackEmpty(struct Stack* ps)
{
    assert(ps);
    return ps->top == 0 ? 1 : 0;
}