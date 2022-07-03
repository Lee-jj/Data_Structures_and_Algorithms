#include <iostream>
#include "SqList.h"
using namespace std;

#define LIST_INIT_SIZE 100  // 初始有100个
#define LIST_INCREAMENT 10  // 每次的增量


// 初始化--创建线性表
Status List_Init(SqListPtr L)
{
    Status s = fail;
    if (L != NULL)
    {
        L->elem = (ElemType *) malloc((LIST_INIT_SIZE + 1) * sizeof(ElemType)); // 分配内存
        if (L->elem)
        {
            L->length = 0;
            L->list_size = LIST_INIT_SIZE;
            s = success;
        }
    }
    return s;
}

// 归还线性表
void List_Destory(SqListPtr L)
{
    if (L)
    {
        if (L->elem)
        {
            free(L->elem);
            L->elem = NULL;
            L->length = 0;
        }
    }
}

// 清空线性表
void List_Clear(SqListPtr L)
{
    if (L)
    {
        L->length = 0;
    }
}

// 判断列表是否为空
bool List_Empty(SqListPtr L)
{
    return (L->length == 0);
}

// 判断列表的长度
int List_Size(SqListPtr L)
{
    return L->length;
}

// 查找--按位置找值
/* 为保证逻辑空间和存储空间的一致，即从1开始存储，位置0不使用，则在初始化内存时需要多分配一个空间 */
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    Status s = Range_error;
    if (L)
    {
        if (pos >= 1 && pos <= L->length)// 检测查找位置合法性
        {
            *elem = L->elem[pos];
            s = success;
        }
    }
    return s;
}

// 查找--按值查找位置
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
    Status s = Range_error;
    if (L)
    {
        for (int i = 1; i <= L->length; i++)
        {
            if (elem == L->elem[i])
            {
                *pos = i;
                s = success;
                break;
            }
        }
    }
    return s;
}

// 插入元素操作
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    Status s = Range_error;
    if (L)
    {
        if (pos >=1 && pos <= L->length+1)// 检测插入位置合法性
        {
            if (L->length < L->list_size)// 判断线性表长度是否超过最初分配的长度
            {
                for (int i = L->length; i >= pos; i--)
                {
                    L->elem[i+1] = L->elem[i]; 
                }
                L->elem[pos] = elem;
                L->length ++;
                s = success;
            }
        }
    }
    return s;
}

// 删除元素
Status List_Delete(SqListPtr L, int pos)
{
    Status s = Range_error;
    if (L)
    {
        if (pos >= 1 && pos <= L->length)
        {
            for (int i = pos; i < L->length; i++)
            {
                L->elem[i] = L->elem[i+1];
            }
            L->length --;
            s = success;
        }
    }
    return s;
}

// 求直接前驱
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
    Status s = Range_error;
    if (L)
    {
        if (pos > 1 && pos <= L->length)
        {
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    return s;
}

// 求直接后继
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
    Status s = Range_error;
    if (L)
    {
        if (pos >= 1 && pos < L->length)
        {
            *elem = L->elem[pos+1];
            s = success;
        }
    }
    return s;
}

// 打印线性表
void List_Print(SqListPtr L)
{
    if (L)
    {
        printf("\n***** Now Print List ***** \n");
        for (int i = 1; i <= L->length; i++)
        {
            printf("%d ", L->elem[i]);
        }
        printf("\n***** Print List successful ***** \n");
    }
}

