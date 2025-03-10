#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

#define N 500
#define M 1000
#define T 1000

int *solution_with_list(int n, int m);

int *solution_with_delist(int n, int m);

int main()
{
    srand(time(NULL));
    int n , m , t = T;
    int *ans1 = (int*)malloc(n * sizeof(int));
    int *ans2 = (int*)malloc(n * sizeof(int));
    while(t--)
    {
        n = 10, m = 1;
        ans1 = solution_with_list(n, m);
        ans2 = solution_with_delist(n, m);
    }
    // check the correctness of the solution
    float begin, end;
    t = T;
    begin = clock();
    while(t--)
    {
        int n = N, m = rand() % M + 1;
        solution_with_list(n, m);
    }
    end = clock();
    printf("Time taken by solution_with_list() is %f seconds\n", (end - begin) / CLOCKS_PER_SEC);
    begin = clock();
    while(t--)
    {
        int n = N, m = rand() % M + 1;
        solution_with_delist(n, m);
    }
    end = clock();
    printf("Time taken by solution_with_delist() is %f seconds\n", (end - begin) / CLOCKS_PER_SEC);
}

int *solution_with_list(int n, int m)
{
    int *arr = (int*)malloc(n * sizeof(int));
    LIST *l = initList();
    int i;
    for( i = n; i >= 1 ; i-- )
    {
        insert(l, i);
    }
    for( i = 0; i < n; i++ )
    {
        int x = (m - 1) % (n - i);
        m = deleteList(l, x);
        *(arr + i) = m;
    }
    return arr;
}

int *solution_with_delist(int n, int m)
{
    int *arr = (int*)malloc(n * sizeof(int));
    DELIST *l = initDEList();
    int i,x=1;
    for( i = n; i >= 1 ; i-- )
    {
        insertDE(l, i);
    }
    for( i = 0; i < n; i++ )
    {
        int x = (m - 1) % (n - i);
        if (x > l->element / 2)
        {
            x = x - l->element;
        }

        m = deleteDEList(l, x);
        *(arr + i) = m;
    }
    return arr;
}