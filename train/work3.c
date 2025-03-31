#include <stdio.h>
#include "work.h"
#include <stdlib.h>

void work3(int n)
{
    int i;
    destack *s;
    create_destack(&s, n);
    work3_dfs(1, 1, n, s);
}

void work3_dfs(int pos , int id , int n , destack *s)
{
    // printf("dfs(%d, %d, %d, %d)\n", pos, id, n, s->top);
    // system("pause");
    if(pos == n+1)
    {
        printans(s);
        print_operation(2 * n);
        return;
    }
    if(s->top1)
    {
        int x = topleft(s);
        popleft(s);
        add_op(1,x);
        pushright(s, x);
        work3_dfs(pos+1 , id , n , s);
        pushleft(s, x);
        popright(s);
        delete_op();
    }
    if(id <= n )
    {
        pushleft(s , id);
        add_op(0,id);
        work3_dfs(pos , id+1 , n , s);
        popleft(s);
        delete_op();
    }
}