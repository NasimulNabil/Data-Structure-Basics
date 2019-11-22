#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x,y;
    struct node *next;
};
typedef struct node nabil;
int main()
{
    nabil *head;
    head=(nabil*)malloc(sizeof(nabil));
    head->x=10;
    head->y=15;
    //head->next=NULL;//
    printf("%d %d\n",head->x,head->y);
    return 0;
}
