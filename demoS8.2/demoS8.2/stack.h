#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#define DataType int

struct Stack
{
    DataType* data;
    int top;
    int capacity;
};

//��ʼ����������
void StackInit(struct Stack* ps);

//���ٺ�������
void StackDestory(struct Stack* ps);

//��ջ��������
void StackPush(struct Stack* ps, DataType x);

//��ջ��������
void StackPop(struct Stack* ps);

//ȡջ��Ԫ�غ�������
DataType StackTop(struct Stack* ps);

//����ջ��Ԫ��������������
int StackSize(struct Stack* ps);

//�ж�ջ�Ƿ�Ϊ�պ�������
int StackEmpty(struct Stack* ps);
