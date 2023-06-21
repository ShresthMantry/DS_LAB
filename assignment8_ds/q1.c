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

typedef struct queue
{
    int front, rear;
    unsigned capacity;
    Node *arr;
} Queue_t, *Queue;

Queue newQueue(unsigned capacity)
{

    Queue q = (Queue)calloc(1, sizeof(Queue_t));
    q->front = -1;
    q->capacity = capacity;
    q->rear = -1;
    q->arr = (Node *)calloc(capacity, sizeof(Node));
    // printf("done");

    return q;
}

void push(Queue q, Node data)
{
    if (q->rear == (q->capacity - 1))
    {
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[0] = data;
    }

    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
    // printf("done");
}

Node pop(Queue q)
{
    // printf("%d\n",st->top);
    if (q->front == -1)
    {
        return NULL;
    }

    else if (q->front == q->rear)
    {
        Node ele = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return ele;
    }

    else
    {
        Node ele = q->arr[q->front];
        for (int i = 1; i <= q->rear; i++)
        {
            q->arr[i - 1] = q->arr[i];
        }
        q->rear--;
        return ele;
    }
}

Node insertIntoBst(Node root,int data)
{

    if(root==NULL)
    {
        root = newNode(data);
        return root;
    }
    if(data>root->data)
    {
        root->right = insertIntoBst(root->right,data);
    }
    else if(data<=root->data)
    {
        root->left = insertIntoBst(root->left,data);
    }

    return root;

}



void levelOrderTraversal(Node root)
{
    Queue q = newQueue(20);
    push(q, root);
    push(q, NULL);
    while (q->front > -1)
    {
        Node temp = pop(q);

        if (temp == NULL)
        {
            printf("\n");
            if (q->front > -1)
            {
                push(q, NULL);
            }
        }
        else
        {
            printf("%d ", temp->data);

            if (temp->left)
            {
                push(q, temp->left);
            }
            if (temp->right)
            {
                push(q, temp->right);
            }
        }
    }

    free(q);
}

void bubbleSort(int* arr,int n)
{
    for(int i = n-1;i>=1;i--)
    {
        for(int j = 0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
}

void heapify(int *arr,int n,int i)
{
    int larger = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left<=n && arr[left]<arr[larger])
    {
        larger = left;
    }
    if(right<=n && arr[right]<arr[larger])
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

    int n;
    scanf("%d",&n);

    Node root = NULL;

    int *arr = (int*)calloc(n,sizeof(int));

    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        root = insertIntoBst(root,num);
        arr[i]=num;
    }

    printf("\n");
    printf("Level Order Traversal of BST\n");
    levelOrderTraversal(root);
    printf("\n");


    bubbleSort(arr,n);


    int *a = (int*)calloc(n+1,sizeof(int));
    a[0]=-1;
    for(int i = 1;i<=n;i++)
    {
        a[i]=arr[i-1];
    }

    for(int i = n/2;i>0;i--)
    {
        heapify(a,n,i);
    }

    printf("Array After Heapify\n");
    for(int i = 0;i<=n;i++)
    {
        printf("%d ",a[i]);
    }


}