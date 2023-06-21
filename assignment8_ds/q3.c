#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Heap_t
{
    int *arr;
    int size;
    int index;
} Heap_t, *Heap;

Heap newHeap(int size)
{
    Heap heap = (Heap)calloc(1, sizeof(Heap_t));
    heap->arr = (int *)calloc(size + 1, sizeof(int));
    heap->size = size;
    heap->index = 0;
    heap->arr[heap->index] = -1;
    return heap;
}

void printHeap(Heap heap)
{
    for (int i = 1; i <= heap->index; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void insert(Heap heap, int data)
{
    int index = heap->index;
    int *arr = heap->arr;
    index++;
    heap->index++;
    if(index>heap->size)
    {
        return;
    }
    arr[index] = data;

    while (index > 1)
    {
        int parent = index / 2;
        if (arr[parent] > arr[index])
        {
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            index = parent;
        }
        else
        {
            return;
        }
    }
}

int delete(Heap heap)
{
    if(heap->index==0)
    {
        return -1;
    }

    int *arr = heap->arr;
    int ans = arr[1];
    arr[1]=arr[heap->index];
    heap->index--;

    int i = 1;

    while(i<heap->index)
    {
        int left = 2*i;
        int right = 2*i+1;
        int larger;
        if(left>heap->index)
            break;
        else if(right>heap->index)
            larger = left;
        else
        {
            larger = arr[left]<=arr[right]?left:right;
        }

        if(arr[i]>arr[larger])
        {
            int temp = arr[i];
            arr[i]=arr[larger];
            arr[larger]=temp;
            i = larger;
        }
        else
            break;

    }

    return ans;
}

int main()
{
    int n;
    scanf("%d ",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        arr[i]=num;
    }


    int k;
    scanf("%d",&k);
    Heap heap = newHeap(k);

    for(int i = 0;i<k;i++)
    {
        insert(heap,arr[i]);
    }
    for(int i = k;i<n;i++)
    {
        if(arr[i]>heap->arr[1])
        {
            // printf("%d ",arr[i]);
            delete(heap);
            insert(heap,arr[i]);
        }
    }

    printf("%d ",heap->arr[1]);

    



    

}