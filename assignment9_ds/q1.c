#include<stdio.h>
#include<stdlib.h>

int partition1(int *arr,int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }

        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }

        if(i<j)
        {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    }

    int temp = arr[j];
    arr[j]=arr[low];
    arr[low]=temp;

    return j;
}

void quickSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int pIndex = partition1(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }

}


int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        arr[i]=num;
    }

    quickSort(arr,0,n-1);


    int count = 1;
    for(int i = 1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            count++;
            if(i==n-1)
            {
                printf("%d->%d\n",arr[i],count);
            }
        }
        else
        {
            if(count!=1)
            {
                printf("%d->%d\n",arr[i-1],count);
            }
            count = 1;
        }
    }


}