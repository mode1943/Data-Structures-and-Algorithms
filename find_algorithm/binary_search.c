#include<stdio.h>

/*
 *二分查找
 *
 * --说明：元素必须是有序的，如果是无序的则要先进行排序操作
 *
 * --基本思想：也称为是折半查找，属于有序查找算法。用给定值k先与中间结点的关键字比较，
 * 中间结点把线形表分成两个子表，若相等则查找成功；
 * 若不相等，再根据k与该中间结点关键字的比较结果确定下一步查找哪个子表，
 * 这样递归进行，直到查找到或查找结束发现表中没有这样的结点。
 *
 * --复杂度分析：最坏情况下，关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)；
 *
 * --注意:折半查找的前提条件是需要有序表顺序存储，
 *  对于静态查找表，一次排序后不再变化，折半查找能得到不错的效率。
 *  但对于需要频繁执行插入或删除操作的数据集来说，维护有序的排序会带来不小的工作量，那就不建议使用。
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

    for (i=left; i < right; i++)
    {
        if (A[i] <= A[prio])
        {
            swap(A, ++tail, i);
        }
    }
    swap(A, tail+1, right);

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

/*
int BinarySearch1(int A[], int key, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (A[middle] = key)
        {
            return middle;
        }

        if (A[middle] > key)
        {    
            high = middle - 1;
        }

        if (A[middle] < key)
        {
            low = middle + 1;
        }
    }

    return -1;
}
*/
int BinarySearch2(int A[], int low, int high, int key)
{   
    int middle = (low + high)/2;
    if (A[middle] == key)
    {
        return middle;
    }
    if (A[middle] > key)
    {
        return BinarySearch2(A, low, middle - 1, key);
    }
    if (A[middle] < key)
    {
        return BinarySearch2(A, middle + 1, high, key);
    }

}


void main()
{
    int i;
    int unfind[] = {12, 45, 22, 89, 90, 43, 51, 33, 66};
    int size = sizeof(unfind)/sizeof(int);
    
    QuickSort(unfind, 0, size-1);
    
    for (i=0; i<size; i++)
    {
        printf("%d\n", unfind[i]);
    }
    int index = BinarySearch2(unfind, 0, size-1, 43);
    printf("index: %d\n", index);
}
