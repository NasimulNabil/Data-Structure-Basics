#include<stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link *next;
};
typedef struct link node;
node *head=NULL;
void insert_front(node *newnode) //this code have node add and delete in front and end
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
void delete_front(node *newnode)
{
    node *temp=head;
    if(head==NULL)
    {
        printf("blank");
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
void delete_end(node *newnode)
{
    node *temp=head;
    if(head==NULL)
    {
        printf("blank");
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
          temp->data=NULL;
    }
}
void sort_list(node *p)
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
void display ()
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
    int n,ch;
    printf("welcome\n");
    while(1)
    {
        printf("Enter 1 to add front:\n");
        printf("Enter 2 to add end:\n");
        printf("Enter 3 to delete front:\n");
        printf("Enter 4 to delete end:\n");
        printf("Enter 5 to sorting:\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter a number:  ");
            scanf("%d",&n);
            p=(node*)malloc(sizeof(node));
            p->data=n;
            p->next=NULL;
            insert_front(p);
            printf("Displaying adding at front:     ");
            display();
        }
        else if(ch==2)
        {
            printf("Enter a number: ");
            scanf("%d",&n);
            p=(node*)malloc(sizeof(node));
            p->data=n;
            p->next=NULL;
            insert_end(p);
            printf("displaying adding end:  ");
            display();
        }
       else if(ch==3)
       {
           delete_front(p);
           display();
       }
       else if(ch==4)
       {
           delete_end(p);
           display();
       }
       else if(ch==5)
       {
           sort_list(p);
           display();
       }

    }
    return 0;
}

