#include"quickSort.h"
#include<stdio.h>
#include<stdlib.h>

int isSorted(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
        
    }
    return 1;
}

int getPartitionIndex(int *a, int n)
{
    int x = a[0];
    int temp;
    int i = -1;
    int j = n;
    while (1)
    {
        do
        {
            j--;
        } while (a[j] > x);
        do
        {
            i++;
        } while (a[i] < x);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            return j;
            
            
        }
    }
    
    // int front = 0;
    // int back = n - 1;
    // int temp;
    // while (1)
    // {
    //     while(a[front] < pivot)
    //     {
    //         front++;
    //     }
    //     while (a[back] > pivot)
    //     {
    //         back--;
    //     }

        
    //     if (front < back)
    //     {
    //         temp = a[front];
    //         a[front] = a[back];
    //         a[back] = temp;
    //     }
    //     else
    //     {
    //         return back;
    //     }
        
    // }


}


ptrPair divide(int *a, int n)
{
    int partitionPosition = getPartitionIndex(a, n);
    // int temp = a[0];
    // a[0] = a[partitionPosition];
    // a[partitionPosition] = a[tent partitionPosition = getPartitionIndex(a, n) + 1;
    // ptrPair ptrs;
    // ptrs.first = &(a[0]);
    // ptrs.second = &(a[partitionPosition]);
    // ptrs.firstLen = partitionPosition;
    // ptrs.secondLen = n - partitionPosition;
    // rsition;
    // ptrs.secondLen = n - partitionPosition;
    // return ptrs;

}

void conquer(int *a, int n)
{
    if (n <= 1)
    {
        return;
    }
    ptrPair ptrs = divide(a, n);
    conquer(ptrs.first, ptrs.firstLen);
    conquer(ptrs.second, ptrs.secondLen);
    // for (int i = 0; i < ptrs.firstLen; i++)
    // {
    //     printf("%d ", ptrs.first[i]);
    // }
    // printf("\n");
    // printf("Pivot %d", ptrs.first[ptrs.firstLen]);
    // for (int i = ptrs.firstLen + 1; i < ptrs.secondLen; i++)
    // {
    //     printf("%d ", ptrs.second[i]);
    // }
    // printf("\n");
    

}

void quickSort(int *a, int n)
{
    conquer(a, n);
}