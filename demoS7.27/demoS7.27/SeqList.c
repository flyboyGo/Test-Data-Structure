#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ������ʵ��
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

//��麯���Ƿ�����
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

//��ӡ����ʵ��
void SeqListPrint(const SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//���Һ���ʵ��
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

//���뺯��ʵ��
void SeqListInsert(SL* ps, int pos, DATA_TYPE x)
{
	//�������
	SeqListCheckCapacity(ps);
	//Ų������
	assert((pos >= 1) && (pos <= ps->size + 1));

	int end = ps->size;
	while (end >= pos)
	{
		ps->data[end] = ps->data[end - 1];
		end--;
	}
	//��������
	ps->data[end] = x;
	ps->size++;
	ps->capacity--;
}

//ɾ������ʵ��
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

//���ٺ���ʵ��
void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}

//β�庯��ʵ��
void SeqListPushBack(SL* ps, int X)
{
	//�������
	//SeqListCheckCapacity(ps);
	//��������
	//ps->data[ps->size] = X;
	//ps->size++;
	//ps->capacity--;

	//�ȼ���
	SeqListInsert(ps, ps->size + 1, X);
}

//βɾ����ʵ��
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	//ps->size--;
	//ps->capacity++;

	//�ȼ���
	SeqListErase(ps, ps->size);
}

//ͷ�庯��ʵ��
void SeqListPushFront(SL* ps, int X)
{
	//�������
	//SeqListCheckCapacity(ps);
	//Ų������
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->data[end + 1] = ps->data[end];
	//	--end;
	//}
	//ps->data[0] = X;
	//ps->size++;
	//ps->capacity--;

	//�ȼ���
	SeqListInsert(ps, 1, X);
}

//ͷɾ����ʵ��
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

	//�ȼ���
	SeqListErase(ps, 1);
}


