#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* Cnode(int value);
void insert_head(Node **head,int x);
void reverse_iterative(Node **head);
void forward_print(Node *head);//�ݹ鷽������
void reverse_print(Node *head);//����
void print(Node *head);
int main()
{
    Node *head = NULL;  // ȫ��ͷָ��
    insert_head(&head,3);
    insert_head(&head,2);
    insert_head(&head,5);
    insert_head(&head,6);
    insert_head(&head,7);
    printf("�����ӡ ");
    forward_print(head);
    printf("\n");
    printf("�����ӡ ");
    reverse_print(head);
    return 0;
}
Node* Cnode(int value)
{
    Node *Newnode = (Node*)malloc(sizeof(Node));//�½����
    if(NULL == Newnode){
        printf("�ڴ����ʧ��\n");
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
void reverse_iterative(Node **head)//��������ת����
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
    temp->next = *head; //ָ��ͷ�ڵ�
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