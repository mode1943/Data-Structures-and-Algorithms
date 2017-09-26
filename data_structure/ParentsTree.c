#include<stdio.h>
#include<time.h>
#define MAXSIZE 25
/*
 *            A-0
 *       B-1********C-2
 *    D-3        E-4***F-5
 *G-6**H-7**I-8   J-9
 *
 *
 */
typedef int Status;
typedef int ElemType;

typedef struct Tnode
{
    ElemType data;
    int parent;
}Tnode;


typedef struct
{
    Tnode tree[MAXSIZE];
    int r,n;
}Tree;

Status InitTree(Tree *T)
{
    int d,p,i;
    T->r = 0;
    printf("请输入树的结点数:\n");
    scanf("%d", &(T->n));
    printf("请输入节点及双亲的位置:\n");
    for (i=0; i<T->n; i++)
    {
        scanf("%d,%d", &d, &p);
        T->tree[i].data = d;
        T->tree[i].parent = p;
        printf("%d,%d\n", d, p);
    }
}

void FindParent(Tree *T, int i)
{
    if (i>T->n)
    {
        printf("error"); 
    }
    printf("该元素是:%d, 它的双亲位置是:%d\n", T->tree[i].data, T->tree[i].parent);
}

void main()
{
    Tree *T, M;
    T = &M;
    InitTree(T);
    FindParent(T, 2);
}
