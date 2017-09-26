#include<stdio.h>


void swap(int a[], int x, int y)
{
    int temp;
    temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void Cocktail_Sort(int a[], int len)
{
    int left, right, i;

    left = 0;
    right = len - 1;

    while (left < right)
    {
        for(i=left; i<right; i++)
        {
            if (a[i] > a[i+1])
            {
                swap(a, i, i+1);
            }
        }
        right--;

        for (i=right; i>left; i--)
        {
            if (a[i] < a[i-1])
            {
                swap(a, i, i-1);
            }
        }

        left++;
    }

}


void main()
{
    int i;
    int unsorted[] = {23, 22, 90, 389, 12, 789, 43, 0, 139, 9};
    int len = sizeof(unsorted)/sizeof(int);

    printf("unsorted:\n");
    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
    
    Cocktail_Sort(unsorted, len);
    printf("sorted:\n");
    
    for (i=0; i<len; i++)
    {
        printf("%d\n", unsorted[i]);
    }
}
