#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node_t
{
    int data;
    struct Node_t *left;
    struct Node_t *right;
} Node_t, *Node;

Node newNode(int data)
{
    Node node = (Node)calloc(1, sizeof(Node_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node insertIntoBst(Node root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertIntoBst(root->right, data);
    }
    else if (data <= root->data)
    {
        root->left = insertIntoBst(root->left, data);
    }

    return root;
}

Node minVal(Node root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


void inorder(Node root,int *pi,int *arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left,pi,arr);
    printf("%d ", root->data);
    arr[*pi]=root->data;
    (*pi)++;
    inorder(root->right,pi,arr);
}
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

    Node root1 = NULL;
    Node root2 = NULL;

    int *arr1 = (int *)calloc(n, sizeof(int));
    int *arr2 = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        root1 = insertIntoBst(root1, num);
    }

    int i1 = 0;
    inorder(root1,&i1,arr1);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        root2 = insertIntoBst(root2, num);

    }

    int i2 = 0;
    inorder(root2,&i2,arr2);

  

    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            printf("False");
            return 0;
        }
    }
    printf("True");
    return 0;
}