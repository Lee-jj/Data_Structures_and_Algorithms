#include <iostream>
#include "LkList.h"

using namespace std;

/* 该链式存储结构为带头节点的链表 */

Status List_Init(LkListPtr L)
{
    Status s = fail;
    Ptr p;
    if (*L == NULL)
    {
        p = (Ptr)malloc(sizeof(Node));  // 头节点
        if (p)
        {
            *L = p;                          // 让L指针指向头节点
            (*L)->next = NULL;
            s = success;
        }
    }
    // free(p);
    return s;
}

void List_Destory(LkListPtr L)
{
    // Ptr p;
    // if (*L)
    // {
    //     p = (*L)->next;
    //     while (p)
    //     {
    //         (*L)->next = p->next;
    //         free(p);
    //         p = (*L)->next;
    //     }
    //     free(*L);
    //     (*L) = NULL;
    // }

    // 由于有很多重复，故调用List_Clear来实现
    List_Clear(L);
    if (*L)
    {
        free(*L);
        *L = NULL;
    }
}

// 与List_Destory类似，但保留了头节点
void List_Clear(LkListPtr L)
{
    Ptr p;
    if (*L)
    {
        p = (*L)->next;
        while (p)
        {
            (*L)->next = p->next;
            free(p);
            p = (*L)->next;
        }
    }
}

bool List_Empty(LkListPtr L)
{
    return ((*L)->next == NULL);
}

int List_Size(LkListPtr L)
{
    int len = 0;
    Ptr p;
    p = (*L)->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

Status List_Retrival(LkListPtr L, int pos, ElemType *elem)
{
    Status s = Range_error;
    int i = 1;
    Ptr p = (*L)->next;
    while (p && i < pos)
    {
        i++;
        p = p->next;
    }
    if (p && i == pos)
    {
        *elem = p->elem;
        s = success;
    }
    return s;
}

Status List_Locate(LkListPtr L, ElemType elem, int *pos)
{
    Status s = fail;
    int i = 1;
    Ptr p = (*L)->next;
    while (p && elem != p->elem)
    {
        i++;
        p = p->next;
    }
    if (p && elem == p->elem)
    {
        *pos = i;
        s = success;
    }
    return s;
}

// 很多时候我们需要定位到pos位置，然后在这个位置进行插入删除及查找前驱后继等操作，所以我们将这一操作整合
Status List_Find(LkListPtr L, int pos, Ptr * pAddr)
{
    Status s = fail;
    int i = 1;
    Ptr p = (*L)->next;
    while (p && i < pos)
    {
        i++;
        p = p->next;
    }
    if (p && i == pos)
    {
        *pAddr = p;
        s = success;
    }
    return s;
}

Status List_Insert(LkListPtr L, int pos, ElemType elem)
{
    /*
    Status s = fail;
    int i = 1;
    Ptr p, q;
    p = (*L)->next;
    while (p && i < pos-1)
    {
        i++;
        p = p->next;
    }
    if (p && i == pos-1)
    {
        q = (Ptr)malloc(sizeof(Node));
        if (q)
        {
            q->elem = elem;
            q->next = p->next;
            p->next = q;
            s = success;
        }
    }
    return s;
    */
    // 使用List_Find简化步骤
    Status s = fail;
    Ptr p, q;
    if (pos > 1)
    {
        s = List_Find(L, pos-1, &p);
        if (s == success)
        {
            s = fail;
            q = (Ptr)malloc(sizeof(Node));
            if (q)
            {
                q->elem = elem;
                q->next = p->next;
                p->next = q;
                s = success;
            }
        }
    }
    else
    {
        q = (Ptr)malloc(sizeof(Node));
        if (q)
        {
            q->elem = elem;
            q->next = (*L)->next;
            (*L)->next = q;
            s = success;
        }
    }
    return s;
}

Status List_Delete(LkListPtr L, int pos)
{
    /*
    Status s = fail;
    int i = 1;
    Ptr p, q;
    p = (*L)->next;
    while (p && i < pos-1)
    {
        i++;
        p = p->next;
    }
    if (p && i == pos-1)
    {
        q = p->next;
        if (q)
        {
            p->next = q->next;
            free(q);
            q = NULL;
            s = success;
        }      
    }
    return s;
    */
    // 简化操作
    Status s = fail;
    Ptr p, q;
    s = List_Find(L, pos-1, &p);
    if (s == success)
    {
        s = fail;
        q = p->next;
        if (q)
        {
            p->next = q->next;
            free(q);
            q = NULL;
            s = success;
        }      
    }
    return s;
}

Status List_Prior(LkListPtr L, int pos, ElemType *elem)
{
    Status s = fail;
    Ptr p;
    s = List_Find(L, pos-1, &p);
    if (s == success)
    {
        s = fail;
        *elem = p->elem;
        s = success;
    }
    return s;
}

Status List_Next(LkListPtr L, int pos, ElemType *elem)
{
    Status s = fail;
    Ptr p;
    s = List_Find(L, pos+1, &p);
    if (s == success)
    {
        s = fail;
        *elem = p->elem;
        s = success;
    }
    return s;
}

void List_Print(LkListPtr L)
{
    Ptr p = (*L)->next;
    printf("***** Now print List *****\n");
    while (p)
    {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n***** List print finished *****\n");
}
