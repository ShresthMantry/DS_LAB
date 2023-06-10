#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node_t
{
    int data;
    struct Node_t *next;
} Node_t, *Node;

Node newNode(int data, Node next)
{
    Node node = (Node)calloc(1, sizeof(Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void printList(Node node)
{
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void addFirst(Node *pnode, int data)
{
    *pnode = newNode(data, *pnode);
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

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node reverse(Node head)
{
    Node curr = head;
    Node prev = NULL;
    Node next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void palindrome(Node head)
{
    Node mid = middle(head);
    Node revHead = reverse(mid->next);
    mid->next = revHead;

    // printList(head);

    Node node = head;
    Node curr = mid->next;

    while (curr != NULL)
    {
        if (curr->data != node->data)
        {
            printf("Not Palindrome");
            return;
        }
        curr = curr->next;
        node = node->next;
    }

    printf("Palindrome");
}

int main()
{
    Node list = NULL;

    int n;
    printf("Enter no of nodes\n");
    scanf("%d", &n);

    printf("Enter the nodes\n");
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        addLast(&list, num);
    }


    printList(list);
    palindrome(list);
}