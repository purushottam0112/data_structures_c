#include <stdio.h>
#include <stdlib.h>

struct dynode
{
    struct dynode *prev;
    int data;
    struct dynode *next;
};

int dy_list(struct dynode **head, int len)
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

        *head = new_nodes;
        ptr = *head;

        printf("Enter elements\n");
        scanf("%d", &ptr->data);
        int i;
        for (i = 1; i < len; i++)
        {
            new_nodes = (struct dynode *)malloc(sizeof(struct dynode));
            ptr->next = new_nodes;
            new_nodes->prev = ptr;
            ptr = new_nodes;
            scanf("%d", &ptr->data);
        }
        ptr->next = (*head);
        (*head)->prev = ptr;
        // *tail = ptr;
    }
}

void printElement(struct dynode **head)
{
    if ((*head) == NULL)
    {
        printf("\nNo elements in your list: ");
    }
    else
    {
        struct dynode *ptr;
        ptr = (*head);

        printf("\nList in forward direction: ");

        printf("%d ", ptr->data);
        ptr = ptr->next;
        while (ptr != (*head))
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void backward_dir(struct dynode **head)
{
    if ((*head) == NULL)
    {
        printf("\nNo elements in your single link list: ");
    }
    else
    {
        struct dynode *ptr;
        ptr = (*head)->prev;

        printf("\nList in backward direction: ");

        printf("%d ", ptr->data);
        ptr = ptr->prev;

        while (ptr != (*head)->prev)
        {
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
    printf("\n");
}

void insertion(struct dynode **head, int pos, int val)
{
    struct dynode *ptr;
    ptr = *head;
    struct dynode *new_node;
    new_node = (struct dynode *)malloc(sizeof(struct dynode));
    if (new_node == NULL)
    {
        printf("Dynamic memory allocation failed, Insertion can not be down");
    }
    else
    {
        new_node->data = val;
        if (pos < 1)
        {
            printf("Error: Invalid position");
        }

        else if (ptr == NULL)
        {
            new_node->next = new_node;
            *head = new_node;
            new_node->prev = new_node;
            // *tail = new_node;
        }

        else if (pos == 1)
        {
            new_node->next = ptr;
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node;
            ptr->prev = new_node;
            *head = new_node;
        }

        else if (pos > 1)
        {
            int i = 1;
            while (i < pos - 1 && ptr->next != *head)
            {
                ptr = ptr->next;
                i++;
            }
            new_node->next = ptr->next;
            new_node->prev = ptr;
            // if (ptr->next != NULL)
            // {
            ptr->next->prev = new_node;
            // }
            // else
            // {
            //     *tail = new_node;
            // }
            ptr->next = new_node;
        }
    }
}

void deletion(struct dynode **head, int pos, int *ele)
{
    struct dynode *ptr;
    ptr = *head;
    if (pos < 1)
    {
        printf("Inappropriate position, so deletion is not posible.");
    }

    else if (ptr == NULL)
    {
        printf("Deletion is not possible as list is already empty.");
    }

    else if (pos == 1)
    {
        if (ptr == ptr->prev)
        {
            *head = NULL;
        }
        else
        {
            *head = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
        }
        *ele = ptr->data;

        free(ptr);
    }
    else if (pos > 1)
    {
        int i = 1;
        while (i < pos - 1 && ptr->next != (*head))
        {
            ptr = ptr->next;
            // printf("while %d", ptr);
            i++;
        }
        if (ptr->next == (*head))
        {
            printf("Deletion is not possible as position exceeds length of list: ");
        }
        else
        {
            struct dynode *temp;
            temp = ptr->next;

            temp->next->prev = ptr;

            ptr->next = temp->next;
            *ele = temp->data;
            printf("\nElement %d is deleted at given position %d", *ele, pos);
            free(temp);
        }
    }
}

int linear_search(struct dynode **head, int val)
{
    int pos_no = 1;
    int found = 0;
    struct dynode *ptr = *head;
    
    if (ptr == NULL)
    {
        printf("List is empty that why searching not possible");
        return 0;
    }
    
    else
    {
        do
        {
            if (ptr->data == val)
            {
                printf("Element found at position no.: %d", pos_no);
                found++;
                break;
            }
            else
            {
                ptr = ptr->next;
                pos_no++;
            }
        } while (ptr != *head);
    }

    if (found == 0)
    {
        printf("Element not found.");
        return 0;
    }
}

int merging(struct dynode **head)
{
    struct dynode *head1 = NULL;
    int len, user_ch;
    do
    {
        printf("Enter how many element you want to marge with first list: ");
        scanf("%d", &len);
        if (len < 0)
        {
            printf("Should be >= 0\n");
        }
    } while (len < 0);
    dy_list(&head1, len);

    struct dynode *ptr;
    ptr = *head;
    if (ptr == NULL)
    {
        *head = head1;
    }
    else if (head1 == NULL)
    {
        return 0;
    }
    
    else
    {
        (*head)->prev->next = head1;
        head1->prev->next = (*head);
        head1->prev = (*head)->prev;
    }
}

int main()
{
    struct dynode *head = NULL;
    int len, user_ch;
    do
    {
        printf("Enter how many element you want to insert: ");
        scanf("%d", &len);
        if (len < 0)
        {
            printf("Should be >= 0\n");
        }
    } while (len < 0);
    dy_list(&head, len);
    do
    {
        printf("\nEnter 1 for insertion: ");
        printf("\nEnter 2 for deletion: ");
        printf("\nEnter 3 for linearSearch: ");
        printf("\nEnter 4 for merge: ");
        printf("\nEnter 5 for forward print: ");
        printf("\nEnter 6 for backward print: ");
        printf("\nEnter 0 for exit: ");
        printf("\nEnter: ");
        scanf("%d", &user_ch);
        if (user_ch < 0 || user_ch > 6)
        {
            printf("Please Enter a valid number.\n");
        }

        if (user_ch == 1)
        {
            int val, pos;
            printf("Enter the value which you want to insert: ");
            scanf("%d", &val);
            printf("Enter the position where you want to insert: ");
            scanf("%d", &pos);
            insertion(&head, pos, val);
            printElement(&head);
        }
        else if (user_ch == 2)
        {
            int pos, ele;
            printf("Enter the position where you want to delete: ");
            scanf("%d", &pos);
            deletion(&head, pos, &ele);

            printElement(&head);
        }
        else if (user_ch == 3)
        {
            int val;
            printf("Enter which element you want to search: ");
            scanf("%d", &val);
            linear_search(&head, val);
        }

        else if (user_ch == 4)
        {
            merging(&head);
        }

        else if (user_ch == 5)
        {
            printElement(&head);
        }

        else if (user_ch == 6)
        {
            backward_dir(&head);
        }

    } while (user_ch != 0);
    return 0;
}
