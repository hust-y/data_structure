#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

#define N 10
#define M 5
#define T 1

int *solution_with_list(int n, int m);

int *solution_with_delist(int n, int m);

int *solution_with_sequence(int n, int m);

int main()
{
    srand(time(NULL));
    int n , m , t = T;
    int *ans1 = (int*)malloc(n * sizeof(int));
    int *ans2 = (int*)malloc(n * sizeof(int));
    int *ans3 = (int*)malloc(n * sizeof(int));
    while(t--)
    {
        n = 15, m = 1;
        ans1 = solution_with_list(n, m);
        ans2 = solution_with_delist(n, m);
        ans3 = solution_with_sequence(n, m);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n" , ans1[i] , ans2[i] , ans3[i]);
        if (ans1[i] != ans2[i])
        {
            printf("Error!\n");
            return 0;
        }
    }
    printf("It is OK!\n");
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
    int i , x = 0;
    for( i = n; i >= 1 ; i-- )
    {
        insert(l, i);
    }
    for( i = 0; i < n; i++ )
    {
        // printf("%d " , m);
        x += m - 1;
        x %= n - i;
        m = deleteList(l, x);

        *(arr + i) = m;
    }
    return arr;
}

int *solution_with_delist(int n, int m)
{
    int *arr = (int*)malloc(n * sizeof(int));
    DELIST *l = initDEList();
    int i,x;
    for( i = n; i >= 1 ; i-- )
    {
        insertDE(l, i);
    }
    for( i = 0; i < n; i++ )
    {
        // printf("%d\n" , x);
        // printf("%d " , m);
        int x = (m - 1) % (n - i);
        if (x > l->element / 2)
        {
            x = x - l->element - 1;
        }

        m = deleteDE(l, x);
        
        *(arr + i) = m;
    }
    return arr;
}

int* solution_with_sequence(int n, int m) {
    int *arr = (int*)malloc(n * sizeof(int));
    int *circle = (int*)malloc(n * sizeof(int));
    int i, pos = 0;
    for (i = 0; i < n; i++) {
        circle[i] = i + 1;
    }

    int remaining = n;
    for (i = 0; i < n; i++) {
        pos = (pos + m - 1) % remaining;
        arr[i] = circle[pos];
        m = arr[i];
        for (int j = pos; j < remaining - 1; j++) {
            circle[j] = circle[j + 1];
        }
        remaining--;
    }

    free(circle);
    return arr;
}