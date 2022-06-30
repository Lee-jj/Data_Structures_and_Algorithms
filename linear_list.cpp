#include <iostream>

using namespace std;

#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10

// 线性表的数据类型
typedef int ElemtType;

// 
typedef struct SqList
{
    ElemtType *elem;    // 首地址
    int length;         // 线性表长度
    int list_size;      // 线性表初始化元素个数
}SqList, *Ptr;

typedef Ptr SqListPtr;

// 定义状态
enum Status
{
    success, fail, fatal, Range_errors
};

// 初始化--创建线性表
Status List_Init(SqListPtr L)
{
    Status s = success;
    L->list_size = LIST_INIT_SIZE;
    L->length = 0;
    L->elem = (ElemtType *)malloc(sizeof(ElemtType) * L->list_size);
    if (L->elem == NULL)
        s = fatal;
    return s;
}

// 查找--按位置找值
Status List_Retrival(SqListPtr L, int pos, ElemtType *elem)
{
    Status s = Range_errors;
    if (L)
    {
        if ((pos - 1) > 0 && (pos - 1) < L->length)
        {
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    else
        s = fatal;
    return s;
}

// 查找--按值查找位置
Status List_Locate(SqListPtr L, ElemtType elem, int *pos)
{
    Status s = Range_errors;
    if (L)
    {
        for (int i = 0; i < L->length; ++i)
        {
            if (L->elem[i] == elem)
            {
                *pos = i + 1;
                s = success;
                break;
            }
        }
    }
    else
        s = fatal;
    return s;
}

// 插入元素操作
Status List_Insert(SqListPtr L, int pos, ElemtType elem)
{
    Status s = Range_errors;
    if ((pos - 1) >=0 && (pos - 1) <= L->length)
    {
        if (L && L->length < L->list_size)
        {
            for (int i = L->length - 1; i >= pos - 1; --i)
            {
                L->elem[i+1] = L->elem[i];
            }
            L->elem[pos-1] = elem;
            L->length++;
            s = success;
        } 
    }
    else
        s = fatal;
    return s;
}

// 删除元素
Status List_delete(SqListPtr L, int pos)
{
    Status s = Range_errors;
    if ((pos - 1) >= 0 && (pos - 1) < L->length)
    {
        if (L && L->length > 0)
        {
            for (int i = pos; i < L->length; ++i)
            {
                L->elem[i-1] = L->elem[i];
                L->length--;
                s = success;
            }
        }
    }
    else
        s = fatal;
    return s;
}

// 主函数
int main()
{
    cout << "hello world!" << endl;

    system("pause");
    return 0;
}