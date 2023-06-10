#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
    int front, rear;
    unsigned capacity;
    int *arr;
} Queue_t, *Queue;

Queue newQueue(unsigned capacity)
{
    
    Queue q = (Queue)calloc(1, sizeof(Queue_t));
    q->front = -1;
    q->capacity = capacity;
    q->rear = -1;
    q->arr = (int *)calloc(capacity, sizeof(int));
    // printf("done");

    return q;
}

void push(Queue q, int data)
{
    if ((q->rear == (q->capacity - 1) && q->front==0) || ((q->front-1)==q->rear))
    {
        return ;
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
        q->rear = q->rear%q->capacity;
        q->arr[q->rear] = data;
    }
    // printf("done");
}

int pop(Queue q)
{
    // printf("%d\n",st->top);
    if (q->front == -1)
    {
        return -1;
    }

    else if (q->front == q->rear)
    {
        int ele = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return ele;
    }

    else
    {
        int ele = q->arr[q->front];
        q->arr[q->front]=-111;
        q->front++;
        q->front = q->front%q->capacity;
        return ele;
    }
}

int front(Queue q)
{
    return q->front>=0?q->arr[q->front]:-1;
}

void printQueue(Queue q)
{
    for (int i = 0; i <= q->capacity-1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void pushIndex(Queue* nq,int index,int data)
{
    Queue q = *nq;
    if ((q->rear == (q->capacity - 1) && q->front==0) || ((q->front-1)==q->rear))
    {
        return ;
    }

    printf("index %d capacity %d \n",index,q->capacity);
    if(index==q->capacity-1)
    {
        push(q,data);
        return ;
    }

    Queue k = newQueue(q->capacity);
    int count = 0;
    while(q->front!=-1)
    {
        if(count == index)
        {
            push(k,data);
            count++;
            continue;
        }

        int ele = pop(q);
        push(k,ele);
        // printf("%d ",ele);
        count++;

    }

    *nq = k;
    

}

void popIndex(Queue* nq,int index)
{
    Queue q = *nq;
    if (q->front == -1)
    {
        return ;
    }

    Queue k = newQueue(q->capacity);

    int count = 0;
    while(q->front!=-1)
    {
        if(count == index)
        {
            count++;
            pop(q);
            continue;
        }

        push(k,pop(q));
        count++;
        
    }

    *nq = k;

}

int main()
{
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    Queue q = newQueue(n+1);

    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        push(q,num);
    }

    printQueue(q);

    printf("Enter index to insert\n");
    int m;
    scanf("%d",&m);

    int data;
    printf("Enter data\n");
    scanf("%d",&data);

    pushIndex(&q,m,data);
    printQueue(q);



    printf("Enter index to delete\n");
    scanf("%d",&m);

    popIndex(&q,m);
    printQueue(q);

    

}