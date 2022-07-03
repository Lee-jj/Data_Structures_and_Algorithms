#include <iostream>
#include "TestSqList.h"

using namespace std;

int main()
{
    int opt = 0;
    SqList list;
    int pos, size;
    ElemType e, *data;
    Status s;

    while (opt != 6)
    {
        printf("*** Please input your choice: ***\n");

        printf("1.Test Create List\n");
        printf("2.Test Clear List\n");
        printf("3.Test Retrival Prior and Next\n");
        printf("4.Test Locate an element\n");
        printf("5.Get the List Size\n");
        printf("6.Quit\n");

        scanf("%d", &opt);
        switch (opt)
        {
        case 1 :
            printf("Please input the size of the List:\n");
            scanf("%d", &size);
            data = (ElemType *)malloc(size * sizeof(ElemType));
            if (data == NULL) break;
            printf("Please input the elements:\n");
            for (int i = 0; i < size; i++)
                scanf("%d", &data[i]);
            s = Test_CreateList(&list, data, size);
            if (s != success)
                printf("Create List failed\n");
            free(data);     // 用完data后释放分配的内存
            List_Destory(&list); // 释放List_Init使用的内存
            break;
        case 2 :
            printf("Please input the size of the List:\n");
            scanf("%d", &size);
            data = (ElemType *)malloc(size * sizeof(ElemType));
            if (data == NULL) break;
            printf("Please input the elements:\n");
            for (int i = 0; i < size; i++)
                scanf("%d", &data[i]);
            s = Test_CreateList(&list, data, size);
            if (s == success)
            {
                s = Test_ClearList(&list);
                if (s == success)
                    printf("*****Clear List successfully*****\n");
            }
            free(data);     // 用完data后释放分配的内存
            List_Destory(&list); // 释放List_Init使用的内存
            break;
        case 3 :
            printf("Please input the size of the List:\n");
            scanf("%d", &size);
            data = (ElemType *)malloc(size * sizeof(ElemType));
            if (data == NULL) break;
            printf("Please input the elements:\n");
            for (int i = 0; i < size; i++)
                scanf("%d", &data[i]);
            s = Test_CreateList(&list, data, size);
            if (s == success)
            {
                printf("Please enter the position you want check and we can find the prior and next of it:\n");
                scanf("%d", &pos);
                s = Test_RetrivalPriorNext(&list, pos);
            }
            free(data);     // 用完data后释放分配的内存
            List_Destory(&list); // 释放List_Init使用的内存
            break;
        case 4 :
            printf("Please input the size of the List:\n");
            scanf("%d", &size);
            data = (ElemType *)malloc(size * sizeof(ElemType));
            if (data == NULL) break;
            printf("Please input the elements:\n");
            for (int i = 0; i < size; i++)
                scanf("%d", &data[i]);
            s = Test_CreateList(&list, data, size);
            if (s == success)
            {
                printf("Please enter an element you want check:\n");
                scanf("%d", &e);
                s = Test_Locate(&list, e);
            }
            free(data);     // 用完data后释放分配的内存
            List_Destory(&list); // 释放List_Init使用的内存
            break;
        case 5 :
            printf("Please input the size of the List:\n");
            scanf("%d", &size);
            data = (ElemType *)malloc(size * sizeof(ElemType));
            if (data == NULL) break;
            printf("Please input the elements:\n");
            for (int i = 0; i < size; i++)
                scanf("%d", &data[i]);
            s = Test_CreateList(&list, data, size);
            if (s == success)
            {
                Test_Size(&list);
            }
            free(data);     // 用完data后释放分配的内存
            List_Destory(&list); // 释放List_Init使用的内存
            break;
        case 6 :
            printf("********** Quit Program **********\n");
            break;
        default:
            printf("********** Please enter the specified number **********\n");
            break;
        }
    }
    
    system("pause");
    return 0;
}
