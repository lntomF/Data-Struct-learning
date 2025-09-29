#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *Creat_node(int value);
void insert_head(Node **head , int value);
void print_Z(Node *head);
void print_N(Node *head);
int main()
{
    Node *head = NULL; //全局变量
    insert_head(&head,12);
    insert_head(&head,13);
    insert_head(&head,2);
    printf("正向打印");
    print_Z(head);
    printf("逆向打印");
    print_N(head);
    return 0;
}
Node *Creat_node(int value)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void insert_head(Node **head , int value)
{
    Node *F_node = Creat_node(value);
    //concer case 
    if(NULL == *head)
    {
        *head = F_node;
        return;
    }
    // 新建结点的下一个结点要指向头节点
    F_node->next = *head;
    // 原头节点的前一个结点要指向新建的头结点
    (*head)->prev = F_node;
    // 将新建结点放在头节点上
    *head = F_node;
}
void print_Z(Node *head)
{
    Node *temp = head;
    //concer case
    if( NULL == temp)
    {
        printf("The list is empty!");
        return ;
    }
    while( NULL != temp)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void print_N(Node *head)
{
    if(NULL == head)
    {
        return;
    }
    Node *temp = head;
    while(NULL != temp->next)
    {
        temp = temp->next;
    }
    while( NULL != temp)
    {
        printf("%d->",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}