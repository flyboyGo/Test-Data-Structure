#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void Test1()
{
	struct ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrintf(plist);
	struct ListNode* ret = ListFind(plist, 5);
	if (ret != NULL)
	{
		ListErase(ret);
	}
	ListPrintf(plist);
	ListDestory(plist);
	plist = NULL;
}
int main()
{
	Test1();
	return 0;
}
