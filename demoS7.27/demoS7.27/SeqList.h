#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define DATA_TYPE int
#define DEFAULT_MALLOC_SIZE 5

typedef struct SeqList
{
	DATA_TYPE* data; //动态存储数据
	int size; // 表示数组中存储了多少个数据
	int capacity;//表示剩余的空间容量
}SL;

//接口函数 -- 命名风格跟着STL走
//静态特点:如果满了就禁止插入 缺点:顺序表的大小不好确定

//初始化函数声明
void SeqListInit(SL* ps);

//打印函数声明
void SeqListPrint(const SL* ps);

//销毁函数声明
void SeqListDestory(SL* ps);

//查找函数声明
int SeqListFind(const SL* ps, DATA_TYPE x);

//插入函数声明
void SeqListInsert(SL* ps, int pos, DATA_TYPE x);

//删除函数声明
void SeqListErase(SL* ps, int pos);

//尾插函数声明
void SeqListPushBack(SL* ps, int X);

//尾删函数声明
void SeqListPopBack(SL* ps);

//头插函数声明
void SeqListPushFront(SL* ps, int X);

//头删函数声明
void SeqListPopFront(SL* ps);




