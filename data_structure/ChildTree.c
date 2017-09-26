#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

typedef int ElemType;
typedef int Status;

typedef struct CNode
{
    int index;
    struct CNode *next;
}ChildNode;

typedef struct
{
    ElemType data;
    ChildNode *firstchild;
    int parent;
}Tnode;

typedef struct
{
    Tnode node[MAXSIZE];
    int r,n;
}Tree;

Status InitTree(Tree *T)
{
    int i, p, d;
    printf("输入树节点个数:\n");
    scanf("%d", &(T->n));
    T->r = -1;
    printf("输入节点数据及双亲节点索引")
    for (i=0; i<T->n; i++)
    {
        scanf("%d,%d", &d, &p);
        T->node[i].data = d;
        T->node[i].parent = p;

    }
}
