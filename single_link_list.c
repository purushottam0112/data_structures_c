#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void create_list(struct node **head, int len)
{
    if (len == 0)
    {
        *head == NULL;
    }

    else if (len > 0)
    {
        struct node *ptr;
        struct node *new_nodes;
        new_nodes = (struct node*)malloc(sizeof(struct node));
        *head = new_nodes;

        ptr = *head;
        printf("Enter elements\n ");
        scanf("%d", &ptr->data);
        int i;
        for (i = 1; i < len; i++)
        {
            new_nodes = (struct node*)malloc(sizeof(struct node));
            ptr->link = new_nodes;
            ptr = new_nodes;
            scanf("%d", &ptr->data);
        }
        ptr->link = NULL;
    }
}

void printElement(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo elements in your single link list: ");
    }
    else
    {
        printf("\nlist: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
    printf("\n");
}

void linear_search(struct node *ptr, int val)
{
    int pos_no = 1;
    int found = 0;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("Element found at position no.: %d", pos_no);
            found++;
            break;
        }
        else
        {
            ptr = ptr->link;
            pos_no++;
        }
    }
    if (found == 0)
    {
        printf("Element not found.");
    }
}

void insertion(struct node **head, int pos, int val)
{
    struct node *ptr;
    ptr = *head;
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
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
            new_node->link = NULL;
            *head = new_node;
        }

        else if (pos == 1)
        {
            new_node->link = ptr;
            *head = new_node;
        }

        else if (pos > 1)
        {
            int i = 1;
            while (i < pos - 1 && ptr->link != NULL)
            {
                ptr = ptr->link;
                i++;
            }
            new_node->link = ptr->link;
            ptr->link = new_node;
        }
    }
}

void deletion(struct node **head, int pos, int *ele)
{
    struct node *ptr;
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
        *head = ptr->link;
        *ele = ptr->data;
        free(ptr);
    }
    else if (pos > 1)
    {
        int i = 1;
        while (i < pos - 1 && ptr->link != NULL)
        {
            ptr = ptr->link;
            // printf("while %d", ptr);
            i++;
        }
        if (ptr->link == NULL)
        {
            printf("Deletion is not possible as position exceeds length of list: ");
        }
        else
        {
            struct node *temp;
            temp = ptr->link;
            ptr->link = ptr->link->link;
            *ele = temp->data;
            printf("\nElement %d is deleted at given position %d", *ele, pos);
            free(temp);
        }
    }
}
void merging(struct node **head)
{
    struct node *head1 = NULL;
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
    create_list(&head1, len);

    struct node *ptr;
    ptr = *head;
    if (ptr == NULL)
    {
        *head = head1;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = head1;
    }
}

int main()
{
    struct node *head = NULL;
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

    create_list(&head, len);
    do
    {
        printf("\nEnter 1 for insertion: ");
        printf("\nEnter 2 for deletion: ");
        printf("\nEnter 3 for linearSearch: ");
        printf("\nEnter 4 for merge: ");
        printf("\nEnter 5 for print: ");
        printf("\nEnter 0 for exit: ");
        printf("\nEnter: ");
        scanf("%d", &user_ch);
        if (user_ch < 0 || user_ch > 5)
        {
            printf("Please Enter a valid number.\n");
            
        }

        else if (user_ch == 1)
        {
            int val, pos;
            printf("Enter the value which you want to insert: ");
            scanf("%d", &val);
            printf("Enter the position where you want to insert: ");
            scanf("%d", &pos);
            insertion(&head, pos, val);
            printElement(head);
        }
        else if (user_ch == 2)
        {
            int pos, ele;
            printf("Enter the position where you want to delete: ");
            scanf("%d", &pos);
            deletion(&head, pos, &ele);
            // printf("\nElement %d is deleted at given position %d", ele, pos);
            printElement(head);
        }
        else if (user_ch == 3)
        {
            int val;
            printf("Enter which element you want to search: ");
            scanf("%d", &val);
            linear_search(head, val);
        }
        
        else if (user_ch == 5)
        {
            printElement(head);
        }
        else if (user_ch == 4)
        {
            merging(&head);
        }

    } while (user_ch != 0);

    return 0;
}
