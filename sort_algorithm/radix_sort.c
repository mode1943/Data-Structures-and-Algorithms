#include<stdio.h>
#include<stdlib.h>

/*
 * 基数排序
 * 分类 ------------- 内部非比较排序
 * 数据结构 ---------- 数组
 * 最差时间复杂度 ---- O(n * dn)
 * 最优时间复杂度 ---- O(n * dn)
 * 平均时间复杂度 ---- O(n * dn)
 * 所需辅助空间 ------ O(n * dn)
 * 稳定性 ----------- 稳定
 */

const int dn = 3;

int GetDigit(int x, int d) // 获得元素x的第d位数字
{
    int radix[] = {1,1,10,100}; //最大为三位数，所以这里只要到百位就满足了
    return (x/radix[d]) % 10;
}
void CountingSort(int A[], int size, int d) //依据元素的第d位数字，对A数组进行计数排序
{
    int k=100;
    int C[k];
    int i;

    for (i=0; i < k; i++)
    {
        C[i] = 0;
    }

    for (i=0; i < size; i++)
    {
        C[GetDigit(A[i], d)]++;
    }

    for (i=1; i < k; i++)
    {
        C[i] = C[i] + C[i-1];
    }

    int *B = (int*)malloc((size) * sizeof(int));

    for (i=size - 1; i>=0; i--)
    {
        int digit = GetDigit(A[i], d); //元素A[i]当前位数字为dight
        B[--C[digit]] = A[i]; //根据当前位数字，把每个元素A[i]放到它在输出数组B中的正确位置上
        //当再遇到当前位数字同为dight的元素时，会将其放在当前元素的前一个位置上保证计数排序的稳定性
    }

    for (i=0; i<size; i++)
    {
        A[i] = B[i];
    }

    free(B);
}

void RadixSort(int A[], int size) //最低位优先基数排序
{
    int i;

    for (i=1; i<= dn; i++) //从低位到高位
    {
        CountingSort(A, size, i); //依据第d位数字对A进行计数排序
    }
}

void main()
{
    int unsorted[] = {123, 342, 110, 345, 298, 771, 651, 900, 321, 100, 45, 3, 12};
    int size = sizeof(unsorted)/sizeof(int);
    int i;

    RadixSort(unsorted, size);

    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}
