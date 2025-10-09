#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

typedef struct Stack
{
    char str[MAX_SIZE];
    int top;
}Stack;

void Stack_init(Stack *S)
{
    S->top = -1;
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s,char c)
{
    if(!isFull(s))
    {
        s->top++;
        s->str[s->top] = c;
    }
}
char pop(Stack *s)
{
    if(!isEmpty(s))
    {
        char c = s->str[s->top];
        s->top--;
        return c;
    }
    return '\0';
}
void reverse(char *str)
{
    Stack s;
    Stack_init(&s);
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        push(&s,str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i] = pop(&s);
    }
}
void reverse_double_pionter(char *str)
{
    if( NULL == str) return;
    int len = strlen(str);
    if( len < 1) return;
    char *left = str;
    char *right = str + len - 1;
    while(left<right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

}
int main()
{
    char c[MAX_SIZE];
    printf("please input something:\n");
    scanf("%s",c);
    reverse(c);
    printf("The reverse string :\n%s\n",c);
    reverse_double_pionter(c);
    printf("The reverse_double_pionter string :\n%s",c);
    return 0;
}


