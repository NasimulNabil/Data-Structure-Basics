#include<stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link *next;
};
typedef struct link node;
int main()
{
    node *head=NULL;
    node *second=NULL;
    node *third=NULL;
    head=(node*)malloc(sizeof(node));
    second=(node*)malloc(sizeof(node));
    third=(node*)malloc(sizeof(node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printf("%d %d %d",head->data,second->data,third->data);
    return 0;

}
