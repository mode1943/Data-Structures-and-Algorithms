#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode;

BiTNode *CreateBiTree()
{
    char ch;
    BiTNode *T;
    scanf("%c", &ch);
    getchar();
    if (ch=='@')
    {
        T = NULL;
        
    }
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = ch;
        T->lchild=CreateBiTree();
        T->rchild=CreateBiTree();
    }
    return T;
}

void PreOrderTraverse(BiTNode *T)
{
    if (T==NULL)
    {
        return;
    }
    printf("%c\n", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTNode *T)
{
    if (T==NULL)
    {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c\n", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild);
    InOrderTraverse(T->rchild);
    printf("%c\n", T->data);
}

void main()
{
    //BiTnode *T, B;
    //T = &B;
    BiTNode *B = CreateBiTree();
    printf("树前序遍历:\n");
    PreOrderTraverse(B);
    printf("树中序遍历:\n");
    InOrderTraverse(B);
    printf("树后序遍历:\n");
    PostOrderTraverse(B);
    printf("haha\n");
}

