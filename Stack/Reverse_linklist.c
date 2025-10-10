#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct {
    Node *data[MAX_SIZE];
    int top;
}Stack;

Node *CNode(int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->data = value;
    return newnode;
}
void Stack_init(Stack *s)
{
    s->top = -1;
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
int isFully(Stack *s)//¼ì²éÕ»ÊÇ·ñÂú
{
    return s->top == MAX_SIZE-1;
}
void push(Stack *s, Node *n)//Ñ¹Õ»
{
    if(!isFully(s))
    {
        s->top++;
        s->data[s->top] = n;
    }
}
Node *pop(Stack *s)//µ¯Õ»
{
    if(!isEmpty(s))
    {
        Node *temp = s->data[s->top];
        s->top--;
        return temp;
    }
    return NULL;
}
void printlink(Node *head)
{
    Node *temp = head;
    while(NULL != temp)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverse(Node **head)
{
    // concer case
    if(*head == NULL || (*head)->next == NULL)
    {
        return ;
    }
    //The Stack init
    Stack s;
    Stack_init(&s);
    Node *temp = *head;
    //Ñ¹Õ»
    while(NULL != temp)
    {
        push(&s,temp);
        temp = temp->next;
    }
    //pop
    *head = pop(&s);//new head
    temp = *head;
    while(!isEmpty(&s))
    {
        temp->next = pop(&s);
        temp = temp->next;
    }
    temp->next = NULL;
}
int main()
{
    Node *head = CNode(1);
    head->next = CNode(2);
    head->next->next = CNode(3);
    printf("The reverse before is:");
    printlink(head);
    reverse(&head);
    printf("The reverse after is:");
    printlink(head);
    while(head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}