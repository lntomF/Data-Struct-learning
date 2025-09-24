#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node* Cnode(int value);
void insert_head(Node **head,int x);
void print(Node *head);
int main()
{
    Node *head = NULL;  // 全局头指针
    int i,x,n;
    printf("请输入想要插入的数字个数");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个数字",i+1);
        scanf("%d",&x);
        insert_head(&head,x);
        print(head);
    }

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