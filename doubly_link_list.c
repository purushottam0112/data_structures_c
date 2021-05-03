#include <stdio.h>
#include <stdlib.h>

struct dynode
{
    struct dynode *prev;
    int data;
    struct dynode *next;
};

int dy_list(struct dynode **head, struct dynode **tail, int len)
{
    if (len == 0)
    {
        *head == NULL;
    }

    else if (len > 0)
    {
        struct dynode *ptr;
        struct dynode *new_nodes;
        new_nodes = (struct dynode*)malloc(sizeof(struct dynode));

        *head = new_nodes;
        ptr = *head;
        ptr->prev = NULL;

        printf("Enter elements\n");
        scanf("%d", &ptr->data);
        int i;
        for (i = 1; i < len; i++)
        {
            new_nodes = (struct dynode*)malloc(sizeof(struct dynode));
            ptr->next = new_nodes;
            new_nodes->prev = ptr;
            ptr = new_nodes;
            scanf("%d", &ptr->data);
        }
        ptr->next = NULL;
        *tail = ptr;
    }   
}

int merging(struct dynode **head, struct dynode **tail)
{
    struct dynode *head1 = NULL, *tail1 = NULL;
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
    dy_list(&head1, &tail1, len);

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
        (*tail)->next = head1;
        head1->prev = *tail;
        *tail = tail1;
    }
}

void linear_search(struct dynode *ptr, int val)
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
            ptr = ptr->next;
            pos_no++;
        }
    }
    if (found == 0)
    {
        printf("Element not found.");
    }
}

void insertion(struct dynode **head, struct dynode **tail, int pos, int val)
{
    struct dynode *ptr;
    ptr = *head;
    struct dynode *new_node;
    new_node = (struct dynode*)malloc(sizeof(struct dynode));
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
            new_node->next = NULL;
            *head = new_node;
            new_node->prev = NULL;
            *tail = new_node;
        }

        else if (pos == 1)
        {
            new_node->next = ptr;
            new_node->prev = ptr->prev;
            ptr->prev = new_node;
            *head = new_node;
        }

        else if (pos > 1)
        {
            int i = 1;
            while (i < pos - 1 && ptr->next != NULL)
            {
                ptr = ptr->next;
                i++;
            }
            new_node->next = ptr->next;
            new_node->prev = ptr;
            if (ptr->next != NULL)
            {
                ptr->next->prev = new_node;
            }
            else
            {
                *tail = new_node;
            }   
            ptr->next = new_node;
        }
    }
}


void printElement(struct dynode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo elements in your list: ");
    }
    else
    {
        printf("\nList in forward direction: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

void backward_dir(struct dynode *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo elements in your single link list: ");
    }
    else
    {
        printf("\nList in backward direction: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
    printf("\n");
}

void deletion(struct dynode **head, struct dynode **tail, int pos, int *ele)
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
        *head = ptr->next;
        if (ptr->next != NULL)
        {
            ptr->next->prev = NULL;
        }
        else
        {
            *tail = NULL;
        }
        *ele = ptr->data;
        free(ptr);
    }
    else if (pos > 1)
    {
        int i = 1;
        while (i < pos - 1 && ptr->next != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr->next == NULL)
        {
            printf("Deletion is not possible as position exceeds length of list: ");
        }
        else
        {
            struct dynode *temp;
            temp = ptr->next;
            if (temp->next != NULL)
            {
                temp->next->prev = ptr;
            }
            else
            {
                *tail = ptr;  
            }
            ptr->next = temp->next;
            *ele = temp->data;
            printf("\nElement %d is deleted at given position %d", *ele, pos);
            free(temp);
        }
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
            if (ptr1->data > ptr2->next->data)
            {
                c = ptr1->data;
                ptr1->data = ptr2->next->data;
                ptr2->next->data = c;
            } 
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1;
    }
}

int main()
{
    struct dynode *head = NULL, *tail = NULL;
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
    dy_list(&head, &tail, len);
    do
    {
        printf("\nEnter 1 for insertion: ");
        printf("\nEnter 2 for deletion: ");
        printf("\nEnter 3 for linearSearch: ");
        printf("\nEnter 4 for merge: ");
        printf("\nEnter 5 for sorting: ");
        printf("\nEnter 6 for forward print: ");
        printf("\nEnter 7 for backward print: ");
        printf("\nEnter 0 for exit: ");
        printf("\nEnter: ");
        scanf("%d", &user_ch);
        if (user_ch < 0 || user_ch > 7)
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
            insertion(&head, &tail, pos, val);
            printElement(head);
        }
        else if (user_ch == 2)
        {
            int pos, ele;
            printf("Enter the position where you want to delete: ");
            scanf("%d", &pos);
            deletion(&head, &tail, pos, &ele);
            printElement(head);
        }
        else if (user_ch == 3)
        {
            int val;
            printf("Enter which element you want to search: ");
            scanf("%d", &val);
            linear_search(head, val);
        }
        
        else if (user_ch == 4)
        {
            merging(&head, &tail);
        }

        else if (user_ch == 5)
        {
            sort(&head, &tail);
        }

        else if (user_ch == 6)
        {
            printElement(head);
        }

        else if (user_ch == 7)
        {
            backward_dir(tail);
        }
        
    } while (user_ch != 0);
    return 0;
}
////////////////////// PURUSHOTTAM KUMAR ///////////////////////
