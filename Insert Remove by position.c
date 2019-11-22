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
        temp=newnode;
    }
    else
    {
        newnode->next=temp;

    }
    head=newnode;
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
        printf("list is empty\n");
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


void sort()
{
    node *i,*j;
    int temp;
    for(i=head; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if (i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

void insertNodeAtMiddle(int data, int position)
{
    int i;
    node *newNode, *temp;

    newNode = malloc(sizeof(node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        temp = head;

        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {

            newNode->next = temp->next;

            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}

void deleteMiddleNode(int position)
{
    int i;
    node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            //toDelete->next = NULL;


            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }
    }
}

void display()
{
    node *temp=head;
    int count =0;
    if(head==NULL)
    {
        return;
    }
    else
    {
        while(temp->next!=NULL)
        {
            count ++;
            printf("%d ",temp->data);
            temp=temp->next;
        }
        count++;
        printf("%d\n",temp->data);
        printf ("count=%d\n\n\n",count);
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
        printf("enter 5 to sorting:\n");
        printf ("enter 6 to insert middle:\n");
        printf ("enter 7 to remove at middle:\n");
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
            printf ("display shot:");
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
        else if (ch==6)
        {
            int data,position;
            printf("Enter data to insert at middle of the list: ");
            scanf("%d", &data);
            printf("Enter the position to insert new node: " );
            scanf("%d", &position);
            insertNodeAtMiddle(data, position);
            printf ("after inserting middle:\n");
            display ();
        }
        if (ch==7)
        {
            int position;
            printf("\nEnter the node position you want to delete: ");
            scanf("%d", &position);

            deleteMiddleNode(position);
            printf ("after removing data:\n");
            display();

        }

    }
}
