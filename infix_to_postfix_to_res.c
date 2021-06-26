#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
#define SUCCESS 0
#define ERROR -1
struct stack
{
    int stack[SIZE];
    int top;
};

void stack_push(char stack[], int *top, char item)
{
    if (*top == (SIZE - 1))
    {
        printf("Stack overflow and hence push operation is unsuccessful\n");
    }
    else
    {
        (*top)++;
        stack[*top] = item;
    }
}
void intg_push(int stack[], int *top, int item)
{
    if (*top == (SIZE - 1))
    {
        printf("Stack overflow and hence push operation is unsuccessful\n");
    }
    else
    {
        (*top)++;
        stack[*top] = item;
    }
}
char stack_pop(char stack[], int *top, char *item)
{
    if (*top == -1)
    {
        printf("Stack underflow and hence pop operation is unsuccessful\n");
    }
    else
    {
        *item = stack[*top];
        (*top)--;
        return *item;
    }
}
char intg_pop(int stack[], int *top, int *item)
{
    if (*top == -1)
    {
        printf("Stack underflow and hence pop operation is unsuccessful\n");
    }
    else
    {
        *item = stack[*top];
        (*top)--;
        return *item;
    }
}
int priority(char p)
{
    if (p == '/' || p == '*')
    {
        return 2;
    }
    else if (p == '+' || p == '-')
    {
        return 1;
    }
    else if (p == '(')
    {
        return 0;
    }
}

int InfixToPostfix(int *top, char exp[], char postfix[], char stack[])
{
    int i = 0, j;
    char item;
    
    while (exp[i] != '\0')
    {
        if (isalpha(exp[i]) || isdigit(exp[i]))
        {
            // printf("%c", exp[i]);
            strncat(postfix, &exp[i], 1);
        }
        else if (exp[i] == '(')
            stack_push(stack, top, exp[i]);

        else if (exp[i] == ')')
        {
            while (stack[*top] != '(')
            {
                stack_pop(stack, top, &item);
                // printf("%c", item);
                strncat(postfix, &item, 1);
            }
            stack_pop(stack, top, &item);
        }
        else if (exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-')
        {
            if (*top == -1)
            {
                stack_push(stack, top, exp[i]);
            }
            else
            {
                if (priority(stack[*top]) < priority(exp[i]))
                {
                    stack_push(stack, top, exp[i]);
                }
                else if (priority(stack[*top]) >= priority(exp[i]) && *top != -1)
                {
                    {
                        stack_pop(stack, top, &item);
                        // printf("%c", item);
                        strncat(postfix, &item, 1);
                    }
                    stack_push(stack, top, exp[i]);
                }
            }
        }
        i++;
    }
    while (*top != -1)
    {
        stack_pop(stack, top, &item);
        // printf("%c", item);
        strncat(postfix, &item, 1);
    }
    return SUCCESS;
}
int char_to_int(char ch)
{
    int integer_value = (int)ch - 48;
    return integer_value;
}
int operation(int op1, int op2, char operator)
{
    int result;
    if (operator== '*')
    {
        result = op1 * op2;
    }
    else if (operator == '/')
    {
        result = op1 / op2;
    }
    else if (operator == '+')
    {
        result = op1 + op2;
    }
    else if (operator == '-')
    {
        result = op1 - op2;
    }
    return result;
}
int Evaluation(char postfix[])
{
    int i = 0, result, intg_top = -1, intg_stack[SIZE];
    int op1, op2;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            intg_push(intg_stack, &intg_top, char_to_int(postfix[i]));
        }
        else
        {
            intg_pop(intg_stack, &intg_top, &op2);
            intg_pop(intg_stack, &intg_top, &op1);
            result = operation(op1, op2, postfix[i]);
            intg_push(intg_stack, &intg_top, result);
        }
        i++;
    }
    intg_pop(intg_stack, &intg_top, &result);
    printf("\nThe Result of the given infix expression is: %d", result);
}
int main()
{
    int status, top = -1,c;
    char exp[SIZE], postfix[SIZE], stack[SIZE];
    printf("Enter the Infix expression: ");
    scanf("%s", &exp);
    printf("Postfix expression of given infix expression is: ");
    char_to_int(c);
    InfixToPostfix(&top, exp, postfix, stack);
    puts(postfix);
    printf("%s",postfix);
    Evaluation(postfix);
}