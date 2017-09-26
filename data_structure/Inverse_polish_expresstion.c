#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode;

typedef struct StackLink
{
    StackNode *top;
    int count;
}StackLink;



