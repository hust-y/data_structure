#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "work.h"

#define MAX 1000

void work1(int n)
{
    stack* s = NULL;
    create_stack(&s);
    int ans[MAX];
    recurse_work(0, n, n, ans);
    int i = 0, j = 1;
}

void recurse_work(int nowpos, int zr, int one, int *ans)
{
    if (zr == 0 && one == 0) {
        for (int i = 0; i < nowpos; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        display(ans);
        return;
    }

    if (zr < one) {
        if (zr != 0) {
            ans[nowpos] = 0;
            recurse_work(nowpos + 1, zr - 1, one, ans);
        }
        if(one != 0) {
            ans[nowpos] = 1;
            recurse_work(nowpos + 1, zr, one - 1, ans);
        }
    }
    else {
        ans[nowpos ] = 0;
        recurse_work(nowpos + 1, zr - 1, one, ans);
    }
    return;
}

void display(int *ans)
{
    stack* s = NULL;
    create_stack(&s);
    int i = 0, j = 1;
    while(ans[i] == 0 || ans[i] == 1) {
        if(ans[i] == 0) {
            push(s, j);
            j++;
        }
        else if(ans[i] == 1) {
            if(s->top == 0) {
                printf("error: stack is empty\n");
                return;
            }
            int d = top(s);
            pop(s);
            printf("%d ", d);
        }
        i++;
    }
    printf("\n");
    return;
}