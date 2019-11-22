#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node ncr;
int main()
{
    ncr* head=NULL;
    ncr* second=NULL;
    ncr* third=NULL;
    head=(ncr*)malloc(sizeof(ncr));
    second=(ncr*)malloc(sizeof(ncr));
    third=(ncr*)malloc(sizeof(ncr));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    printf("%d %d %d %d",head->data,second->data,third->data,second->next);
    return 0;
}

