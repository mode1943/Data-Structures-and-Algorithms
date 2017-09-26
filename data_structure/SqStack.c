#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 12
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;


SqStack *InitStack()
{
    SqStack *s;
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
    return s;
}

ElemType PushStack(SqStack *s, ElemType e)
{
    if (s->top + 1 == MAXSIZE)
    {
        return -1;
    }

    s->top++;
    s->data[s->top] = e;
    return e;
}

ElemType PopStack(SqStack *s)
{
    ElemType e;
    if (s->top == -1)
    {
        return -1;
    }

    e = s->data[s->top];
    s->top--;
    return e;
}
void main()
{
    SqStack *s = InitStack();
    printf("%d\n", s->top);
    PushStack(s, 12);
    ElemType e = PopStack(s);
    printf("%d\n", e);
}

