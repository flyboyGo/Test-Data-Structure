#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Postion
{
    int row;
    int col;
}PT;

/////////////////////////////////////////////////////////////////
typedef PT STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}Stack;

void StackInit(Stack* ps)
{
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    ps->capacity = 4;
    ps->top = 0;
}

void StackDestory(Stack* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType x)
{
    assert(ps);

    // ����-������
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }

    ps->a[ps->top] = x;
    ps->top++;
}

// ��ջ
void StackPop(Stack* ps)
{
    assert(ps);
    // ջ���ˣ�����Pop��ֱ����ֹ���򱨴�
    assert(ps->top > 0);

    //ps->a[ps->top - 1] = 0;
    ps->top--;
}

STDataType StackTop(Stack* ps)
{
    assert(ps);
    // ջ���ˣ�����Top��ֱ����ֹ���򱨴�
    assert(ps->top > 0);

    return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
    assert(ps);

    return ps->top;
}

int StackEmpty(Stack* ps)
{
    assert(ps);

    return ps->top == 0;
}

Stack path;
////////////////////////////////////////////////////////////////

void PrintMaze(int** maze, int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ���ջ���������·��
void PirntPath(Stack* ps)
{
    // path���ݵ���rPath
    Stack rPath;
    StackInit(&rPath);
    while (!StackEmpty(&path))
    {
        StackPush(&rPath, StackTop(&path));
        StackPop(&path);
    }

    while (!StackEmpty(&rPath))
    {
        PT top = StackTop(&rPath);
        printf("(%d,%d)\n", top.row, top.col);
        StackPop(&rPath);
    }

    StackDestory(&rPath);
}

int IsPass(int** maze, int N, int M, PT pos)
{
    if (pos.row >= 0 && pos.row < N
        && pos.col >= 0 && pos.col < M
        && maze[pos.row][pos.col] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int GetMazePath(int** maze, int N, int M, PT cur)
{
    StackPush(&path, cur);

    // ����ߵ�����
    if (cur.row == N - 1 && cur.col == M - 1)
        return 1;

    // ̽��curλ�õ����������ĸ�����
    PT next;
    maze[cur.row][cur.col] = 2;

    // ��
    next = cur;
    next.row -= 1;
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))
            return 1;
    }

    // ��
    next = cur;
    next.row += 1;
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))
            return 1;
    }


    // ��
    next = cur;
    next.col -= 1;
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))
            return 1;
    }

    // ��
    next = cur;
    next.col += 1;
    if (IsPass(maze, N, M, next))
    {
        if (GetMazePath(maze, N, M, next))
            return 1;
    }

    StackPop(&path);

    return 0;
}

int main()
{
    int N = 0, M = 0;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        // int a[n][m]; // vs2013 ��֧��
        // ��̬���ٶ�ά����
        int** maze = (int**)malloc(sizeof(int*) * N);
        for (int i = 0; i < N; ++i)
        {
            maze[i] = (int*)malloc(sizeof(int) * M);
        }

        // ��ά���������
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d", &maze[i][j]);
            }
        }

        StackInit(&path);
        // PrintMaze(maze, N, M);
        PT entry = { 0, 0 };
        if (GetMazePath(maze, N, M, entry))
        {
            //printf("�ҵ�ͨ·\n");
            PirntPath(&path);
        }
        else
        {
            printf("û���ҵ�ͨ·\n");
        }

        StackDestory(&path);

        for (int i = 0; i < N; ++i)
        {
            free(maze[i]);
        }
        free(maze);
        maze = NULL;
    }

    return 0;
}