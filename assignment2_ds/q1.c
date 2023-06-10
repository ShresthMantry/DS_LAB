#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("enter n\n");
    int n;
    scanf("%d",&n);

    printf("enter elements of array\n");
    int *arr = (int*)calloc(n,sizeof(int));
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


    int start = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            int temp = arr[i];
            for(int j = i-1;j>=start;j--)
            {
                arr[j+1]=arr[j];
            }
            arr[start]=temp;
            start++;
        }
    }

    printf("new array\n");
    for(int i = 0;i<n;i++)
    {

        printf("%d ",arr[i]);
    }
}