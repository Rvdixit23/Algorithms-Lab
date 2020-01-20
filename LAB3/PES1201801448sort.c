#include<stdio.h>
#include<stdlib.h>

int isSorted(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            return 0;
        }
        
    }
    return 1;
}
void bubblePass(int *a, int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])
        {
            temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
        }
        
    }
    
}

void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        // bubblePass(a, n);
        
        for (int j = 1; j < n; j++)
        {
            if (a[j] < a[j-1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            
        }
    }
    
}

int numBubblePasses(int *a, int n)
{
    int passCount = 0;
    while (!isSorted(a, n))
    {
        bubblePass(a, n);
        passCount++;
    }
    return passCount;
}

int maxIndex(int *a, int n)
{
    int maxInd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[maxInd] <= a[i])
        {
            maxInd = i;
        }
        
    }
    return maxInd;
}

void swapWithMax(int *a, int n)
{
    int largestEleOffset = maxIndex(a, n);
    int temp;
    if (largestEleOffset < n - 1)
    {
        temp = a[n - 1];
        a[n - 1] = a[largestEleOffset];
        a[largestEleOffset] = temp;
    }
    
}

void selectionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        swapWithMax(a, n - i);
    }
}

int numSwaps(int *a, int n)
{
    int swapCount = 0;
    int maxInd;
    for (int i = 0; i < n; i++)
    {
        maxInd = maxIndex(a, n - i);
        if (maxInd < (n - i - 1))
        {
            swapCount++;
            swapWithMax(a, n - i);
        }       
    }
    return swapCount;
    
    // int swapCount = 0;
    // int i = 0;
    // while (!isSorted(a, n))
    // {
    //     int largestEleOffset = maxIndex(a, n - i);
    //     int temp;
    //     if (largestEleOffset < n - 1 && n > 1)
    //     {
    //         temp = a[n - i - 1];
    //         a[n - i - 1] = a[largestEleOffset];
    //         a[largestEleOffset] = temp;
    //         swapCount++;
    //     }
    //     i++;
    // }
    // return swapCount;
    // int maxIndex;
    // int temp;
    // for (int i = n - 1; i > 0; i--)
    // {
    //     maxIndex = i;
    //     for (int j = i - 1; j > 0; j--)
    //     {
    //         if (a[j] > a[maxIndex])
    //         {
    //             maxIndex = j;
    //         }
            
    //     }
    //     if (maxIndex != i)
    //     {
    //         swapCount++;
    //         temp = a[i];
    //         a[i] = a[maxIndex];
    //         a[maxIndex] = temp;
    //     }
        

        
    // }
    // return swapCount;
}

