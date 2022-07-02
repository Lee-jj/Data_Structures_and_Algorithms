#pragma once // 希望头文件只编译一次

// 定义状态
typedef enum Status
{
    success, fail, fatal, Range_error
}Status;

// 线性表的数据类型
typedef int ElemType;

// 创建顺序存储结构的列表
typedef struct SqList
{
    ElemType *elem;    // 列表首地址
    int length;         // 线性表长度
    int list_size;      // 线性表初始化元素个数
}SqList, *Ptr;
typedef Ptr SqListPtr;

Status List_Init(SqListPtr L);
void List_Destory(SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
Status List_Insert(SqListPtr L, int pos, ElemType elem);
Status List_Delete(SqListPtr L, int pos);
Status List_Prior(SqListPtr L, int pos, ElemType *elem);
Status List_Next(SqListPtr L, int pos, ElemType *elem);

