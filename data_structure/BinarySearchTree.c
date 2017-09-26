#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

void InorderTraverse(BiTree T)
{
    if (T==NULL)
    {
        return;
    }
    InorderTraverse(T->lchild);
    printf("%d\n", T->data);
    InorderTraverse(T->rchild);
}

int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)
    {
        *p = f;
        return -1;
    }

    else if (key == T->data)
    {
        *p = T;
        return 1;
    }

    else if (key < T->data)
    {
        T = T->rchild;
        f = T;
        return SearchBST(T, key, f, p);
    }
    else
    {
        T = T->rchild;
        f = T;
        return SearchBST(T, key, f, p);
    }
}

int InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
        {
            *T = s;
        }
        else if (key < p->data)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
        return 1; 
    }
    else
    {
        return -1;
    }
}

BiTree CreateBST(int A[], int n)
{
    int i;
    BiTree T = NULL;
    
    for (i=0; i<n; i++)
    {
        InsertBST(&T, A[i]);
    }
    return T;
}

void main()
{
    int a[] = {23, 45, 12, 99, 52, 18, 62, 89, 36, 20};
    int size = sizeof(a)/sizeof(int);
    BiTree M = CreateBST(a, size);
    InorderTraverse(M);    
}
