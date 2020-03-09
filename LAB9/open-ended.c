#include<stdio.h>
#include<stdlib.h>
// Design an algorithm to merge k sorted lists and 
// analyse the time efficiency


int * merger(int a[5][5], int n, int k)
{
    /*
    Function to merge k sorted arrays of length n
    */
    int *arrayIndices = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        arrayIndices[i] = 0;
    }
    int answerIndex = 0;
    int *finalArray = (int *)malloc(sizeof(int) * n * k);
    
    int min;
    int arrayIndexIndex;
    while (answerIndex < n * k)
    {
        min = 69;
        arrayIndexIndex = -1;
        for (int i = 0; i < k; i++)
        {
            if (arrayIndices[i] < n && a[i][arrayIndices[i]] < min)
            {
                min = a[i][arrayIndices[i]];
                arrayIndexIndex = i;

            }
            
        }
        if (arrayIndexIndex == -1)
        {
            return finalArray;
        }
        
        finalArray[answerIndex++] = min;
        arrayIndices[arrayIndexIndex]++;
        
    }
    return finalArray;

    
    
}

int main()
{
    int array[5][5] = {0, 5, 10, 15, 25, 1, 6, 11, 16, 21, 2, 7, 12, 17, 22, 3, 8, 13, 18, 23, 4, 9, 14, 19, 24};
    int *new = merger(array, 5, 5);
    for (int i = 0; i < 25; i++)
    {
        printf("%d ", new[i]);       
    }
    printf("\n");
    
}