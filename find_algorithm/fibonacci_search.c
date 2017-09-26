#include<stdio.h>

/*
 *
 *斐波那契查找
 *
 * --基本思想：也是二分查找的一种提升算法，通过运用黄金比例的概念在数列中选择查找点进行查找，
 * 提高查找效率。同样地，斐波那契查找也属于一种有序查找算法
 *
 * --斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。
 *  他要求开始表中记录的个数为某个斐波那契数小1，及n=F(k)-1;
 * 
 * 开始将key值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1),比较结果也分为三种:
 * 1.key==F(k-1)，mid位置的元素即为所求
 * 2.key>F(k-1), low=mid+1,k-=2
 * 3.key<F(k-1), high=mid-1,k-=1
 *
 * --说明: low=mid+1说明待查找的元素在[mid+1,high]范围内，
 *  k-=2 说明范围[mid+1,high]内的元素个数为n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个，所以可以递归的应用斐波那契查找。
 *
 *  low=mid+1说明待查找的元素在[low,mid-1]范围内，
 *  k-=1 说明范围[low,mid-1]内的元素个数为F(k-1)-1个，所以可以递归 的应用斐波那契查找。
 *
 * --复杂度分析：最坏情况下，时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)
 */

void Merge(int A[], int left, int middle, int right)
{
    int index=0;
    int len = right - left + 1;
    int temp[len];
    int i = left;
    int j = middle + 1;

    while (i <= middle && j <= right)
    {
        if (A[i] <= A[j])
        {
            temp[index++] = A[i];
            i++;
        }
        else
        {
            temp[index++] = A[j];
            j++;
        }
    }
    
    while (i <= middle)
    {
        temp[index++] = A[i];
        i++;
    }
    
    while (j <= right)
    {
        temp[index++] = A[j];
        j++;
    }
    
    for (i=0; i<len; i++)
    {
        A[left++] = temp[i];
    }


}

void MergeSort(int A[], int left, int right)
{   
    if (left == right)
    {
        return;
    }
    int middle = (left + right)/2;
    MergeSort(A, left, middle);
    MergeSort(A, middle + 1, right);
    Merge(A, left, middle, right);
}

void Fibonacci(int A[], int size)
{
    int i;
    A[0] = 1;
    A[1] = 1;
    
    for (i=2; i<size; i++)
    {
        A[i] = A[i-1] + A[i-2];
    }
}

int FibonacciSearch(int A[], int size, int key) //A为要查找的数组,size为要查找的数组长度,key为要查找的关键字
{
    int i;
    int low = 0;
    int high = size - 1;
    
    int len = 12;
    int F[len];
    Fibonacci(F, 12);  //构造一个斐波那契数组F

    int k=0;
    while (size > F[k] - 1)  //计算size位于斐波那契数列的位置
    {
        ++k;
    }

    for (i=size; i<F[k]-1; ++i)  //将数组A扩展到F[k]-1的长度
    {
        A[i] = A[size];
    }

    while (low <= high)
    {
        int middle = low + F[k-1] - 1;

        if (key < A[middle])
        {
            high = middle - 1;
            k--;
        }

        else if (key > A[middle])
        {
            low = middle + 1;
            k = k - 2;
        }
        else
        {
            if (middle < size)
            {
                return middle;     //若相等则说明mid即为查找到的位置
            }
            else
            {
                return size - 1;     //若mid>=n则说明是扩展的数值,返回n-1
            }
        }
    }
}



void main()
{
    int i;
    int unfind[] = {13, 35, 32, 99, 41, 45, 77, 10, 51};
    int size = sizeof(unfind)/sizeof(int);

    MergeSort(unfind, 0, size - 1);

    for (i=0; i<size; i++)
    {
        printf("%d\n", unfind[i]);
    }
    int index = FibonacciSearch(unfind, size-1, 45);
    printf("%d\n", index);


}

