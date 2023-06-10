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




int main()
{
    Node list = NULL;
    int n;
    printf("Enter Size \n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        push(&list,num);
    }

    printList(list);
    pop(&list);
    pop(&list);
    pop(&list);
    printf("After Popping \n");
    printList(list);
    
}