#ifndef FUNC_H
#define FUNC_H

typedef struct Node {
    int op;
    int id;
}node;

void print_operation(int n);

void add_op(int op , int id);

void delete_op();

typedef struct Stack {
    int top;
    int elements[100];
}stack;

void create_stack(stack** s);

void push(stack* s, int value);

int top(stack* s);

void pop(stack* s);

typedef struct Destack {
    int top1;
    int top2;
    int elements[100];
    int n;
}destack;
//left is zhan, right is ans and the direction is from right to left

void create_destack(destack** d , int n);

void pushleft(destack* d, int value);

void pushright(destack* d, int value);

int topleft(destack* d);

void popleft(destack* d);

void popright(destack* d);

void printans(destack* d);


void copy_add_array(int *a, int *b, int n, int m);
#endif