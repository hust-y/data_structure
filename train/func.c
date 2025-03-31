#include "func.h"
#include <stdio.h>
#include <stdlib.h>

node operations[100];

void print_operation(int n)
{
    for( int i = 1 ; i <= n ; i++ )
    {
        printf("%s %d\n", operations[i].op, operations[i].id);
    }
    return;
}

void create_stack(stack** s)
{
    stack* t = (stack*)malloc(sizeof(stack));
    t->top = 0;
    *s = t;
}

void push(stack* s, int value)
{
    s->elements[++s->top] = value;
}

int top(stack* s)
{
    if( s->top == 0 ){
        printf("error: stack is empty\n");
        return -1;
    }
    return s->elements[s->top];
}

void pop(stack* s)
{
    s->top--;
}

void create_destack(destack* d , int n)
{
    d = (destack*)malloc(sizeof(destack));
    d->top1 = 0;
    d->top2 = n + 1;
    d->n = n;
    return ;
}

void pushleft(destack* d, int value)
{
    d->elements[++d->top1] = value;
}

void pushright(destack* d, int value)
{
    d->elements[--d->top2] = value;
}

int topleft(destack* d)
{
    if( d->top1 == 0)
    {
        printf("error: stack is empty\n");
        return -1;
    }else
    {
        return d->elements[d->top1];
    }
}

void printans(destack* d)
{
    for( int i = d->n ; i >= 1 ; i-- )
    {
        printf("%d ", d->elements[i]);
    }

}