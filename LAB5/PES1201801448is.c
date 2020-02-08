#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"session5_sort.h"

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}

long int InsertionSort(Record *A, int n)
{
    long int comparisonCount = 0;
    Record temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && ++comparisonCount && A[j].serialnumber > temp.serialnumber)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = temp;
    }
    return comparisonCount;
}

long int BubbleSort(Record *A, int n)
{
    Record temp;
    long int comparisonCount = 1;
    int noSwap;
    for (long int i = 1; i < n; i++)
    {
        noSwap = 1;
        for (long int j = 0; j < i; j++)
        {
            // comparisonCount++;
            if (++comparisonCount && A[j].serialnumber > A[j + 1].serialnumber)
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                noSwap = 0;
            }
            
        }
    }
    return comparisonCount;
}

long int SelectionSort(Record *A, int n)
{
    long int comparisonCount = 0;
    int min;
    Record temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            // comparisonCount++;
            if (++comparisonCount && A[j].serialnumber < A[min].serialnumber)
            {
                min = j;
            }
            
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    return comparisonCount;
}

long int BinaryInsertionSort(Record *A, int n)
{
    long int comparisonCount = 0;
    Record temp;
    int j;
    for (int i = 1; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        long int beg = 0;
        long int end = j;
        long int mid = j/2;
        long int count = 0;
        int found = 1;
        while(mid != beg && found)
        {
                comparisonCount++;
                if (A[mid].serialnumber > temp.serialnumber)
                {
                        end = mid;
                }
                else if(A[mid].serialnumber < temp.serialnumber)
                {
                        beg = mid;
                }
                else
                {
                        found = 0;
                }
        }
        for(int c = j; c >= mid; c--)
        {
                A[j + 1] = A[j];
        }
        A[mid] = temp;
    }
    return comparisonCount;
}

int main()
{
    int n;
    struct timespec start, end;
    scanf("%d", &n);
    Record *A = (Record *)malloc(sizeof(Record)*n);
    Record *B = (Record *)malloc(sizeof(Record)*n);
    Record *C = (Record *)malloc(sizeof(Record)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%li", &A[i].serialnumber);
        scanf("%d", &A[i].score);
    } 
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
        C[i] = A[i];
    }
    
    long int insC, bubC, selC, bisC;
    double insT, bubT, selT, bisT;
    
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    insC = InsertionSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    insT = time_elapsed(start, end);
    
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    bubC = BubbleSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    bubT = time_elapsed(start, end);
    
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    selC = SelectionSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    selT = time_elapsed(start, end);
    
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    bisC = BinaryInsertionSort(A, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    bisT = time_elapsed(start, end);
    
    printf("Insertion Sort: %li %lf\n", insC, insT);
    printf("Bubble Sort: %li %lf\n", bubC, bubT);
    printf("Selection Sort: %li %lf\n", selC, selT);
    printf("Binary Insertion Sort: %li %lf\n", bisC, bisT);
    
    return 0;
}
