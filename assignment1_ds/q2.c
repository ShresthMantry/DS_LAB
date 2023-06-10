#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    printf("Enter the number of elements\n");
    scanf("%d",&size);

    int *arr = (int*)calloc(size,sizeof(int));

    printf("Enter the elements of array\n");
    for(int i = 0;i<size;i++)
        scanf("%d",&arr[i]);


    int largest = arr[0];
    int smallest = arr[0];

    for(int i = 0;i<size;i++)
    {
        largest = largest>arr[i]?largest:arr[i];
        smallest = smallest<arr[i]?smallest:arr[i];
    }

    printf("largest element = %d smallest element = %d \n",largest,smallest);
}
