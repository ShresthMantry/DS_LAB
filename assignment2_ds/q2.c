#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main()
{
    printf("enter n\n");
    int n;
    scanf("%d",&n);

    int *arr = (int*)calloc(1,sizeof(int));
    printf("enter elements of array\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int second_largest=INT_MIN,largest=arr[0];

    for(int i = 0;i<n;i++)
    {
        largest=largest>arr[i]?largest:arr[i];
    }

    for(int i = 0;i<n;i++)
    {
        if(arr[i]==largest)
            continue;

        second_largest= second_largest>arr[i]?second_largest:arr[i];
    }

    printf("largest = %d   second largest = %d ",largest,second_largest);


}
