#include<stdio.h>
/*
 *
 * 选择排序
 * 分类 -------------- 内部比较排序
 * 数据结构 ---------- 数组
 * 最差时间复杂度 ---- O(n^2)
 * 最优时间复杂度 ---- O(n^2)
 * 平均时间复杂度 ---- O(n^2)
 * 所需辅助空间 ------ O(1)
 * 稳定性 ------------ 不稳定
 */

void swap(int t[], int min , int i)
{
    int temp;
    temp = t[i];
    t[i] = t[min];
    t[min] = temp;
}

void Select_Sort(int a[], int len)
{
    int i, j, min;
    
    for (i=0; i<len-1; i++)
    {
        min = i;

        for (j=i+1; j<len; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        
        if (min != i)
        {
            swap(a, min, i);
        }
    }

}

void main()
{
    int i;
    int unsorted[] = {12, 88, 98, 34, 56, 23, 11, 90, 37, 100, 345, 54, 1};

    int len = sizeof(unsorted)/sizeof(int);

    printf("unsorted:\n");

    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }

    Select_Sort(unsorted, len);
    printf("sorted:\n");
    
    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
}
