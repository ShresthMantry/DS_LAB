#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        arr[i] = num;
    }

    printf("Enter 1 for BubbleSort , 2 for SelectionSort , 3 for InsertionSort\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        bubbleSort(arr, n);

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    }
    case 2:
    {
        selectionSort(arr, n);

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        break;    
    }
    case 3:
    {
        insertionSort(arr, n);

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        break;
    }

    }
}