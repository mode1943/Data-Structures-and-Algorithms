#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}LinkNode;

typedef struct LinkQueue
{
    LinkNode *front, *rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    Q->front = Q->rear = p;
    Q->front->next = NULL;
    return 1;
}

Status EnQueue(LinkQueue *Q, ElemType e)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = NULL;
    if (Q->front->next == NULL)
    {
        Q->front->next = p;    
    }
    Q->rear->next = p;
    Q->rear = p;
    return 1;
}

Status DeQueue(LinkQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        return -1;
    }
    LinkNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;

    if (Q->front->next == p)
    {
        Q->front = Q->rear;
    }
    free(p);
    return 1;
}


void main()
{
    LinkQueue *m = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(m);
    int i, n = 5;
    srand((unsigned int) time(NULL));
    for (i=0; i<n; i++)
    {
        EnQueue(m, rand()%101);
        printf("INput queue:%d\n", m->rear->data);
    }
    
    int *out, o;
    out = &o;
    for (i=0; i<n; i++)
    {
        DeQueue(m, out);
        printf("output queue;%d\n", *out);
    }
}
