#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x) // ??
{
    if (top == MAX_SIZE - 1)
    {
        printf("The arrary is FUlly!");
        return;
    }
    A[++top] = x;
}
void pop() // ??
{
    if (-1 == top)
    {
        printf("The Stack is Empty!");
        return;
    }
    top--;
}

int view_top()
{
    return A[top];
}

void print()
{
    printf("The Stack content:");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    push(2);
    print(); // stack 2
    push(5);
    print(); // stack 5
    push(10);
    print(); // stack 10
    pop();
    print(); // stack 10
    push(12);
    print(); // stack 12
    return 0;
}