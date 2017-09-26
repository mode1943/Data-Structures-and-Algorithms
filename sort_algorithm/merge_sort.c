#include<stdio.h>

/*
 * 归并排序 
 * 分类 -------------- 内部比较排序
 * 数据结构 ---------- 数组
 * 最差时间复杂度 ---- O(nlogn)
 * 最优时间复杂度 ---- O(nlogn)
 * 平均时间复杂度 ---- O(nlogn)
 * 所需辅助空间 ------ O(n)
 * 稳定性 ------------ 稳定
 *
 */
void Merge(int a[], int left, int middle, int right)
{
    int len = right - left + 1;
    int temp[len];
    int index = 0;
    int i = left;
    int j = middle + 1;

    while (i<=middle && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[index] = a[i];
            i++;
        }
        else
        {
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    
    while (i<=middle)
    {
        temp[index] = a[i];
        index++;
        i++;
    }

    while (j<=right)
    {
        temp[index] = a[j];
        index++;
        j++;
    }
    
    for (i=0; i<len; i++)
    {
        a[left] = temp[i];
        left++;
    }
}
/*
void Merge(int a[], int left, int middle, int right)
{
    int len = right - left + 1;
    int index = 0;
    int i = left;
    int j = middle + 1;
    int temp[len];

    while (i <= middle && j <= right)
    {
        temp[index++] = a[i] <= a[j]? a[i++] : a[j++];
    }

    while (i <= middle)
    {
        temp[index++] = a[i++];
    }

    while (j <= right)
    {
        temp[index++] = a[j++];
    }

    int m;
    for (m=0; m < len; m++)
    {
        a[left++] = temp[m];
    }
}
*/
void MergeSortRecursion(int a[], int left, int right)
{
    if (left == right)
    {
        return;
    }
    int middle = (left + right) / 2;
    MergeSortRecursion(a, left, middle);
    MergeSortRecursion(a, middle+1, right);
    Merge(a, left, middle, right);
}



void main()
{
    int i;
    int unsorted[] = {12, 34, 11, 3, 90, 120, 21, 32, 9, 71, 76};
    int len = sizeof(unsorted)/sizeof(int);
    MergeSortRecursion(unsorted, 0, len - 1);

    printf("after sort:\n");
    for (i=0; i < len; i++)
    {
        printf("%d\n", unsorted[i]);
    }

}
