#include <stdio.h>
#define MAXQUEUE 5
#define ERROR -1
#define SUCCESS 0

int enqueue(int item[], int *front, int *rear, int data)
{
    if (*rear == MAXQUEUE - 1)
    {
        printf("\n Queue is full");
        return ERROR;
    }
    else
    {
        *rear = *rear + 1;
        item[*rear] = data;
        return SUCCESS;
    }   
}

int dequeue(int item[], int *front, int *rear, int *data, int *status)
{
    int i;
    if (*front > *rear)
    {
        return ERROR;
    }
    else
    {
        *data = item[*front];
        for (int i = 0; i <= *rear; i++)
        {
            item[i] = item[i + 1];
        }
        *rear--;
        return SUCCESS;
    }
}

void display(int item[], int front, int rear)
{
    printf("f %d", front);
    printf("r %d \n", rear);
    if (front > rear)
    {
        printf("Queue is empty \n");
    }
    else
    {
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", item[i]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int item[MAXQUEUE], front = 0, rear = -1, user_ch, data, status;
    do
    {
        printf("Enter 1 for enqueue:\n");
        printf("Enter 2 for dequeue:\n");
        printf("Enter 3 for display:\n");
        printf("Enter 0 for exit:\n");
        scanf("%d", &user_ch);
        if (user_ch == 1)
        {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(item, &front, &rear, data);
        }
        else if (user_ch == 2)
        {
            status = dequeue(item, &front, &rear, &data, &status);
            if (status == -1)
            {
                printf("Queue is empty \n");
            }
            else if (status == 0)
            {
                printf("Dequeue data is %d \n", data);
            }
        }
        else if (user_ch == 3)
        {
            display(item, front, rear);
        }
        
    } while (user_ch != 0);

    return 0;
}
