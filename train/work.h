#ifndef WORK_H
#define WORK_H

#include "func.h"

void work1(int n);

void work2(int n);

void work2_print_ans(int n);

void work2_dfs(int pos , int id , int n , stack *s);

void work3(int n);

void work3_dfs(int pos , int id , int n , destack *s);

void work4(int n);
#define MAX 1000
int cattelan[MAX];

void set_cattelan(int n);
void display_ans(int n, int *ans, int nth_cattelan);
void get_ith_ans(int i, int n,  int *ans, int *temp);
void set_one(int i, int *ans, int n);
void set_pre(int i, int *ans, int *temp, int n);
void set_end(int i, int *ans, int *temp, int n);

void print_oneline(int *a, int n);

#endif