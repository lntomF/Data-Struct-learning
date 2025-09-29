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
    Node *head = NULL; //ȫ�ֱ���
    insert_head(&head,12);
    insert_head(&head,13);
    insert_head(&head,2);
    printf("�����ӡ");
    print_Z(head);
    printf("�����ӡ");
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
    // �½�������һ�����Ҫָ��ͷ�ڵ�
    F_node->next = *head;
    // ԭͷ�ڵ��ǰһ�����Ҫָ���½���ͷ���
    (*head)->prev = F_node;
    // ���½�������ͷ�ڵ���
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