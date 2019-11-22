#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1;
    float data2;
    struct node *next;
}*head;

void createlist (int n);
void tlist();

int main ()
{
    int n;
    printf ("Enter how many node:\n");
    scanf ("%d",&n);
    createlist(n);

    printf ("\n\n.....LIST IS.....\n");
    display_list();
    return 0;

}
void createlist (int n)
{
    struct node *temp,*newnode;
    int data1,i;
    float data2;


    head=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
    {
        printf ("list is empty\n");

    }


    printf ("Enter the data of node INTEGER 1:");
    scanf ("%d",&data1);
    printf ("Enter the data of node FLOAT 1:");
    scanf ("%f",&data2);


    head->data1=data1;
    head->data2=data2;
    head->next=NULL;

    temp=head;
    for (i=2; i<=n; i++)
    {
        newnode =(struct node*)malloc (sizeof(struct node));

        printf ("enter the data of INTGER %d:",i);
        scanf ("%d",&data1);
        printf ("enter the data of FLOAT %d:",i);
        scanf ("%f",&data2);



        newnode->data1=data1;
        newnode->data2=data2;
        newnode->next=NULL;

        temp->next=newnode ;
        temp=temp->next;


    }

}

void display_list ()
{
    struct node *temp;

    if (head==NULL)
    {
        printf ("list is empty");
        return;

    }
    temp=head;
    while (temp!=NULL)
    {
        printf (" %d\t%.2f\n",temp->data1,temp->data2);
        temp=temp->next;
    }
}
