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

Node minVal(Node root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}



void inorder(Node root,int k1,int k2)
{
    if(root==NULL)
    {
        return ;
    }

    inorder(root->left,k1,k2);
    if(root->data>=k1 && root->data<=k2)
    printf("%d ",root->data);
    inorder(root->right,k1,k2);

}


int main()
{

    int n;
    scanf("%d",&n);

    Node root = NULL;

    for(int i = 0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        root = insertIntoBst(root,num);
    }

    int k1,k2;
    scanf("%d",&k1);
    scanf("%d",&k2);

    inorder(root,k1,k2);
    printf("\n");





}