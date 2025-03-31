#include <stdio.h>
#include "work.h"
#include <stdlib.h>

int ans[100];

void dfs(int pos , int id , int n , stack *s)
{
    // printf("dfs(%d, %d, %d, %d)\n", pos, id, n, s->top);
    // system("pause");
    if(pos == n+1)
    {
        work2_print_ans(n);
        return;
    }
    if(s->top)
    {
        int x = top(s);
        pop(s);
        ans[pos] = x;
        dfs(pos+1 , id , n , s);
        push(s, x);
    }
    if(id <= n )
    {
        push(s , id);
        ans[pos] = id;
        dfs(pos , id+1 , n , s);
        pop(s);
    }
    
}

void work2( int n) 
{
    stack *s;
    create_stack(&s);
    // printf("%d" , s->top);
    int id = 1 , pos = 1;
    printf("begin dfs\n");
    dfs(pos, id, n, s);
    printf("end dfs\n");
}

void work2_print_ans(int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return;
}