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

//初始化函数声明
void StackInit(struct Stack* ps);

//销毁函数声明
void StackDestory(struct Stack* ps);

//进栈函数声明
void StackPush(struct Stack* ps, DataType x);

//出栈函数声明
void StackPop(struct Stack* ps);

//取栈顶元素函数声明
DataType StackTop(struct Stack* ps);

//计算栈中元素数量函数声明
int StackSize(struct Stack* ps);

//判断栈是否为空函数声明
int StackEmpty(struct Stack* ps);
