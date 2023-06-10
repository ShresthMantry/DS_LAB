#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Node_t {
    int data;
    struct Node_t* next;
} Node_t,* Node;

Node newNode(int data,Node next)
{
    Node node = (Node) calloc (1,sizeof(Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void printList(Node node)
{
    while(node)
    {
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void addFirst(Node *pnode , int data)
{
    *pnode = newNode(data,*pnode);
}

void push(Node *pnode,int data)
{
    if(*pnode==NULL)
    {
        addFirst(pnode,data);
        return;
    }
    Node node = *pnode;
    while(node->next)
        node = node->next;

    node->next = newNode(data,node->next);

}

int pop(Node *pnode)
{
    if(*pnode == NULL)
    return INT_MAX;

    Node node = *pnode;
    *pnode = node->next;
    int data = node->data;
    free(node);
    return data;
}

int getLen(Node head)
{
    Node node = head;
    int count = 0;
    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}




int main()
{
    Node list1 = NULL;
    int n;
    printf("Enter size \n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        push(&list1,num);
    }
    printList(list1);

    Node list2 = NULL;
    int m;
    printf("Enter Size \n");
    scanf("%d",&m);
    printf("Enter elements \n");
    for(int i = 0;i<m;i++)
    {
        int num;
        scanf("%d",&num);
        push(&list2,num);
    }
    printList(list2);


    if(m!=n)
    {
        printf("Not equal");
        return -1;
    }
    else
    {
        int isequal = 1;
        Node head1 = list1;
        Node head2 = list2;
        while(head1 && head2)
        {
            if(head1->data!=head2->data)
            {
                isequal = 0;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        if(isequal==0)
        {
            printf("Unequal");
        }
        else
        {
            printf("Equal");
        }
    }
    
}