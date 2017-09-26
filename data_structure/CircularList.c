#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}LinkList;

LinkList *CreateList(Status size)
{
    int i;
    LinkList *head, *p, *L, *tail;
    head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    p = head;
    
    for (i=0; i<size; i++)
    {
        L = (LinkList*)malloc(sizeof(LinkList));
        p->next = L;
        p->data = 12;
        p = L;
    }
    p->next = head;
    tail = p;
    
    return tail;
}

void main()
{
    int n = 5;
    LinkList *p = CreateList(n);
    printf("%d\n", p->next->next->data);
}


