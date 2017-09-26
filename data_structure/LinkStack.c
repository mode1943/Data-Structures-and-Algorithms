#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef int Status;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}LinkStackNode;

typedef struct LinkStack
{
    LinkStackNode *top;
    int count;
}LinkStack;

Status Push(LinkStack *S, ElemType e)
{
    LinkStackNode *L = (LinkStackNode*)malloc(sizeof(LinkStackNode));
    L->data = e;
    L->next = S->top;
    S->top = L;
    S->count++;
    return 1;
}

Status StackEmpty(LinkStack *S)
{
    if (S->count==0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
Status Pop(LinkStack *S, ElemType *e)
{
    if (StackEmpty(S)>0)
    {
        return -1;
    }
    LinkStackNode *p = S->top;
    *e = p->data;
    S->top = p->next;
    S->count--;
    free(p);
    return 1;
}

void main()
{
    int i, n=10;
    LinkStack m, *s;
    m.count = 0;
    s = &m;
    srand((unsigned int) time(NULL));
    for (i=0; i<10; i++)
    {
        Push(s, rand()%101);
    }
    printf("stack top is:%d\n", s->top->data);
    printf("stack top is:%d\n", s->count);
    
    int *out, o;
    out = &o;
    while (s->count!=0)
    {
        Pop(s, out);
        printf("pop:%d\n", *out);
    }
}
