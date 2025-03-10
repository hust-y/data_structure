#include "func.h"
#include <stdio.h>
#include <stdlib.h>


LIST *initList(){
    LIST *l = (LIST *)malloc(sizeof(LIST));
    if (l == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    l->element = 0;
    l->next = NULL;
    return l;
}

void insert(LIST *l, int element){
    LIST *newNode = (LIST *)malloc(sizeof(LIST));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    if (l->next == NULL){
        l->next = newNode;
    }
    newNode->element = element;
    newNode->next = l->next;
    if(newNode->next == NULL)
    {
        newNode->next = l->next;
    }
    l->next = newNode;
    l->element++;
}

int deleteList(LIST *l, int index){
    if (index < 0 || index >= l->element){
        printf("Invalid index\n");
        return -1;
    }
    LIST *temp = l;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    LIST *delNode = temp->next;
    temp->next = delNode->next;
    int element = delNode->element;
    free(delNode);
    l->element--;
    return element;
}

int isEmpty(LIST *l){
    return l->element == 0;
}

DELIST *initDEList(){
    DELIST *l = (DELIST *)malloc(sizeof(DELIST));
    if (l == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    l->element = 0;
    l->prev = NULL;
    l->next = NULL;
    return l;
}//with head pointers

void insertDE(DELIST *l, int element)
{
    DELIST *newNode = (DELIST *)malloc(sizeof(DELIST));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    if(l->next == NULL)
    {
        l->prev = newNode;
        newNode->next = newNode;
    }else
    {
        newNode->next = l->next;
        l->next->prev = newNode;
    }
    newNode->element = element;
    newNode->prev = l->prev;
    l->next = newNode;
    l->element++;
}
//insert at the head of the list

int deleteDE(DELIST *l, int index)
{
    DELIST *temp = l;
    if(index < 0)
    {
        while(index++)
        {
            temp = temp->prev;
        }
        // DELIST *delNode = temp->prev;
        // temp->prev = delNode->prev;
        // delNode->prev->next = temp;
        // int element = delNode->element;
        // free(delNode);
        // l->element--;
        // return element;
    }else
    {
        for (int i = 0; i < index; i++){
            temp = temp->next;
        }
    }
    
    
    DELIST *delNode = temp->next;
    int element = delNode->element;
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    l->prev = delNode->prev;
    l->next = delNode->next;
    free(delNode);
    l->element--;
    return element;
}
//delete the element at the given index

int isEmptyDE(DELIST *l)
{
    return l->element == 0;
}
//check if the list is empty:0 for empty, 1 for not empty
