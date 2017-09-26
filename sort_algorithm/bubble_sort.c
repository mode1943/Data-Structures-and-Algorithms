#include<stdio.h>

/*
 * 冒泡排序
 * 分类 -------------- 内部比较排序
 * 数据结构 ---------- 数组
 * 最差时间复杂度 ---- O(n^2)
 * 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
 * 平均时间复杂度 ---- O(n^2)
 * 所需辅助空间 ------ O(1)
 * 稳定性 ------------ 稳定
 */


void swap(int a[], int x, int y)
{
    int temp;

    temp = a[x];
    a[x] = a[y];
    a[y] = temp;

}


void Bubble_Sort(int a[], int len)
{
    int i, j;

    for (i=0; i<len-1; i++)
    {
        for (j=0; j<len-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a, j, j+1);
            }
        }

    }
    
}


void main()
{
    int i;
    int unsorted[] = {12, 45, 1, 89, 90, 22, 34, 2, 50, 100};
    int len = sizeof(unsorted)/sizeof(int);

    printf("unsorted:\n");
    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
    Bubble_Sort(unsorted, len);

    printf("sorted:\n");
    for(i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}


