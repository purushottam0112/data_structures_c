#include <stdio.h>

#define MAX 100
#define ERROR -1
#define SUCCESS 0


int push(int stack[], int ele, int *top)
{
    if (*top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        ++*top;
        stack[(*top)] = ele;
        printf("Sucessfully pusing\n");
    }     
}

int pop(int stack[], int *ele, int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    
    else
    {
        *ele = stack[*top];
        --*top;
    }
}

int display(int stack[], int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }   
    }
}

int main()
{
    int stack[MAX], ele, status, top = -1, user_ch;
    do
    {
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter 0 for exit\n");
        printf("Enter-> ");
        scanf("%d", &user_ch);
        if (user_ch == 1)
        {
            printf("Enter which element you want to insert: ");
            scanf("%d", &ele);
            push(stack, ele, &top);
        }
        else if (user_ch == 2)
        {
            pop(stack, &ele, &top);   
        }
        else if (user_ch == 3)
        {
            display(stack, top);
        }  
    } while (user_ch != 0); 
    return 0;  
}

