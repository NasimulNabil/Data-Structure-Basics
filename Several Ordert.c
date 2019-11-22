
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *root=NULL;
void insert(node *q,int data)
{
    if(root==NULL)
    {
        node *p;
        p=malloc(sizeof(node));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        root=p;
    }
    else if(data<q->data && q->left!=NULL)
    {
        q=q->left;
        insert(q,data);
    }
    else if(data>q->data && q->right!=NULL)
    {
        q=q->right;
        insert(q,data);
    }
    else if(data<q->data && q->left==NULL)
    {
        node *p;
        p=malloc(sizeof(node));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        q->left=p;
    }
    else if(data>q->data && q->right==NULL)
    {
         node *p;
        p=malloc(sizeof(node));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        q->right=p;
    }
}
void preorder(node *q)
{
    if(q!=NULL)
    {
        printf("%d",q->data);
        preorder(q->left);
        preorder(q->right);
    }
}
void inorder(node *q)
{
    if(q!=NULL)
    {
        inorder(q->left);
        printf("%d",q->data);
        inorder(q->right);
    }
}
void postorder(node *q)
{
    if(q!=NULL)
    {
        postorder(q->left);
        postorder(q->right);
        printf("%d",q->data);
    }
}
int main()
{
    int i,max=7,n;
    for(i=1;i<=max;i++)
    {
        scanf("%d",&n);
        insert(root,n);
    }
    printf("preorder: ");
    preorder(root);
    printf("inorder: ");
    inorder(root);
    printf("postorder: ");
    postorder(root);
    return 0;
}
