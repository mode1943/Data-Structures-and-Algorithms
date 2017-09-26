#include<stdio.h>
#include<stdlib.h>

/*
 *基数排序
 * 分类 ------------ 内部非比较排序
 * 数据结构 --------- 数组
 * 最差时间复杂度 ---- O(n + k)
 * 最优时间复杂度 ---- O(n + k)
 * 平均时间复杂度 ---- O(n + k)
 * 所需辅助空间 ------ O(n + k)
 * 稳定性 ----------- 稳定
 *
 *
 */

void CountingSort(int A[], int size)
{
    int k = 100; //基数为100，排序[0,99]内的整数
    int C[k]; //计数数组
    int i;
    for (i=0; i<k; i++) //初始化，将数组C中的元素置0
    {
        C[i] = 0;
    }

    for (i=0; i<size; i++) //使C[i]保存着等于i的元素个数
    {
        C[A[i]]++;
    }

    for (i=1; i<k; i++) //使C[i]保存着小于等于i的元素个数，排序后元素i就放在第C[i]个输出位置上
    {
        C[i] = C[i] + C[i-1];
    }

    int *B = (int*)malloc((size) * sizeof(int)); //分配临时空间,长度为n，用来暂存中间数据
    
    for (i=size-1; i>=0; i--) //从后向前扫描保证计数排序的稳定性(重复元素相对次序不变)
    {
        B[--C[A[i]]] = A[i]; //把每个元素A[i]放到它在输出数组B中的正确位置上
    }                        //当再遇到重复元素时会被放在当前元素的前一个位置上保证计数排序的稳定性

    for (i=0; i<size; i++) //把临时空间B中的数据拷贝回A
    {
        A[i] = B[i];
    }
    free(B); //释放临时空间
}

void main()
{
    int unsorted[] = {12, 1, 23, 2, 13, 40, 35, 23, 60, 21, 34, 35, 12}; //针对计数排序设计的输入，每一个元素都在[0,100]上且有重复元素
    int size = sizeof(unsorted)/sizeof(int);
    int i;

    CountingSort(unsorted, size);

    printf("after sort:\n");
    for (i=0; i<size; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}
