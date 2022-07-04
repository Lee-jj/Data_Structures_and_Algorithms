#pragma once // 希望头文件只编译一次

// 定义状态
typedef enum Status
{
    success, fail, fatal, Range_error
}Status;

// 线性表的数据类型
typedef int ElemType;

// 创建链式存储结构的结点结构
typedef struct Node
{
    ElemType elem;
    struct Node *next;
}Node, *Ptr;
typedef Ptr *LkListPtr;


// 线性表基本功能
Status List_Init(LkListPtr L);
void List_Destory(LkListPtr L);
void List_Clear(LkListPtr L);
bool List_Empty(LkListPtr L);
int List_Size(LkListPtr L);
Status List_Retrival(LkListPtr L, int pos, ElemType *elem);
Status List_Locate(LkListPtr L, ElemType elem, int *pos);
Status List_Find(LkListPtr L, int pos, Ptr * pAddr);
Status List_Insert(LkListPtr L, int pos, ElemType elem);
Status List_Delete(LkListPtr L, int pos);
Status List_Prior(LkListPtr L, int pos, ElemType *elem);
Status List_Next(LkListPtr L, int pos, ElemType *elem);

void List_Print(LkListPtr L);
