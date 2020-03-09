#include"heapSort.h"
#include<stdlib.h>

void maxHeapify(Heap h, int idx)
{
    if (idx >= 0 && h.size > 1)
    {
        int child = (2 * idx) +  1;
        if (child < h.size)
        {
            if ((child + 1) < h.size && h.a[child] < h.a[child + 1])
            {
                child++;
            }
            if (h.a[child] > h.a[idx])
            {
                int temp = h.a[idx];
                h.a[idx] = h.a[child];
                h.a[child] = temp;
                maxHeapify(h, child);
            }
            else
            {
                return;
            } 
        }
    }
}

Heap buildMaxHeap(int *const a, int n)
{
    Heap heap;
    heap.a = a;
    heap.size = n;
    for (int i = (n/2) - 1; i > -1; i--)
    {
        maxHeapify(heap, i);
    }
    
    return heap;
}

void heapSort(int *const a, int n)
{
    Heap heap = buildMaxHeap(a, n);

    for (int i = n - 1; i >` 0; i--)
    {
        int temp = heap.a[i];
        heap.a[i] = heap.a[0];
        heap.a[0] = temp;
        heap.size--;
        maxHeapify(heap, 0);
    }
    
    
}

