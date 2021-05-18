#include <stdio.h>
#include <stdlib.h>
#define R_SIZE 50
#define C_SIZE 50

struct node
{
    int row;
    int col;
    int value;
    struct node *nextInRow;
    struct node *nextInCol;
};

void make_matrix(int *matrix, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter element in [%d][%d]: ", i + 1, j + 1);
            scanf("%d", (matrix + i * n) + j);
        }
    }
}

int inLinklist(int *matrix, struct node *row_head[], struct node *column_head[], int m, int n)
{
    struct node *row_ptr[m], *column_ptr[n], *new_node;
    int i, j;
    for (i = 0; i < m; i++)
    {
        row_ptr[i] = row_head[i];
    }

    for (j = 0; j < n; j++)
    {
        column_ptr[j] = column_head[j];
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*((matrix + i * n) + j) != 0)
            {
                new_node = (struct node *)(malloc(sizeof(struct node)));
                if (new_node == NULL)
                {
                    printf("Memory allocation failed");
                    return -1;
                }
                else
                {
                    new_node->row = i;
                    new_node->col = j;
                    new_node->value = *((matrix + i * n) + j);
                    new_node->nextInRow = NULL;
                    new_node->nextInCol = NULL;

                    if (row_head[i] == NULL)
                    {
                        row_head[i] = new_node;
                        row_ptr[i] = new_node;
                    }
                    else
                    {
                        row_ptr[i]->nextInRow = new_node;
                        row_ptr[i] = new_node;
                    }

                    if (column_head[j] == NULL)
                    {
                        column_head[j] = new_node;
                        column_ptr[j] = new_node;
                    }
                    else
                    {
                        column_ptr[j]->nextInCol = new_node;
                        column_ptr[j] = new_node;
                    }
                }
            }
        }
    }
}

void print_link_list_matrix(struct node *row_head[], int m, int n)
{
    int i, k, j;
    for (i = 0; i < m; i++)
    {
        struct node *ptr = row_head[i];
        k = 0;
        while (ptr != NULL)
        {
            if (ptr->col == k)
            {
                printf("%d ", ptr->value);
                ptr = ptr->nextInRow;
                k++;
            }
            else
            {
                printf("0 ");
                k++;
            }
        }
        for (j = 0; j < n - k; j++)
        {
            printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int no_of_row, no_of_column;

    do
    {
        printf("Enter no. of row: ");
        scanf("%d", &no_of_row);
        if (no_of_row <= 0 || no_of_row > R_SIZE)
        {
            printf("Row size should be grater than 0 and less than %d\n ", R_SIZE);
        }

    } while (no_of_row <= 0 || no_of_row > R_SIZE);

    do
    {
        printf("Enter no. of column: ");
        scanf("%d", &no_of_column);
        if (no_of_column <= 0 || no_of_column > C_SIZE)
        {
            printf("Column size should be grater than 0 and less than %d\n ", C_SIZE);
        }

    } while (no_of_column <= 0 || no_of_column > C_SIZE);

    int matrix[no_of_row][no_of_column];

    make_matrix(&matrix[0][0], no_of_row, no_of_column);

    struct node *row_head[no_of_row], *column_head[no_of_column];

    int i;
    for (i = 0; i < no_of_row; i++)
    {
        row_head[i] = NULL;
    }

    for (i = 0; i < no_of_column; i++)
    {
        column_head[i] = NULL;
    }

    inLinklist(&matrix[0][0], row_head, column_head, no_of_row, no_of_column);

    print_link_list_matrix(row_head, no_of_row, no_of_column);

    return 0;
}