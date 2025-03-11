#include "func.h"
#include <stdio.h>
#include <stdlib.h>

LIST *initList()
{
    LIST *l = (LIST *)malloc(sizeof(LIST));
    if (l == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    l->element = 0;
    l->next = NULL;
    return l;
}

void insert(LIST *l, int element)
{
    LIST *newNode = (LIST *)malloc(sizeof(LIST));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->element = element;
    newNode->next = l->next;
    l->next = newNode;
    l->element++;
}

int deleteList(LIST *l, int index)
{
    if (index < 0 || index >= l->element)
    {
        printf("Invalid index:%d\n" , index);
        return -1;
    }
    LIST *temp = l;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    LIST *delNode = temp->next;
    temp->next = delNode->next;
    int element = delNode->element;
    free(delNode);
    l->element--;
    return element;
}

int isEmpty(LIST *l)
{
    return l->element == 0;
}

DELIST *initDEList()
{
    DELIST *l = (DELIST *)malloc(sizeof(DELIST));
    if (l == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    l->element = 0;
    l->prev = NULL;
    l->next = NULL;
    return l;
} // with head pointers

void insertDE(DELIST *l, int element)
{
    DELIST *newNode = (DELIST *)malloc(sizeof(DELIST));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    if (l->next == NULL)
    {
        l->prev = newNode;
    }
    else
    {
        newNode->next = l->next;
        l->next->prev = newNode;    
    }
    l->prev->next = newNode;
    newNode->element = element;
    newNode->prev = l->prev;
    l->next = newNode;
    l->element++;
}
// insert at the head of the list

int deleteDE(DELIST *l, int index)
{
    DELIST *temp = l;
    DELIST *delNode;
    if (index < 0)
    {
        while (++index)
        {
            temp = temp->prev;
        }
        delNode = temp->prev;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        delNode = temp->next;
    }
    int element = delNode->element;
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    l->prev = delNode->prev;
    l->next = delNode->next;
    free(delNode);
    l->element--;
    return element;
}
// delete the element at the given index

int isEmptyDE(DELIST *l)
{
    return l->element == 0;
}
// check if the list is empty:0 for empty, 1 for not empty
