#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Stack
{
    Node *head;
}Stack;

void Stack_init(Stack *stack)
{
    stack->head = NULL;
}
Node* creatnewnode(int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = value;
    return temp;
}
void push(Stack *stack,int x)//入栈
{
    Node * temp = creatnewnode(x);
    temp->next  = stack->head;
    stack->head = temp;
}
void pop(Stack *stack)//弹栈
{
    Node *temp = stack->head;//记录
    stack->head = stack->head->next;// 访问下一个指针 
    free(temp);
}
int iSEmpty(Stack *stack)
{
    return stack->head == NULL;
}
int peek(Stack *stack)
{
    return stack->head->data;
}
int main()
{
    Stack stack;
    Stack_init(&stack);
    push(&stack,11);
    push(&stack,22);
    push(&stack,55);
    push(&stack,44);
    printf("Top element is [%d]\n",peek(&stack));
    pop(&stack);
    pop(&stack);
    printf("Top element is [%d]\n",peek(&stack));
    return 0;
}