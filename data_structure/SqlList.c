#include<stdio.h>
#define MAXSIZE 50
typedef int ElemType;

//定义一个线性表结构
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqlList;

int GetElem(SqlList *L, int i, int *e)
{
    if (L->length == 0 || i<1 || i>L->length)
    {
        return -1;
    }
    *e = L->data[i-1];
    return 1;
}

int InsertList(SqlList *L, int i, int e)
{
    if (i<1 || i>L->length || L->length==MAXSIZE)
    {
        return -1;
    }
    
    int pos;
    for (pos=i-1; pos<L->length; pos++)
    {
        L->data[pos+1] = L->data[pos];
    }
    L->data[i-1] = e;
    L->length++;
    return 1;
}

int ListDelete(SqlList *L, int i, int *e)
{
    if (i<1 || i>L->length)
    {
        return -1;
    }
    
    *e = L->data[i-1];
    int pos;
    for (pos=i-1; pos<L->length-1; pos++)
    {
        L->data[pos] = L->data[pos+1];
    }
    L->length--;
    return 1;
} 

SqlList ListInit(int A[], int size)
{
    int i;
    SqlList L;
    L.length = size;

    for (i=0; i<L.length; i++)
    {
        L.data[i] = A[i];
    }
    return L;
}

void main()
{
    int unlist[] = {11, 45, 99, 12, 43, 29};
    int size = sizeof(unlist)/sizeof(int);
    SqlList L1 = ListInit(unlist, size);
    SqlList *L = &L1;
    
    int *e, out;
    e = &out;
    GetElem(L, 3, e);
    InsertList(L, 2, 68);
    //ListDelete(L, 2, e);
    printf("第%d个元素是:%d\n", 3, *e);
    printf("第%d个元素是:%d\n", 2, L->data[2]);
    //printf("删除第%d个元素是:%d\n", 2, *e);
    
}
