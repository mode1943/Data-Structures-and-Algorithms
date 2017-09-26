#include<stdio.h>

/*
 * 直接插入排序
 * 分类 --------------> 内部比较排序.
 * 数据结构 ----------> 数组.
 * 最差时间复杂度 ----> 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2).
 * 最优时间复杂度 ----> 最好情况为输入序列是升序排列的,此时时间复杂度O(n).
 * 平均时间复杂度 ----> O(n^2).
 * 所需辅助空间 ------> O(1).
 * 稳定性 ------------> 稳定
 *
*/ 
void Insert_Sort(int a[], int size)
{
    int i, j, temp;
    for (i=0; i<size; i++)
    {
        for(j=i; j>0; j--)
        {
            if (a[j-1] > a[j])
            {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        
        }
    }
}

void main()
{
    int i;
    int unsorted[] = {12, 23, 1, 4, 90, 21, 13, 67};
    int size = sizeof(unsorted)/sizeof(int);

    printf("unsorted numbers:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }

    Insert_Sort(unsorted, size);
    
    printf("sorted numbers:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }


}

