#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define SUCCESS 0
struct stack_node
{
    int data;
    struct stack_node *link;
};
int push(struct stack_node **top, int val)
{
    struct stack_node *new_node, *ptr;
    new_node = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (new_node == NULL)
    {
        return ERROR;
    }
    else
    {
        new_node->data = val;
        if (*top == NULL)
        {
            *top = new_node;
            new_node->link = NULL;
            printf("Push operation is successfully completed\n");
            return SUCCESS;
        }

        else
        {
            (new_node)->link = (*top);
            *top = new_node;
            printf("Push operation for data %d is successfully completed\n", val);
            return SUCCESS;
        }
    }
}
int pop(struct stack_node **top, int *val)
{
    struct stack_node *ptr;
    if (*top == NULL)
    {
        printf("Stack underflow,so,Pop operation failed\n");
        return ERROR;
    }
    else
    {
        ptr = *top;
        *val = (*top)->data;
        (*top) = (*top)->link;
        free(ptr);
        printf("Pop operation for item %d is successfully completed\n", *val);
    }
    return SUCCESS;
}
int disp(struct stack_node *top)
{
    struct stack_node *ptr;
    if (top == NULL)
        printf("\nStack is empty\n");
    else
    {
        ptr = top;
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->link;
        }
    }
}
int main()
{
    int val, user_ch;
    struct stack_node *top = NULL;
    do
    {
        printf("\nEnter 1 for Pushing in Stack\n");
        printf("Enter 2 for Poping in Stack\n");
        printf("Enter 3 for Displaying the Stack\n");
        printf("Enter 0 to exit the Program\n");
        printf("Enter: ");
        scanf("%d", &user_ch);

        if (user_ch == 1)
        {

            printf("Enter the element for stack push: \n");
            scanf("%d", &val);
            push(&top, val);
        }
        else if (user_ch == 2)
        {

            pop(&top, &val);
        }
        else if (user_ch == 3)
        {
            printf("Elements in the Stack are as follows:\n");
            disp(top);
        }
    } while (user_ch != 0);
    return 0;
}


