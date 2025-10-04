#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *Cnode(int value);
void insert_head(Node **head,int x);
void end_insert(Node **head,int x);
void insert_at_position(Node **head, int data, int position);
void print(Node *head);
int main()
{
    Node *head = NULL;
    insert_at_position(&head,2,7);
    print(head);
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
void insert_head(Node **head,int x)
{
    Node *temp = Cnode(x);
    temp->next = *head; //指向头节点
    *head = temp;
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
void insert_at_position(Node **head, int data, int position)
{
    //creat a new node
    Node *new_node = Cnode(data);
    //边界判断
    if( 1 == position)
    {
        insert_head(head,data);
        return;
    }
    else if( position <= 0)
    {
        printf("Invild position! please input a new position\n");
        free(new_node);// 防止内存泄漏
        return;
    }
    Node *temp = *head;
    for( int i=0;(NULL != temp) && (i< position-2);i++)
    {
        temp = temp->next;
    }
    if(NULL == temp) //超出链表
    {
        printf("The position too long!");
        free(new_node);
        return;
    }
    new_node->next = temp->next;//将插入的后一个指针地址转移到插入的下一个地址域中
    temp->next =new_node;
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



