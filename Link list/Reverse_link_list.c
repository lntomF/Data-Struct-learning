#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* Cnode(int value);
void insert_head(Node **head,int x);
void reverse_iterative(Node **head);
void forward_print(Node *head);//递归方法正序
void reverse_print(Node *head);//逆序
void print(Node *head);
int main()
{
    Node *head = NULL;  // 全局头指针
    insert_head(&head,3);
    insert_head(&head,2);
    insert_head(&head,5);
    insert_head(&head,6);
    insert_head(&head,7);
    printf("正序打印 ");
    forward_print(head);
    printf("\n");
    printf("逆序打印 ");
    reverse_print(head);
    return 0;
}
Node* Cnode(int value)
{
    Node *Newnode = (Node*)malloc(sizeof(Node));//新建结点
    if(NULL == Newnode){
        printf("内存分配失败\n");
        exit(1);
    }
    Newnode->data = value;
    Newnode->next = NULL;
    return Newnode;
}
void forward_print(Node *head)
{
    if(NULL == head)
    {
        return;
    }
    printf("%d ",head->data);
    forward_print(head->next);
}
void reverse_print(Node *head)
{
    if(NULL == head)
    {
        return;
    }
    reverse_print(head->next);
    printf("%d ",head->data);
}
void reverse_iterative(Node **head)//迭代法反转链表
{
    Node *prev = NULL;
    Node *current = *head;
    while( NULL != current)
    {
        Node *next1 = current->next;
        current->next = prev;
        prev = current;
        current = next1;
    }
    *head = prev;
}

void insert_head(Node **head,int x)
{
    Node *temp = Cnode(x);
    temp->next = *head; //指向头节点
    *head = temp;
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