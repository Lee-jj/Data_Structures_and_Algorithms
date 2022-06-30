#include <iostream>

using namespace std;

#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10

typedef int ElemtType;

typedef struct SqList
{
    ElemtType *elem;
    int length;
    int list_size;
}SqList, *Ptr;

typedef Ptr SqListPtr;

enum Status
{
    success, fail, fatal, range_error
};

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

int main()
{
    cout << "hello world" << endl;

    system("pause");
    return 0;
}