#include <stdio.h>
#include <stdlib.h>

// 定义节点结构
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
    Node *head = NULL;  // 全局头指针
    int x;
    insert_head(&head,2);
    insert_head(&head,4);
    insert_head(&head,6);
    insert_head(&head,5);
    insert_head(&head,7);
    insert_head(&head,9);
    printf("初始链表:");
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
    Node *Newnode = (Node*)malloc(sizeof(Node));//新建结点
    if(NULL == Newnode){
        printf("内存分配失败\n");
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
    //concer case 1 头部情况
    if( NULL == *head)
    {
        printf("The list is empty!\n");
        return;
    }
    //concer case 1.1 位置在第一位的node
    if(1 == position)
    {
        Node *temp_1 = *head;
        // *head = temp_1->next;//初学者这样写
        *head = (*head)->next;//糕手这样
        free(temp_1);
        return; //重要！！！！！删除第一个结点后链表长度异常减少未立即返回，导致重复删除
    }
    //concer case 2 头节点后的任意位置
    Node *temp = *head;
    for(int i=0;(NULL != temp)&&(i < (position-2));i++)
    {
        temp = temp->next;
    }
    //concer case 2.1 任意结点后面的最后的位置指向NULL的位置
    /*NULL == temp和 NULL == temp->next的区别??
    NULL == temp
        ??temp本身是空指针??（比如链表已经遍历到末尾，或者传入的 temp初始就是 NULL）
    检查当前结点是否有效
    NULL == temp->next
    ?   ?temp的下一个结点是 NULL??（比如 temp是最后一个结点，temp->next就是 NULL）
    检查是否可以安全访问 temp->next*/
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