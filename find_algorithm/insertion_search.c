#include<stdio.h>

/*
 * 插值查找
 *
 * --基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，
 *  可以提高查找效率。当然，差值查找也属于有序查找。
 * --查找点计算公式：mid=low+(key-a[low])/(a[high]-a[low])*(high-low)
 * --注意：对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。
 *  反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择。
 *
 * --复杂度分析：查找成功或者失败的时间复杂度均为O(log2(log2n))。
 *
 */

void swap(int A[], int m, int n)
{
    int temp;
    temp = A[m];
    A[m] = A[n];
    A[n] = temp;
}

int Partition(int A[], int left, int right)
{
    int prio = right;
    int tail = left - 1;
    int i;

    for (i=left; i<right; i++)
    {
        if (A[i] <= A[prio])
        {
            swap(A, ++tail, i);
        }
    }
    swap(A, tail + 1, right);
    return tail + 1;
}

void QuickSort(int A[], int left, int right)
{
    int prio;
    if (left < right)
    {
        prio = Partition(A, left, right);
        QuickSort(A, left, prio - 1);
        QuickSort(A, prio + 1, right);
    }
}


int InsertionSearch(int A[], int low, int high, int key)
{
    int middle = low + (key - A[low])/(A[high] - A[low]) * (high - low);
    
    if (A[middle] == key)
    {
        return middle;
    }

    if (A[middle] > key)
    {
        return InsertionSearch(A, low, middle - 1, key);
    }

    if (A[middle] < key)
    {
        return InsertionSearch(A, middle + 1, high, key);
    }
}


void main()
{
    int i;
    int unsorted[] = {12, 56, 22, 90, 45, 32, 88, 66, 11};
    int size = sizeof(unsorted)/sizeof(int);
     
    QuickSort(unsorted, 0, size - 1);
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
    int index = InsertionSearch(unsorted, 0, size-1, 66);
    printf("%d\n", index);

}
