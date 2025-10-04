#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* Cnode(int value);
void insert_head(Node **head,int x);
void delete_node(Node **head, int position);
int Cul_node(Node **head);
void print(Node *head);
int main()
{
    Node *head = NULL;  // ȫ��ͷָ��
    int x;
    insert_head(&head,2);
    insert_head(&head,4);
    insert_head(&head,6);
    insert_head(&head,5);
    insert_head(&head,7);
    insert_head(&head,9);
    printf("��ʼ����:");
    print(head);
    x=Cul_node(&head);
    printf("The list length is :%d\n",x);
    while (head != NULL) {
        printf("please input you want delete node position!\n");
        int n;
        scanf("%d", &n);
        delete_node(&head, n);
        printf("The list is ");
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
int Cul_node(Node **head)
{
    int count;
    Node *temp = *head;
    while( NULL != temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void delete_node(Node **head, int position)
{
    // 1.go to the specific position
    //concer case 1 ͷ�����
    if( NULL == *head)
    {
        printf("The list is empty!\n");
        return;
    }
    //concer case 1.1 λ���ڵ�һλ��node
    if(1 == position)
    {
        Node *temp_1 = *head;
        // *head = temp_1->next;//��ѧ������д
        *head = (*head)->next;//��������
        free(temp_1);
        return; //��Ҫ����������ɾ����һ�������������쳣����δ�������أ������ظ�ɾ��
    }
    //concer case 2 ͷ�ڵ�������λ��
    Node *temp = *head;
    for(int i=0;(NULL != temp)&&(i < (position-2));i++)
    {
        temp = temp->next;
    }
    //concer case 2.1 ��������������λ��ָ��NULL��λ��
    /*NULL == temp�� NULL == temp->next������??
    NULL == temp
        ??temp�����ǿ�ָ��??�����������Ѿ�������ĩβ�����ߴ���� temp��ʼ���� NULL��
    ��鵱ǰ����Ƿ���Ч
    NULL == temp->next
    ?   ?temp����һ������� NULL??������ temp�����һ����㣬temp->next���� NULL��
    ����Ƿ���԰�ȫ���� temp->next*/
    if( (NULL == temp) || (NULL == temp->next))
    {
        printf("The list out of bound!\n");
        return;
    }
    // 2.jump to target position
    Node *next = temp->next->next;
    // 3.free the node  
    free(temp->next);
    temp->next = next;
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