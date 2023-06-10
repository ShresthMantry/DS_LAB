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

Node mergeSortSortedLinkedList(Node l1, Node l2)
{
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    if (l1->data > l2->data)
    {
        Node l3 = l1;
        l1 = l2;
        l2 = l3;
    }

    Node res = l1;

    while (l1 != NULL && l2 != NULL)
    {
        Node temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }

        temp->next = l2;
        Node l3 = l2;
        l2 = l1;
        l1 = l3;
    }

    return res;
}

Node mergeSort(Node head)
{
    if(head->next==NULL)
    {
        return head;
    }
    Node mid = middle(head);
    Node l2 = mid->next;
    mid->next = NULL;
    Node l1 = head;
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);

    Node res = mergeSortSortedLinkedList(l1,l2);
    return res;
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

    printList(list);

    Node ans = middle(list);
    printf("Sorted Linked List\n");
    
    printList(mergeSort(list));

}