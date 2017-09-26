#include<stdio.h>
/*
 *
 *堆排序
 *分类 -------------- 内部比较排序
 *数据结构 ---------- 数组
 *最差时间复杂度 ---- O(nlogn)
 *最优时间复杂度 ---- O(nlogn)
 *平均时间复杂度 ---- O(nlogn)
 *所需辅助空间 ------ O(1)
 *稳定性 ------------ 不稳定
 */

void swap(int A[], int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void heapify(int A[], int i, int size)
{
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int max = i;

    if (left_child < size && A[left_child] > A[max])
    {
        max = left_child;  
    }

    if (right_child < size && A[right_child] > A[max])
    {
        max = right_child;
    }

    if (max != i)
    {
        swap(A, i, max);
        heapify(A, max, size);
    }
}


int build_heap(int A[], int size)
{
    int i, heap_size=size;
    for (i=heap_size/2 - 1; i >= 0; i--)
    {
        heapify(A, i, heap_size);
    }

    return heap_size;
}

void HeapSort(int A[], int size)
{
    int heap_size = build_heap(A, size);
    while (heap_size > 1)
    {
        swap(A, 0, --heap_size);
        heapify(A, 0, heap_size);
    }
}


void main()
{
    int unsorted[] = {12, 20, 11, 2, 56, 89, 31, 66, 120, 32, 45};
    int size = sizeof(unsorted)/sizeof(int);
    HeapSort(unsorted, size);

    printf("after sort:\n");
    int i;
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}
