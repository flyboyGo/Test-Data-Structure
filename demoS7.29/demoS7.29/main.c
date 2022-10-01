#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void TestSList1()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);

	SListPrint(plist);
}
void TestSList2()
{
	SLNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPrint(plist);
}
void TestSList3()
{
	SLNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPopBack(&plist);
	SListPrint(plist);
}
void TestSList4()
{
	SLNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPopFront(&plist);
	SListPrint(plist);
}

void TestSList5()
{
	SLNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 2);
	SListPrint(plist);

	SLNode* pos = SListFind(plist, 2);
	int i = 0;
	while (pos != NULL)
	{
		printf("第%d个pos节点:%p->%d\n", ++i, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}

	//修改数据
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(plist);
}

void TestSList6()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListInsert(&plist, 3, 5);
	SListPrint(plist);
}

void TestSList7()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListErase(&plist, 1);
	SListPrint(plist);
}

void TestSList8()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SLNode* pos = SListFind(plist, 1);
	SListInsertPlus(&plist, pos, 30);
	SListPrint(plist);
}

void TestSList9()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SLNode* pos = SListFind(plist, 4);
	SListInsertAfter(&plist, pos, 30);
	SListPrint(plist);
}

void TestSList10()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SLNode* pos = SListFind(plist, 1);
	SListErasePlus(&plist, pos);
	SListPrint(plist);
	SListDestory(&plist);
}

int main()
{
	TestSList10();
	return 0;
}
