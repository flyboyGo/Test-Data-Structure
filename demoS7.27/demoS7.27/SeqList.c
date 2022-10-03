#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化函数实现
void SeqListInit(SL* ps)
{
	DATA_TYPE* pf = (DATA_TYPE*)malloc(sizeof(DATA_TYPE) * DEFAULT_MALLOC_SIZE);
	if (pf == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	ps->data = pf;
	ps->capacity = DEFAULT_MALLOC_SIZE;
	ps->size = 0;
}

//检查函数是否增容
static void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == 0)
	{
		DATA_TYPE* pf = (DATA_TYPE*)realloc(ps->data, sizeof(DATA_TYPE) * ((ps->size) * 2));
		if (pf == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->data = pf;
		ps->capacity = ps->size;
	}
}

//打印函数实现
void SeqListPrint(const SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//查找函数实现
int SeqListFind(const SL* ps, DATA_TYPE x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return (i + 1);
		}
	}
	return -1;
}

//插入函数实现
void SeqListInsert(SL* ps, int pos, DATA_TYPE x)
{
	//检查增容
	SeqListCheckCapacity(ps);
	//挪动数据
	assert((pos >= 1) && (pos <= ps->size + 1));

	int end = ps->size;
	while (end >= pos)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	//插入数据
	ps->data[end] = x;
	ps->size++;
	ps->capacity--;
}

//删除函数实现
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size > 0);
	assert(pos <= ps->size && (pos > 0));

	int begin = pos;
	while (begin < ps->size)
	{
		ps->data[begin - 1] = ps->data[begin];
		begin++;
	}
	ps->size--;
	ps->capacity++;
}

//销毁函数实现
void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}

//尾插函数实现
void SeqListPushBack(SL* ps, int X)
{
	//检查增容
	//SeqListCheckCapacity(ps);
	//插入数据
	//ps->data[ps->size] = X;
	//ps->size++;
	//ps->capacity--;

	//等价于
	SeqListInsert(ps, ps->size + 1, X);
}

//尾删函数实现
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	//ps->size--;
	//ps->capacity++;

	//等价于
	SeqListErase(ps, ps->size);
}

//头插函数实现
void SeqListPushFront(SL* ps, int X)
{
	//检查增容
	//SeqListCheckCapacity(ps);
	//挪动数据
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->data[end + 1] = ps->data[end];
	//	--end;
	//}
	//ps->data[0] = X;
	//ps->size++;
	//ps->capacity--;

	//等价于
	SeqListInsert(ps, 1, X);
}

//头删函数实现
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->data[begin - 1] = ps->data[begin];
	//	++begin;
	//}
	//ps->size--;

	//等价于
	SeqListErase(ps, 1);
}


