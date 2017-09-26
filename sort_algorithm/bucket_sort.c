#include<stdio.h>
#include<stdlib.h>
#define BN 5  //这里排序[0,49]的元素，使用5个桶就够了，也可以根据输入动态确定桶的数量
//const int bn = 5;
/*
 * 桶排序
 * 分类 ------------- 内部非比较排序
 * 数据结构 --------- 数组
 * 最差时间复杂度 ---- O(nlogn)或O(n^2)，只有一个桶，取决于桶内排序方式
 * 最优时间复杂度 ---- O(n)，每个元素占一个桶
 * 平均时间复杂度 ---- O(n)，保证各个桶内元素个数均匀即可
 * 所需辅助空间 ------ O(n + bn)
 * 稳定性 ----------- 稳定
 *
 */

int C[BN];    //计数数组，存放桶的边界信息

void InsertionSort(int A[], int left, int right)
{
    int i;
    for (i=left + 1; i<=right; i++)
    {
        int get = A[i];
        int j = i -1;

        while (j>=left && A[j] > get)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = get;
    }
}

int MapBucket(int x)   //映射函数f(x)，作用相当于快排中的Partition，把大量数据分割成基本有序的数据块
{
    return x / 10;
}


int Counting(int A[], int size)
{
    int i;
    for (i=0; i<BN; i++)
    {
        C[i] = 0;
    }

    for (i=0; i<size; i++) //使C[i]保存着i号桶中元素的个数
    {
        C[MapBucket(A[i])]++;
    }

    for (i=1; i<BN ; i++)   //定位桶边界：初始时，C[i]-1为i号桶最后一个元素的位置
    {
        C[i] = C[i] + C[i-1];
    }

    int *B = (int*)malloc((size)*sizeof(int));

    for (i=size-1; i>=0; i--)   //从后向前扫描保证计数排序的稳定性(重复元素相对次序不变)
    {
        int bucket = MapBucket(A[i]);  //元素A[i]位于b号桶
        B[--C[bucket]] = A[i];
    }

    for (i=0; i<size; i++)
    {
        A[i] = B[i];
    }

    free(B);
}


void BucketSort(int A[], int size)
{
    int i, left, right;
    Counting(A, size); //利用计数排序确定各个桶的边界（分桶）
    
    for (i=0; i<BN; i++)
    {
        left = C[i];  //C[i]为i号桶第一个元素的位置
        right = (i == BN - 1 ? size-1 : C[i+1] - 1);  //C[i+1]-1为i号桶最后一个元素的位置
        
        if (left < right) //对元素个数大于1的桶进行桶内插入排序
        {
            InsertionSort(A, left, right);
        }
    }
}


void main()
{
    int i;
    int unsorted[] = {38, 24, 32, 41, 46, 23, 18};
    int size = sizeof(unsorted)/sizeof(int);

    BucketSort(unsorted, size);
    printf("after sort:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
}
