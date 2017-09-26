#include<stdio.h>

/*
 *二分插入排序(折半排序)
 *分类 --------------> 内部比较排序
 *数据结构 ----------> 数组
 *最差时间复杂度 ----> O(n^2)
 *最优时间复杂度 ----> O(nlogn)
 *平均时间复杂度 ----> O(n^2)
 *所需辅助空间 ------> O(1)
 *稳定性 ------------> 稳定
 *
 *
*/

void Binary_Insert_Sort(int a[], int size)
{
    int i, j, left, middle, right, unsorted;

    for (i=1; i < size; i++)
    {
        unsorted = a[i];
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            middle = (left + right)/2;
            if (a[middle] > unsorted)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        for (j=i-1; j>=left; j--)
        {
            a[j+1] = a[j];
        }
        a[left] = unsorted;
    }
}

void main()
{
    int i;
    int a[] = {12, 20, 1, 0, 3, 88, 123, 56, 45, 38, 89, 113, 3};
    int size = sizeof(a)/sizeof(int);

    printf("unsorted:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
    
    Binary_Insert_Sort(a, size);
    printf("sorted:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
}
    
