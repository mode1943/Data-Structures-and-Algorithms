#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *prio;
    struct Node *next;
}LinkList;

LinkList *InitList()
{
    LinkList *L;
    L = (LinkList*)malloc(sizeof(LinkList));
    L->next = L;
    L->prio = L;
    return L;
}

Status CreateLink(LinkList *L, int size)
{
    int i;
    LinkList *p, *m;
    srand((unsigned int) time(NULL));
    if (!L)
    {
        return -1;
    }
    m = L;
    for (i=0; i<size; i++)
    {
        p = (LinkList*)malloc(sizeof(LinkList));
        m->next = p;
        p->data = rand()%101;
        p->next = L;
        p->prio = m;
        m = p;
    }
    L->prio = m;
    return 1;

}

Status GetLinkLength(LinkList *L)
{
    int i=0;
    LinkList *p, *m;
    m = L;
    while (m->next != L)
    {
        p = m->next;
        m = p;
        ++i;
    }

    return i;
}

Status InsertLink(LinkList *L, int n, int e)
{
    int i;
    LinkList *p, *m, *temp;
    m = L;
    for (i=1; i<n; i++)
    {
        p = m->next;
        if (p==L)
        {
            return -1;
        }
        m = p;
    }
    temp = (LinkList*)malloc(sizeof(LinkList));
    temp->data = e;
    temp->prio = m;
    temp->next = m->next;
    m->next->prio = temp;
    m->next = temp;
    
    return 1;

}

Status LinkDelete(LinkList *L, int n, ElemType *e)
{
    int i;
    LinkList *p, *m;
    m = L;
    int len = GetLinkLength(L);
    if (n<1 || n>len)
    {
        return -1;
    }
    for (i=1; i<len; i++)
    {
        p = m->next;
        m = p;
    }
    p->prio->next=p->next;
    p->next->prio = p->prio;
    *e = p->data;
    free(p);
    
    return 1;
}
void main()
{
    int i;
    int size = 6;
    LinkList *c, *n, *m, *p, *L = InitList();
    CreateLink(L, size);
    printf("第一个节点的值:%d\n", L->next->data);
    printf("最后一个节点的值是:%d\n", L->prio->data);
    //InsertLink(L, 5, 100); 
    m = L;
    for (i=0; i<size; i++)
    {
        c = m->next;
        m = c;
        if (i<1)
        {
            printf("第%d个元素的前驱是:null, 当前是:%d, 后继是:%d\n", i+1, c->data, c->next->data);
        }
        else if (i>=size-1)
        {
            printf("第%d个元素的前驱是:%d, 当前是:%d, 后继是:null\n", i+1, c->prio->data, c->data);
        }
        else
        {
            printf("第%d个元素的前驱是:%d, 当前是:%d, 后继是:%d\n", i+1, c->prio->data, c->data, c->next->data);
        }
    }

    int *e, t;
    e = &t;
    //LinkDelete(L, 3, e);
    printf("%d\n", *e);
}

