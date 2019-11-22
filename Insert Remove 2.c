#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
node *head=NULL;
void insert_front(node *newnode)
{
    node *temp=head;
    if(temp==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }

}
void insert_end(node *newnode)
{
    node *temp=head;
    if(temp==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insert_after(node *newnode,int pos)
{
    int i;
    node *temp=head;
    node *temp1;
    if(pos==1 && temp==NULL)
    {
        head=newnode;
    }
    else if(pos==1 && temp->next==NULL)
    {
        temp->next=newnode;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=newnode;
        newnode->next=temp1;
    }
}
void insert_at(node *newnode,int pos)
{
    int i;
    node *temp=head;
    node *temp1;
    if(pos==1 && temp==NULL)
    {
        head=newnode;
    }
    else if(pos==1 && temp->next==NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
           temp1=temp->next;
           temp->next=newnode;
           newnode->next=temp1;
    }
}
void remove_front(node *newnode)
{
    node *temp=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
    }
    else if (temp->next!=NULL)
    {
        head=temp->next;
    }
}
void remove_end(node *newnode)
{
    node *temp=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}
void sort(node *p)
{
    node *i,*j;
    int temp;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
void display()
{
    node *temp=head;
    if(head==NULL)
    {
        return;
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n\n\n",temp->data);
    }
}
int main()
{
    int n,ch,pos;
    node *p;
    while(1)
    {

        printf("enter 1 to insert front\n ");
        printf("enter 2 to insert end\n ");
        printf("enter 3 to insert after\n ");
        printf("enter 4 to insert at\n ");
        printf("enter 5 to delete front\n ");
        printf("enter 6 to delete end\n ");
        printf("enter 7 to sorting\n ");
        scanf("%d",&ch);
        if(ch==1)
        {
            p=malloc(sizeof(node));
            printf("enter number: ");
            scanf("%d",&n);
            p->data=n;
            p->next=NULL;
            insert_front(p);
            display();
        }
        else if(ch==2)
        {
             p=malloc(sizeof(node));
            printf("enter number: ");
            scanf("%d",&n);
            p->data=n;
            p->next=NULL;
            insert_end(p);
            display();
        }
        else if(ch==3)
        {
            p=malloc(sizeof(node));
            printf("enter number: ");
            scanf("%d",&n);
            printf("enter position: ");
            scanf("%d",&pos);
            p->data=n;
            p->next=NULL;
            insert_after(p,pos);
            display();
        }
        else if(ch==4)
        {
             p=malloc(sizeof(node));
            printf("enter number: ");
            scanf("%d",&n);
            printf("enter position: ");
            scanf("%d",&pos);
            p->data=n;
            p->next=NULL;
            insert_at(p,pos);
            display();
        }
        else if(ch==5)
        {
            remove_front(p);
            display();
        }
        else if(ch==6)
        {
            remove_end(p);
            display();
        }
        else if (ch==7)
        {
            sort(p);
            display();
        }
    }
    return 0;
}
