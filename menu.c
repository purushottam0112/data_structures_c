#include <stdio.h>
#define SIZE 100
int linearSearch(int[], int, int);
int binary(int[], int, int, int, int);
int insertion(int[], int, int, int);
int deleting(int[], int, int);
void merge(int[], int[], int, int);
void insertSort(int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);
void quickSort(int[], int, int);
int main()
{
    int user_no, init_na, A[SIZE], na;
    do
    {
        printf("Enter the no. of element (<=%d) in the array_A: ", SIZE);
        scanf("%d", &na);
        if (na <= 0 || na > SIZE)
        {
            printf("\nEnter a value > 0 and <= %d\n", SIZE);
        }

    } while (na <= 0 || na > SIZE);

    do
    {
        printf("Enter the size of array_A(<= %d): ", na);
        scanf("%d", &init_na);
        if (init_na <= 0 || init_na > na)
        {
            printf("\nEnter a value > 0 and <= %d\n", na);
        }

    } while (init_na <= 0 || init_na > na);

    printf("Enter the value of array A: \n");
    for (int i = 0; i < init_na; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &A[i]);
    }

    do
    {
        printf("\n\nEnter 1 for linearSearch,\n");
        printf("Enter 2 for binarySearch,\n");
        printf("Enter 3 for insertion,\n");
        printf("Enter 4 for deleting,\n");
        printf("Enter 5 for insert sorting,\n");
        printf("Enter 6 for bubble sorting,\n");
        printf("Enter 7 for selection sorting,\n");
        printf("Enter 8 for quick sorting,\n");
        printf("Enter 9 for merging,\n");
        printf("Enter 0 for Exit,\n");

        printf("Enter: ");
        scanf("%d", &user_no);
        if (user_no < 0 || user_no > 9)
        {
            printf("Error: enter a valid number\n");
        }

        if (user_no < 0 || user_no > 9)
        {
            printf("Enter a valid number");
        }

        else if (user_no == 1)
        {
            int skey;
            printf("\nEnter the Search key: ");
            scanf("%d", &skey);
            int pos = linearSearch(A, skey, init_na);
            if (pos == -1)
            {
                printf("Search key is not in array A\n");
            }
            else
            {
                printf("The position of search key is %d", pos + 1);
            }
        }
        else if (user_no == 2)
        {
            int skey;
            printf("\nEnter the element you want to search: ");
            scanf("%d", &skey);
            int start = 0;
            int end = init_na - 1;
            int do_ = 0;
            for (int i = 0; i < init_na - 1; i++)
            {
                if (A[i + 1] < A[i])
                {
                    printf("In bineary search array must be in sorted form.\n");
                    do_ = -1;
                    break;
                }
            }

            if (do_ != -1)
            {
                int index = binary(A, init_na, skey, start, end);

                if (index == -1)
                {
                    printf("search key is not found");
                }
                else
                {
                    printf("Search key is found at the position of: %d", index + 1);
                }
            }
        }
        else if (user_no == 3)
        {
            if (na - init_na > 0)
            {
                int pos, num;
                printf("Enter which number you want to insert: ");
                scanf("%d", &num);
                do
                {
                    printf("Enter position where you want to insert: ");
                    scanf("%d", &pos);
                    if (pos > na || pos <= 0)
                    {
                        printf("Position must be less than %d and greater than 0", na);
                    }

                } while (pos > na || pos <= 0);

                insertion(A, init_na, pos, num);
                init_na += 1;

                printf("updated array_A: ");
                for (int i = 0; i < init_na; i++)
                {
                    printf("%d ", A[i]);
                }
            }
            else
            {
                printf("array A don't have a space to insert a new element");
            }
        }
        else if (user_no == 4)
        {
            int pos;
            do
            {
                printf("Enter the position where you want to delete element(1 <= position <= %d): ", init_na);
                scanf("%d", &pos);
                if (pos > init_na || pos <= 0)
                {
                    printf("\nPosition must be 1 <= position <= %d", init_na);
                }

            } while (pos > init_na || pos <= 0);

            deleting(A, init_na, pos);

            init_na -= 1;
            printf("updated array A: ");
            for (int i = 0; i < init_na; i++)
            {
                printf("%d ", A[i]);
            }
        }
        else if (user_no == 5)
        {
            insertSort(A, init_na);
            printf("After sorting array A become\nArray A = ");
            for (int i = 0; i < init_na; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }
        else if (user_no == 6)
        {
            bubbleSort(A, init_na);
            printf("After sorting array A become\nArray A = ");
            for (int i = 0; i < init_na; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }
        else if (user_no == 7)
        {
            selectionSort(A, init_na);
            printf("After sorting array A become\nArray A = ");
            for (int i = 0; i < init_na; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }

        else if (user_no == 8)
        {
            quickSort(A, 0, init_na - 1);
            printf("After sorting array A become\nArray A = ");
            for (int i = 0; i < init_na; i++)
            {
                printf("%d ", A[i]);
            }
            printf("\n");
        }

        else if (user_no == 9)
        {
            if (na - init_na > 0)
            {
                int SIZE_B = 100, nb;
                int B[SIZE_B];
                printf("Enter Array B which you want to merge with Array A.\n");
                do
                {
                    printf("First enter the size of array_B(<= %d) : ", na - init_na);
                    scanf("%d", &nb);
                    if (nb < 0 || nb > (na - init_na))
                    {
                        printf("Enter a value > 0 and <= %d\n", na - init_na);
                    }

                } while (nb < 0 || nb > (na - init_na));

                printf("Enter the value of array:\n");
                for (int i = 0; i < nb; i++)
                {
                    printf("b[%d] = ", i);
                    scanf("%d", &B[i]);
                }

                //////// print A and B
                printf("Array A: ");
                for (int i = 0; i < init_na; i++)
                {
                    printf("%d ", A[i]);
                }

                printf("Array B: ");
                for (int i = 0; i < nb; i++)
                {
                    printf("%d ", B[i]);
                }

                merge(A, B, init_na, nb);
                init_na += nb;
                printf("\nAfter merging array A become:\narray A = ");
                for (int i = 0; i < (init_na); i++)
                {
                    printf("%d ", A[i]);
                }
            }
            else
            {
                printf("array A don't have a space to merge with other array");
            }
        }
    } while (user_no != 0);
    return 0;
}

int linearSearch(int A[], int skey, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (A[i] == skey)
        {
            return i;
        }
    }
    return -1;
}

int binary(int A[], int init_na, int skey, int start, int end)
{
    int mid = (start + end) / 2;

    if (skey == A[mid])
    {
        return mid;
    }

    else if (skey == A[mid - 1])
    {
        return mid - 1;
    }
    
    else if (skey == A[mid + 1])
    {
        return mid + 1;
    }
    
    else if (mid == start || mid == end)
    {
        return -1;
    }

    else if (skey > A[mid])
    {
        return (binary(A, init_na, skey, mid + 1, end));
    }
    else if (skey < A[mid])
    {
        return (binary(A, init_na, skey, start, mid - 1));
    }
}

int insertion(int A[], int init_na, int pos, int num)
{
    if (pos > init_na)
    {
        A[init_na] = num;
    }
    else
    {
        for (int i = init_na - 1; i >= pos - 1; i--)
        {
            A[i + 1] = A[i];
        }
        A[pos - 1] = num;
    }
    // init_na += 1;
    // return init_na;
}

int deleting(int A[], int init_na, int pos)
{
    for (int i = pos - 1; i < init_na - 1; i++)
    {
        A[i] = A[i + 1];
    }
}

void insertSort(int A[], int init_na)
{
    int c;
    for (int i = 0; i < init_na; i++)
    {
        for (int j = i + 1; j < init_na; j++)
        {
            if (A[i] > A[j])
            {
                c = A[i];
                A[i] = A[j];
                A[j] = c;
            }
        }
    }
}

void merge(int A[], int B[], int init_na, int nb)
{
    for (int i = 0; i < (init_na + nb); i++)
    {
        if (i < init_na)
        {
            A[i] = A[i];
        }
        else if (i >= init_na)
        {
            A[i] = B[i - init_na];
        }
    }
}

void bubbleSort(int A[], int n)
{
    int c;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                c = A[j];
                A[j] = A[j + 1];
                A[j + 1] = c;
            }
        }
    }
}

void selectionSort(int A[], int n)
{
    int c;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] < A[j])
            {
                c = A[j];
                A[j] = A[i];
                A[i] = c;
            }
        }
    }
}

void quickSort(int arr[], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quickSort(arr, first, j - 1);
        quickSort(arr, j + 1, last);
    }
}