#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct Node_t {
    int data;
    struct Node_t* next;
    struct Node_t* prev;
} Node_t,* Node;


Node newNode(int data,Node next,Node prev)
{
    Node node = (Node)calloc(1,sizeof(Node_t));
    node->data = data;
    node->next = next;
    node->prev = prev;

    return node;
}

void printList(Node node)
{
    while(node)
    {
        printf("%d == ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void addFirst(Node *pnode,int data)
{
    Node temp = newNode(data,*pnode,NULL);
    if(*pnode==NULL)
    {
        *pnode = temp;
        return ;
    }
    (*pnode)->prev = temp;
    *pnode = temp;
}

void addlast(Node *pnode,int data)
{
    if(*pnode==NULL)
    {
        addFirst(pnode,data);
        return;
    }
    
    Node node = *pnode;
    while(node->next)
    {
        node = node->next;
    }

    node->next=newNode(data,NULL,node);;

}

Node mergeSortSortedArrays(Node head1,Node head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }

    Node l1=NULL,l2=NULL;

    if(head1->data<=head2->data)
    {
        l1 = head1;
        l2 = head2;
    }
    else
    {
        l1 = head2;
        l2 = head1;
    }

    Node ans = l1;

    while(l1!=NULL && l2!=NULL)
    {
        Node temp = NULL;
        while(l1!=NULL && l1->data<=l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next=l2;
        l2->prev=temp;
        Node l3 = l1;
        l1 = l2;
        l2 = l3;

    }

    return ans;
}

int main()
{
    Node head1 = NULL;
    int n;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        addlast(&head1,num);

    }

    printList(head1);


    Node head2 = NULL;
    int m;
    printf("Enter the number of nodes\n");
    scanf("%d",&m);
    for(int i = 0;i<m;i++)
    {
        int num;
        scanf("%d",&num);
        addlast(&head2,num);

    }

    printList(head2);

    printList(mergeSortSortedArrays(head1,head2));
}