#include<stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link *next;
};
typedef struct link node;
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

      }  head=newnode;
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
     }   temp->next=newnode;
 }
    void remove_front(node *newnode)
    {
        node *temp=head;
        if(head==NULL)
        {
           printf("list is empty\n");
        }
        else if(temp->next==NULL)
        {
            head=NULL;
        }
        else if(temp->next!=NULL)
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
    void sort(node *newnode)
    {
        node *i,*j;
        int temp;
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=head;
                head->next=head;
                head->next=temp;
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
            printf("%d\n\n",temp->data);
        }
    }
int main()
{
        node *p;
        int ch,n;
        while(1)
        {
            printf("enter 1 to insert at front:\n");
            printf("enter 2 to insert at end:\n");
            printf("enter 3 to remove at front\n ");
            printf("enter 4 to remove at end:\n");
            printf("enter 5 to sorting:");
            scanf("%d",&ch);
            if(ch==1)
            {
                printf("enter number:");
                scanf("%d",&n);
                p=(node*)malloc(sizeof(node));
                p->data=n;
                p->next=NULL;
                insert_front(p);
                printf("displaying adding at front:");
                display();
            }
            else if(ch==2)
            {
                printf("enter number:");
                scanf("%d",&n);
                p=malloc(sizeof(node));
                p->data=n;
                p->next=NULL;
                insert_end(p);
                printf("displaying adding at end:");
                display();
            }
            else if(ch==3)
            {
                remove_front(p);
                display();
            }
            else if(ch==4)
            {
                remove_end(p);
                display();
            }
            else if(ch==5)
            {
                sort(p);
                display();
            }


        }
}

