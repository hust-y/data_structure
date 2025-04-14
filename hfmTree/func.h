#ifndef FUNC_H
#define FUNC_H

#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    char name;//0 for not leaf node
    struct Node *left;
    struct Node *right;
}node;
typedef struct Listelement{
    int value;
    node *Location;
}listelement;

typedef struct List{
    listelement *data;
    struct List *next;
}list;

void ini(node **root , char *dictionary);
// to generate the dictionary

void enc(const char *filename1, char *filename2 , char *dictionary);
//encode the 1 to 2;

void dec(const char *filename1, char *filename2 , char *dictionary);
//decode the 1 to 2;

void pri(const char *filename);
//print the dictionary;

void print_tree(node *root);
//print the tree;

#endif 