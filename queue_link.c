#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define SUCCESS 0

struct node
{
    int info;
    struct node *link;
};

int enqueue(struct node **front, struct node **rear, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Dynamic memory allocation failed");
        return ERROR;
    }
    else
    {
        new_node->info = data;
        new_node->link = NULL;
        if (*front == NULL)
        {
            *rear = new_node;
            *front = *rear;
        }
        else
        {
            (*rear)->link = new_node;
            *rear = new_node;
        }
        return SUCCESS;  
    }
}

int dequeue(struct node **front, struct node **rear, int *data)
{
    struct node *temp;
    if(*front == NULL)
    {
        printf("Queue is empty\n");
        return ERROR;
    }
    else
    {
        temp = *front;
        (*front) = (*front)->link;
        free(temp);
        return SUCCESS;
    }  
}

void display(struct node *front)
{
    struct node *ptr = front;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("The Queue is: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }  
        printf("\n"); 
    }  
}

int main()
{
    struct node *front = NULL, *rear = NULL;
    int data, user_ch, status;
    do
    {
        printf("Enter 1 for enqueue:\n");
        printf("Enter 2 for dequeue:\n");
        printf("Enter 3 for display:\n");
        printf("Enter 0 for exit:\n");
        scanf("%d", &user_ch);
        if (user_ch < 0 || user_ch > 3)
        {
            printf("Please enter a valid numbar\n");
        }
        
        else if (user_ch == 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
        }
        else if (user_ch == 2)
        {
            status = dequeue(&front, &rear, &data);
            if (status == 0)
                printf("Dequeue data is: %d\n", data);   
        }
        else if (user_ch == 3)
        {
            display(front);
        }
        
    } while (user_ch != 0);
    return 0;
}
