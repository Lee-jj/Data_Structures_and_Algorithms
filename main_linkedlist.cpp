#include <iostream>
// #include "LkList.h"
#include "TestLkList.h"

using namespace std;


// 测试链式存储结构的初始化
// int main()
// {
//     Ptr header = NULL;
//     Status s = fail;
//     s = List_Init(&header);
//     if (header == NULL)
//     {
//         if (s != success)
//             printf("Init failed and pointer is void\n");
//         else printf("Init successfully but pointer is void\n");
//     }
//     else printf("header is not void\n");

//     system("pause");
//     return 0;
// }

// 测试链式存储结构的所有功能，主函数从顺序存储结构复制来
int main()
{
    int opt = 0;
    Ptr list = NULL;
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
