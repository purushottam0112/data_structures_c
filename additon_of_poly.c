#include <stdio.h>
#include <stdlib.h>
struct dynode
{
    struct dynode *prev;
    float coeff;
    int expo;
    struct dynode *next;
};

void dy_list(struct dynode **head, struct dynode **tail, int len)
{
    if (len == 0)
    {
        *head == NULL;
    }

    else if (len > 0)
    {
        struct dynode *ptr;
        struct dynode *new_nodes;
        new_nodes = (struct dynode *)malloc(sizeof(struct dynode));

        if (new_nodes == NULL)
        {
            printf("Memory allocation failed");
        }
        else
        {
            *head = new_nodes;
            ptr = *head;
            ptr->prev = NULL;

            printf("Enter coefficient\n");
            scanf("%f", &ptr->coeff);
            printf("Enter exponent\n");
            scanf("%d", &ptr->expo);
            int i;
            for (i = 1; i < len; i++)
            {
                new_nodes = (struct dynode *)malloc(sizeof(struct dynode));
                if (new_nodes == NULL)
                {
                    printf("Memory allocation failed");
                    break;
                }
                else
                {

                    ptr->next = new_nodes;
                    new_nodes->prev = ptr;
                    ptr = new_nodes;
                    printf("Enter coefficient\n");
                    scanf("%f", &ptr->coeff);
                    printf("Enter exponent\n");
                    scanf("%d", &ptr->expo);
                }
            }
            if (new_nodes != NULL)
            {
                ptr->next = NULL;
                *tail = ptr;
            }   
        }
    }
}

void printElement(struct dynode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo terms in your polynomial: ");
    }
    else
    {
        printf("\nPolynomial in forward direction: ");
        while (ptr != NULL)
        {
            printf("%f ", ptr->coeff);
            printf("%d  ", ptr->expo);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

int merge_of_poly(struct dynode **p1head, struct dynode **p1tail, struct dynode **p2head, struct dynode **p2tail, struct dynode **p3head, struct dynode **p3tail)
{
    if (*p1head == NULL)
    {
        *p3head = *p2head;
        *p3head = *p2tail;
    }
    else if (*p2head == NULL)
    {
        *p3head = *p1head;
        *p3tail = *p1tail;
    }
    else if (*p1head == NULL && *p2head == NULL)
    {
        *p3head = NULL;
        *p3tail = NULL;
    }
    else
    {
        (*p3head) = *p1head;
        (*p1tail)->next = *p2head;
        (*p2head)->prev = *p1tail;
        *p3tail = *p2tail;
    }
}

void sort(struct dynode **head, struct dynode **tail)
{
    struct dynode *ptr1;
    struct dynode *ptr2;
    ptr1 = *head;
    ptr2 = *head;
    int c;
    while (ptr1 != *tail)
    {
        while (ptr2 != *tail)
        {
            if (ptr1->expo < ptr2->next->expo)
            {
                c = ptr1->expo;
                ptr1->expo = ptr2->next->expo;
                ptr2->next->expo = c;

                c = ptr1->coeff;
                ptr1->coeff = ptr2->next->coeff;
                ptr2->next->coeff = c;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1;
    }
}

int add_of_poly(struct dynode **p1head, struct dynode **p1tail, struct dynode **p2head, struct dynode **p2tail, struct dynode **p3head, struct dynode **p3tail)
{

    merge_of_poly(&(*p1head), &(*p1tail), &(*p2head), &(*p2tail), &(*p3head), &(*p3tail));
    sort(&(*p3head), &(*p3tail));
    struct dynode *ptr = *p3head;

    if (ptr == NULL)
    {
        return -1;
    }

    else if (ptr->next == NULL)
    {
        return -1;
    }

    else
    {
        while (ptr->next != NULL)
        {
            if (ptr->expo == ptr->next->expo)
            {
                ptr->coeff = ptr->coeff + ptr->next->coeff;

                struct dynode *temp = ptr->next;

                if (ptr->next->next == NULL)
                {
                    ptr->next = NULL;
                    *p3tail = ptr;
                }
                else
                {
                    ptr->next->next->prev = ptr;
                    ptr->next = ptr->next->next;
                }
                free(temp);
            }
            else
                ptr = ptr->next;
        }
    }
}

int main()
{
    struct dynode *p1head = NULL, *p1tail = NULL;
    struct dynode *p2head = NULL, *p2tail = NULL;
    struct dynode *p3head = NULL, *p3tail = NULL;
    int len, user_ch;
    do
    {
        printf("Enter how many terms in your first polynomial: ");
        scanf("%d", &len);
        if (len < 0)
        {
            printf("Should be >= 0\n");
        }
    } while (len < 0);
    dy_list(&p1head, &p1tail, len);

    do
    {
        printf("\nEnter 1 for print first poly");
        printf("\nEnter 2 for print second poly");
        printf("\nEnter 3 for print third poly"); // third poly is add of first and 
        printf("\nEnter 4 for write second poly");
        printf("\nEnter 5 for adding first and second ploy");
        printf("\nEnter 6 for third to become first polynomial");
        printf("\nEnter ");
        scanf("%d", &user_ch);

        if (user_ch < 0 || user_ch > 7)
        {
            printf("Please Enter a valid number.\n");
        }
        else if (user_ch == 1)
        {
            printElement(p1head);
        }
        else if (user_ch == 2)
        {
            printElement(p2head);
        }
        else if (user_ch == 3)
        {
            printElement(p3head);
        }

        else if (user_ch == 4)
        {
            do
            {
                printf("Enter how many terms in your second polynomial: ");
                scanf("%d", &len);
                if (len < 0)
                {
                    printf("Should be >= 0\n");
                }
            } while (len < 0);
            dy_list(&p2head, &p2tail, len);
        }

        else if (user_ch == 5)
        {
            add_of_poly(&p1head, &p1tail, &p2head, &p2tail, &p3head, &p3tail);
            printElement(p3head);
        }
        else if (user_ch == 6)
        {
            p1head = p3head;
            p1tail = p3tail;
            p2head = p3head = NULL;
            p2tail = p3tail = NULL;
        }

    } while (user_ch != 0);
}
