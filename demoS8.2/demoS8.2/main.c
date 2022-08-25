#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void Test()
{
    struct Stack st;
    StackInit(&st);

    StackPush(&st, 5);
    StackPush(&st, 4);
    StackPush(&st, 3);
    StackPush(&st, 2);
    StackPush(&st, 1);

    StackPop(&st);

    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }

    StackDestory(&st);
}


//int main() {
//    Test();
//    return 0;
//}
