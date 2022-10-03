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
	DATA_TYPE* data; //��̬�洢����
	int size; // ��ʾ�����д洢�˶��ٸ�����
	int capacity;//��ʾʣ��Ŀռ�����
}SL;

//�ӿں��� -- ����������STL��
//��̬�ص�:������˾ͽ�ֹ���� ȱ��:˳���Ĵ�С����ȷ��

//��ʼ����������
void SeqListInit(SL* ps);

//��ӡ��������
void SeqListPrint(const SL* ps);

//���ٺ�������
void SeqListDestory(SL* ps);

//���Һ�������
int SeqListFind(const SL* ps, DATA_TYPE x);

//���뺯������
void SeqListInsert(SL* ps, int pos, DATA_TYPE x);

//ɾ����������
void SeqListErase(SL* ps, int pos);

//β�庯������
void SeqListPushBack(SL* ps, int X);

//βɾ��������
void SeqListPopBack(SL* ps);

//ͷ�庯������
void SeqListPushFront(SL* ps, int X);

//ͷɾ��������
void SeqListPopFront(SL* ps);




