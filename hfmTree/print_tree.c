#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void print_tree(node *root, int n)
{
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
    if(root->name != 0)
    {
        printf("%c", root->name);
        return;
    }

    printf("\n");
    print_tree(root->left, n + 1);
    print_tree(root->right, n + 1);   
}
