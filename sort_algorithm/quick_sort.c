#include<stdio.h>


void swap(int a[], int m, int n)
{
    int temp;
    temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}

int Partition(int a[], int left, int right)
{
    int prio = a[right];
    int tail = left - 1;
    int i;
    for (i=left; i < right; i++)
    {
        if (a[i] < prio)
        {
            swap(a, ++tail, i);
        }
    }

    swap(a, tail + 1, right);

    return tail + 1;
}

void QuickSort(int a[], int left, int right)
{
    int prio;
    if(left < right)
    {
        prio = Partition(a, left, right);
        QuickSort(a, left, prio - 1);
        QuickSort(a, prio + 1, right);
    }
}

void main()
{
    int i;
    int unsorted[] = {12, 100, 1, 23, 32, 11, 99, 459, 64, 6};
    int len = sizeof(unsorted)/sizeof(int);
    QuickSort(unsorted, 0, len - 1);
    
    printf("after sort:\n");
    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}
