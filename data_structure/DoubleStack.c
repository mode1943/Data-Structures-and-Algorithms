#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;


typedef struct
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}DoubleStack;


DoubleStack *InitStack()
{
    DoubleStack *s;
    s = (DoubleStack*)malloc(sizeof(DoubleStack));
    s->top1 = -1;
    s->top2 = MAXSIZE + 1;

    return s;
}

Status PushStack(DoubleStack *s, ElemType e, int serial)
{
    if (s->top1 + 1 == s->top2)
    {
        return -1;
    }
    if (serial == 1)
    {
        s->top1++;
        s->data[s->top1] = e;
    }
    if (serial == 2)
    {
        s->top2--;
        s->data[s->top2] = e;
    }

    return 1;
}


Status PopStack(DoubleStack *s, int serial)
{
    int e;
    if (serial == 1 && s->top1 == -1)
    {
        return -1;
    }

    if (serial == 2 && s->top2 == MAXSIZE + 1)
    {
        return -1;
    }
    
    if (serial == 1)
    {
        e = s->data[s->top1];
        s->top1--;
    }

    if (serial == 2)
    {
        e = s->data[s->top2];
        s->top2++;
    }

    return e;
}

void main()
{
    DoubleStack *s = InitStack();
    PushStack(s, 36, 1);
    int e1 = PopStack(s, 1);

    PushStack(s, 34, 2);
    int e2 = PopStack(s, 2);

    printf("top1 pop:%d\n", e1);
    printf("top2 pop:%d\n", e2);

}
