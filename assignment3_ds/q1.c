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

void addLast(Node *pnode, int data)
{
    if (*pnode == NULL)
    {
        addFirst(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next)
        node = node->next;

    node->next = newNode(data, node->next);
}


Node middle(Node head)
{
    Node fast = head;
    Node slow = head;

    while(fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void deleteMiddle(Node *pnode,Node middle)
{
    Node node = *pnode;
    while(node->next!=middle)
    {
        node = node->next;
    }

    Node temp = node->next;
    node->next=node->next->next;
    free(temp);
}


int main()
{
    Node list = NULL;

    int n;
    printf("Enter no of nodes\n");
    scanf("%d",&n);

    printf("Enter the nodes\n");
    for(int i = 1;i<=n;i++)
    {
        int num;
        scanf("%d",&num);
        addLast(&list,num);
    }

    int extra;
    printf("Enter node to insert\n");
    scanf("%d",&extra);
    addFirst(&list,extra);

    
    printList(list);

    
    Node ans = middle(list);
    printf("Deleted Node %d \n",ans->data );
    deleteMiddle(&list,ans);
    printList(list);

}