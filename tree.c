#include <stdio.h>
#include <stdlib.h>
struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *newnode(int data)
{
    struct treenode *node;
    node = (struct treenode *)malloc(sizeof(struct treenode));
    if (newnode == NULL)
    {
        printf("Dynamic memory allocation failed\n");
        return NULL;
    }
    else
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return (node);
    }
}

struct treenode *Insertion(struct treenode **root, int data)
{
    if (*root == NULL)
    {
        *root = newnode(data);
        return (*root);
    }
    else
    {
        if (data <= (*root)->data)
        {
            return (Insertion(&((*root)->left), data));
        }
        else
        {
            return (Insertion(&((*root)->right), data));
        }
    }
}
void Inorder_display(struct treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        Inorder_display(root->left);
        printf("%d  ", root->data);
        Inorder_display(root->right);
    }
}

struct treenode *search(struct treenode *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (target == root->data)
        {
            return root;
        }
        else
        {
            if (target < root->data)
                return (search(root->left, target));
            else
                return (search(root->right, target));
        }
    }
}

int main()
{
    struct treenode *root = NULL, *res;
    int data, n, i, target;

    printf("Enter the number of elements in the tree.\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        Insertion(&root, data);
    }
    Inorder_display(root);
    printf("\nEnter your target which you want to search:\n ");
    scanf("%d\n", &target);
    res = search(root, target);
    if (res == NULL)
        printf("Target not found");
    else
    {
        printf("Target found in tree ");
    }
}