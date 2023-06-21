#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void heapify(int *arr,int n,int i)
{
    int larger = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left<=n && arr[left]>arr[larger])
    {
        larger = left;
    }
    if(right<=n && arr[right]>arr[larger])
    {
        larger = right;
    }

    if(larger!=i)
    {
        int temp = arr[larger];
        arr[larger]=arr[i];
        arr[i]=temp;
        i = larger;
        heapify(arr,n,i);
    }
}

int main()
{
    int size;
    scanf("%d",&size);
    
    int *arr = (int*)calloc(size+2,sizeof(int));
    arr[0]=-1;

    for(int i = 1;i<=size;i++)
    {
        int num;
        scanf("%d",&num);
        arr[i]=num;
    }

    for(int i = size/2;i>0;i--)
    {
        heapify(arr,size,i);
    }

    for(int i = 0;i<=size;i++)
    {
        printf("%d ",arr[i]);
    }


    printf("\n");
    printf("Enter element to insert\n");
    int ele;
    scanf("%d",&ele);


    arr[size+1]=ele;

    for(int i = (size+1)/2;i>0;i--)
    {
        heapify(arr,size+1,i);
    }

    for(int i = 0;i<=size+1;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    printf("Enter index to Delete\n");
    int index;
    scanf("%d",&index);

    int *b = (int*)calloc(size+1,sizeof(int));

    int j = 0;
    for(int i = 0;i<=size+1;i++)
    {
        if(i==index)
            continue;

        b[j++]=arr[i];
    }



    for(int i = size/2;i>0;i--)
    {
        heapify(b,size,i);
    }

    for(int i = 0;i<=size;i++)
    {
        printf("%d ",b[i]);
    }



}