#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* Cnode(int value);
void insert_head(Node **head,int x);
void print(Node *head);
int main()
{
    Node *head = NULL;  // ȫ��ͷָ��
    int i,x,n;
    printf("��������Ҫ��������ָ���");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("�������%d������",i+1);
        scanf("%d",&x);
        insert_head(&head,x);
        print(head);
    }

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