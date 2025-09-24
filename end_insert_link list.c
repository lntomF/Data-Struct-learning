#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;   
}Node;
Node *Cnode(int value);
void end_insert(Node **head,int x);
void print(Node *head);
int main()
{
    //test 
    Node *head = NULL;
    int x,i,n;
    printf("Input the number of numbers you want:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Input your want insert %d numbers to end:",i+1);
        scanf("%d",&x);
        end_insert(&head,x);
        print(head);
    }
}
Node *Cnode(int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if(NULL == temp)
    {
        printf("memory is failed!");
        exit(1);
    }
    temp->next = NULL;
    temp->data = value;
    return temp;
}
void end_insert(Node **head,int x)
{
    Node *new_node = Cnode(x);
    //boundary handling 
    if(NULL == *head)
    {
        // new_node = *head; erorr ways：因为链表头是空的话应该是新节点给头部节点赋值
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while(NULL != temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}
void print(Node *head)
{
    Node *temp =head;
    while( temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}