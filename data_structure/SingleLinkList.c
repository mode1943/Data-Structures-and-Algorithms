#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node *next;
}LinkList;

//尾插法
LinkList *CreateLink1(int size)
{
    int i;
    LinkList *head, *p, *l; 
    head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    p = head;
    
    srand((unsigned int) time(NULL));
    for (i=0; i<size; i++)
    {
        l = (LinkList*)malloc(sizeof(LinkList));
        p->next = l;
        p->data = rand()%101;
        p = l;
    }
    p->next = NULL;

    return head;
}

//头插法
LinkList *CreateLink2(int size)
{
    int i;
    LinkList *L, *p;
    L = (LinkList*)malloc(sizeof(LinkList));
    L->next = NULL;
    
    srand((unsigned int) time(NULL));
    for (i=0; i<size; i++)
    {
        p = (LinkList*)malloc(sizeof(LinkList));
        p->data = rand()%101;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

Status GetElem(LinkList *L, int i)
{
    int j=1;
    LinkList *p;

    p = L->next;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    
    if (!p && j>i)
    {
        return -1;
    }
    return p->data;
}

Status ListInsert(LinkList *L, int n, int e)
{
    int i=1;
    LinkList *p, *m;
    p = L->next;

    while (p && i<n-1)
    {
        p = p->next;
        i++;
    }
    if (!p && i>n-1)
    {
        return -1;
    }
    m = (LinkList*)malloc(sizeof(LinkList));
    m->data = e;
    m->next = p->next;
    p->next = m;
    return 1;
}

Status ListDelete(LinkList *L, int n, int *e)
{
    int i=1;
    LinkList *p, *m;
    p = L->next;
    
    while(p && i<n-1)
    {
        p = p->next;
        i++;
    }

    if (!p && i>n-1)
    {
        return -1;
    }
    m = p->next;
    *e = m->data;
    p->next = m->next;
    free(m);
}

void main()
{
    int i;
    int length=20;
    LinkList *head = CreateLink2(length);
    LinkList *p;
    p = head;
    for (i=0; i<length; i++)
    {
        if (p->next != NULL)
        {
            p = p->next;
            printf("%d\n", p->data);

        }
    }
    int value = GetElem(head, 3);
    printf("查找的元素为:%d\n", value);
    ListInsert(head, 3, 26);
    int value1 = GetElem(head, 3);
    printf("查找的元素为:%d\n", value1);
    int *e, m;
    e = &m;
    ListDelete(head, 3, e);
    printf("Deleted ele is:%d\n", *e);
    int value2 = GetElem(head, 3);
    printf("查找的元素为:%d\n", value2);

}
