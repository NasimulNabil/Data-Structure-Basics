#include<stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link *next;
};
typedef struct link node;
node *list=NULL;
void insert_front(node *list,int data)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=list;
    list=temp;
}
void insert_after(node *list,int data)
{
    if (list==NULL)
    {
        printf("previous node cant be NULL");
    }
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=list->next;
    list->next=temp;
}
void insert_end(node *list,int data)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    while(list->next!=NULL)
    {
        list=list->next;
    }
    list->next=temp;
    return;

}
void display()
{
    node *temp;
    temp=list;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}
int main()
{
    node *temp;
    int data;
    int ch;
    while(1)
    {
        printf("enter 1 to insert front\n");
        printf("enter 2 to insert after\n");
        printf("enter 3 to insert end\n");
        printf("enter 4 to delete\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter number:  ");
            scanf("%d",&data);
            temp->data=data;
            temp->next=NULL;
            insert_front(temp);
            display();
        }
        if(ch==2)
        {
            printf("enter number: ");
            scanf("%d",&data);
            temp->data=data;
            temp->next=NULL;
            insert_after(temp);
            display();
        }
        if(ch==3)
        {
             printf("enter number: ");
            scanf("%d",&data);
            insert_end(temp);
            display();
        }
    }
}
