#include<stdio.h>
#include<time.h>
#define MAXSIZE 10
typedef int ElemType;
typedef int Status;

typedef struct SqQueue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return 1;
}

Status QueueSize(SqQueue *Q)
{
    return (Q->front + Q->rear - MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return -1;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % MAXSIZE;
    return 1;
}

Status DeQueue(SqQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        return -1;
    }
    
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

void main()
{
    SqQueue *m, s;
    m = &s;
    int i,n = 5;
    int *out, o;
    out = &o;
    InitQueue(m);
    srand((unsigned int) time(NULL));
    for (i=0; i<n; i++)
    {
        EnQueue(m, rand()%101);
        printf("%d\n", m->data[m->rear - 1]);
    }
    
    for (i=0; i<n; i++)
    {
        DeQueue(m, out);
        printf("out queue:%d\n", *out);
    }
}
