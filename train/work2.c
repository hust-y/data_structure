#include <stdio.h>
#include "work.h"
#include <stdlib.h>

int ans[100];

void work2_dfs(int pos , int id , int n , stack *s)
{
    // printf("dfs(%d, %d, %d, %d)\n", pos, id, n, s->top);
    // system("pause");
    if(pos == n+1)
    {
        work2_print_ans(n);
        print_operation(2 * n);
        return;
    }
    if(s->top)
    {
        int x = top(s);
        pop(s);
        add_op(1,x);
        ans[pos] = x;
        work2_dfs(pos+1 , id , n , s);
        push(s, x);
        delete_op();
    }
    if(id <= n )
    {
        push(s , id);
        add_op(0,id);
        ans[pos] = id;
        work2_dfs(pos , id+1 , n , s);
        pop(s);
        delete_op();
    }
    
}

void work2( int n) 
{
    stack *s;
    create_stack(&s);
    // printf("%d" , s->top);
    int id = 1 , pos = 1;
    // printf("begin dfs\n");
    work2_dfs(pos, id, n, s);
    // printf("end dfs\n");
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