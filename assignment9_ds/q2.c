#include <stdio.h>
#include <stdlib.h>

int partition1(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition1(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
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

    quickSort(arr, 0, n - 1);

    int k = 0;

    int *all = (int *)calloc(9, sizeof(int));
    for (int i = arr[0]; i <= arr[n-1]; i++)
    {
        all[k++] = i;
    }

    int s1 = 0;
    int s2 = 0;

    for (int i = 0; i < n; i++)
        for (int j = s2; j <= 8; j++)
        {
            if (all[j] < arr[i])
            {
                printf("%d ", all[j]);
            }
            else if (all[j] == arr[i])
            {
                s2 = j + 1;
                break;
            }
        }
}
