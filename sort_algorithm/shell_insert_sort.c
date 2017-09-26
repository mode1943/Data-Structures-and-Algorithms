#include<stdio.h>


void shell_sort(int a[], int size, int grap)
{
    while(grap >= 1)
    {
        int i;
        for(i=grap; i < size; i++)
        {
            int j = i - grap;
            int temp = a[i];

            while (j>=0 && a[j] > temp)
            {
                a[j+grap] = a[j];
                j -= grap;
            }

            a[j+grap] = temp;
        }
        
        grap = grap / 2;
    }
}


void main()
{
    int a[] = {12, 33, 1, 40, 23, 66, 41, 40, 77, 34};
    int size = sizeof(a)/sizeof(int);
    int grap = size / 2;
    int t;
    
    printf("shell排序前:\n");
    for(t=0; t < size; t++)
    {
        printf("%d\n", a[t]);
    }
    
    shell_sort(a, size, grap);
    
    printf("shell排序后:\n");
    for (t=0; t < size; t++)
    {
        printf("%d\n", a[t]);
    }
}

