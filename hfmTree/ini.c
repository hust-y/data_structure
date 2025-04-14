#include "func.h"
#include<stdbool.h>

static bool code[10];

void translate_tree_to_code(node *root , int x)
{
    if(root->name)
    {
        printf("%c " , root->name);
        for(int i = 0 ; i < x ; i++)
        {
            printf("%d" , code[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        code[x] = 0;
        translate_tree_to_code(root->left , x + 1);
        code[x] = 1;
        translate_tree_to_code(root->right , x + 1);
    }
}

void ini(node **root , char *dictionary)
{
    int n;
    char name[100];
    int freq[100];
    printf("Please input the number of words in the dictionary:");
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Please input the name and frequency of the word:\n");
        scanf("%s %d" , &name[i] , &freq[i]);
    }
    list *head = (list*)malloc(sizeof(list));
    head->next = NULL;
    for(int i = 0 ; i < n ; i++)
    {
        listelement *p = (listelement*)malloc(sizeof(listelement));
        p->value = freq[i];
        node *temp = (node*)malloc(sizeof(node));
        temp->name = name[i];
        temp->left = NULL;
        temp->right = NULL;
        p->Location = temp;
        list *p1 = head;
        while( p1->next && p1->next->data->value < p->value )
        {
            p1 = p1->next;
        }
        list *P = (list*)malloc(sizeof(list));
        P->data = p;
        P->next = p1->next;
        p1->next = P;
    }
    while(head->next && head->next->next)
    {
        listelement *p1 = head->next->data;
        listelement *p2 = head->next->next->data;
        head->next = head->next->next->next;
        node *temp = (node*)malloc(sizeof(node));
        temp->name = 0;
        temp->left = p1->Location;
        temp->right = p2->Location;
        listelement *p = (listelement*)malloc(sizeof(listelement));
        p->value = p1->value + p2->value;
        p->Location = temp;
        list *p3 = head;
        while( p3->next && p3->next->data->value < p->value )
        {
            p3 = p3->next;
        }
        list *P = (list*)malloc(sizeof(list));
        P->data = p;
        P->next = p3->next;
        p3->next = P;
        *root = p->Location;
    }

    freopen(dictionary , "w" , stdout);
    translate_tree_to_code(*root , 0);
}