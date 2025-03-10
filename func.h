#ifndef FUNC_H
#define FUNC_H

typedef struct List{
    int element;
    struct List *next;
}LIST;

typedef struct double_ended_list{
    int element;
    struct double_ended_list *prev;
    struct double_ended_list *next;
}DELIST;

LIST *initList();

void insert(LIST *l, int element);
//insert at the head of the list

int deleteList(LIST *l, int index);
//delete the element at the given index

int isEmpty(LIST *l);
//check if the list is empty:0 for empty, 1 for not empty

DELIST *initDEList();

void insertDE(DELIST *l, int element);
//insert at the head of the list

void deleteDE(DELIST *l, int index);
//delete the element at the given index

int isEmptyDE(DELIST *l);
//check if the list is empty:0 for empty, 1 for not empty

#endif