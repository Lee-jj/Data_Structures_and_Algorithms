#include <iostream>
#include "TestLkList.h"
using namespace std;

// 创建线性表
Status Test_CreateList(LkListPtr list, ElemType data [], int n)
{
    Status s = fail;
    s = List_Init(list);
    if (s == success)
    {
        for (int i = 1; i <= n; i++) // 插入n个指定的元素到线性表中
        {
            s = List_Insert(list, i, data[i-1]);
            if (s != success)
                break;
        }
        List_Print(list);
    }
    return s;
}

// 清空线性表
Status Test_ClearList(LkListPtr list)
{
    Status s = fail;
    if (!(List_Empty(list)))
    {
        List_Clear(list);
        if (List_Empty(list))
            s = success;
    }
    return s;
}

// 找到指定位置的直接前驱和直接后继 
Status Test_RetrivalPriorNext(LkListPtr list, int pos)
{
    Status s = fail;
    ElemType e;
    s = List_Retrival(list, pos, &e);
    if (s == success)
    {
        printf("The element of %d is %d\n", pos, e);
        s = List_Prior(list, pos, &e);
        if (s == success)
            printf("The direct prior element value of %d is %d\n", pos, e);
        else printf("%d have no Prior\n", pos);
        s = List_Next(list, pos, &e);
        if (s == success)
            printf("The direct next element value of %d is %d\n", pos, e);
        else printf("%d have no Next\n", pos);
    }
    else printf("Illegal position\n");
    return s;
}

// 在线性表已经存在的情况下定位某个元素
Status Test_Locate(LkListPtr list, ElemType e)
{
    Status s = fail;
    int pos;
    s = List_Locate(list, e, &pos);
    if (s == success)
        printf("The position of %d is %d\n", e, pos);
    else printf("Lookup Failed\n");
    return s;
}

// 线性表的大小
void Test_Size(LkListPtr list)
{
    int len;
    len = List_Size(list);
    printf("The length of the List is:%d\n", len);
}

