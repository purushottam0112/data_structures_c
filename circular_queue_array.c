#include <stdio.h>
#define MAXQUEUE 6
#define ERROR -1
#define SUCCESS 0

struct cqueue
{
    int item[MAXQUEUE];
    int rear;
    int front;
};

int enqueue(struct cqueue *cq_ptr, int data)
{    
    if ((cq_ptr->front % MAXQUEUE) == ((cq_ptr->rear + 1) % MAXQUEUE))
    {
        printf("Queue is full\n");
        return ERROR;
    }
    else
    {
        if (cq_ptr->front == -1)
        {
            cq_ptr->front++;
        }
        
        (cq_ptr->rear)++;
        cq_ptr->item[(cq_ptr->rear) % MAXQUEUE] = data;
        return SUCCESS;
    } 
}

int dequeue(struct cqueue *cq_ptr, int *data)
{
    if (cq_ptr->front == -1)
    {
        printf("Queue is empty\n");
        return ERROR;
    }
    else
    {
        *data = cq_ptr->item[(cq_ptr->front) % MAXQUEUE];
        if ((cq_ptr->front) % MAXQUEUE == (cq_ptr->rear) % MAXQUEUE)
        {
            cq_ptr->rear = -1;
            cq_ptr->front = -1;
        }
        else
        {
            cq_ptr->front++;
        }
        return SUCCESS;
    }
}

void display(struct cqueue cq)
{
    if (cq.front == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("The Queue is ");
        while (cq.front <= cq.rear)
        {
            printf("%d ", cq.item[(cq.front) % MAXQUEUE]);
            cq.front++;
        }
    }
    printf("\n");
}

int main()
{
    struct cqueue cq;
    int data, user_ch, status;
    cq.front = -1;
    cq.rear = -1;

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
            enqueue(&cq, data);
        }
        else if (user_ch == 2)
        {
            status = dequeue(&cq, &data);
            if (status == 0)
                printf("Dequeue data is: %d\n", data);   
        }
        else if (user_ch == 3)
        {
            display(cq);
        }
        
    } while (user_ch != 0);
    
    return 0;
}

