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

void removeDuplicates(Node *pnode)
{
    Node node = *pnode;
    while (node)
    {
        Node temp = node->next;
        Node prev = node;
        while (temp)
        {
            if (temp->data == node->data)
            {
                Node temp2 = temp;
                prev->next = temp->next;
                temp = temp->next;
                free(temp2);
                continue;
            }

            prev = prev->next;
            temp = temp->next;
        }
        node = node->next;
    }
}

Node intersection(Node l1,Node l2)
{
    Node head = NULL;
    Node h2  = l2;
    Node h1 = l1;

    while(l1)
    {
        int flag = 0;
        l2 = h2;
        while(l2)
        {
            if(l1->data==l2->data)
            {
                flag = 1;
                break;
            }
            l2 = l2->next;
        }
        if(flag==1)
        {
            addLast(&head,l1->data);
        }
        l1 = l1->next;

    }

    return head;
}



int main()
{
    Node l1 = NULL;

    int n;
    printf("Enter no of nodes\n");
    scanf("%d", &n);

    printf("Enter the nodes\n");
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        addLast(&l1, num);
    }

    Node l2 = NULL;

    int m;
    printf("Enter no of nodes\n");
    scanf("%d", &m);

    printf("Enter the nodes\n");
    for (int i = 1; i <= m; i++)
    {
        int num;
        scanf("%d", &num);
        addLast(&l2, num);
    }

    Node ans = intersection(l1,l2);
    removeDuplicates(&ans);
    printList(ans);


    

}