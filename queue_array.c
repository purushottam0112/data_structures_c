#include <stdio.h>
#define MAXQUEUE 5
#define ERROR -1
#define SUCCESS 0

struct queue
{
    int item[MAXQUEUE];
    int front;
    int rear;
};
int enqueue(struct queue *qptr, int data)
{
    if(qptr->rear == MAXQUEUE - 1)
    {
        printf("Queue is full!\n");
        return ERROR;
    }
    else
    {
        qptr->rear++;
        qptr->item[qptr->rear] = data;
        return SUCCESS;
    }
}

int dequeue(struct queue *qptr, int *data)
{
    int i;
    if (qptr->front > qptr->rear)
    {
        printf("Queue is empty\n");
        return ERROR;
    }
    else
    {
        *data = qptr->item[qptr->front];
        for (int i = qptr->front; i <= qptr->rear; i++)
        {

            qptr->item[i] = qptr->item[i + 1];
        }
        qptr->rear--;
        return SUCCESS;   
    } 
}
void display(struct queue q)
{
    int i;
    if (q.front > q.rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("\nThe Queue is: ");
        for (int i = 0; i <= q.rear; i++)
        {
            printf("%d ", q.item[i]);
        }
        printf("\n");   
    }   
}

int main(int argc, char const *argv[])
{
    struct queue q;
    int data, user_ch;
    q.front = 0;
    q.rear = -1;

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
            enqueue(&q, data);
        }
        else if (user_ch == 2)
        {
            dequeue(&q, &data);
            printf("Dequeue data is: %d\n", data);
        }
        else if (user_ch == 3)
        {
            display(q);
        }
        
    } while (user_ch != 0);

    return 0;
}

