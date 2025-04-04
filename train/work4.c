#include <stdio.h>
//#include "work.h"
#include "func.h"
#include "work.h"

void work4(int n)
{
    int n = 3; // Example value for n, you can change it as needed
    set_cattelan(n);

    int ans[cattelan[n] * n];
    int temp[cattelan[n] * n];
    get_ith_ans(n, n, ans, temp);
    display_ans(n, ans, cattelan[n]);
    return 0;
}

void set_cattelan(int n)
{
    cattelan[0] = 1;
    cattelan[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        cattelan[i] = cattelan[i - 1] * 2 * (2 * i - 1) / (i + 1);
    }
    return;
}
void display_ans(int n, int *ans, int nth_cattelan)
{
    printf("The %d training plan is:\n", n);
    for(int i = 0; i < nth_cattelan; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", ans[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
void get_ith_ans(int i, int n,  int *ans, int *temp)
{
    if (i == 1)
    {
        ans[0] = 1;
        return;
    }
    get_ith_ans(i - 1, n, temp, ans);
    printf("i = %d\n", i);
    set_one(i, ans, n);//Set the split one num in the ans array
    set_pre(i, ans, temp, n);//Set the pre num in the ans array
    set_end(i, ans, temp, n);//Set the end num in the ans array
    return;
}
void set_one(int i, int *ans, int n)
{
    int now = 0;
    for(int j = 0; j <= i; j++)
    {
        for(int k = now; k - now < cattelan[j] * cattelan[i - j - 1]; k++)
        {
            ans[k * n + j] = 1;
        }
        now += cattelan[j] * cattelan[i - j - 1];
    }
    return;
}
void set_pre(int i, int *ans, int *temp, int n)
{
    int now_for_ans = cattelan[i - 1];
    int now_for_temp = cattelan[i - 2];
    for(int j = 1; j < i - 1; j ++)//set value to i - 1 and the last, which is i, is seted alone
    {
        for(int k = 0; k < cattelan[j]; k ++)
        {
            for(int l = 0; l < cattelan[i - j - 1]; l++)
            {
                copy_add_array(ans + (now_for_ans + k * cattelan[i - j - 1] + l) * n, temp + (now_for_temp + k * cattelan[i - j - 2]) * n, j, 0);
            }
        }
        now_for_ans += cattelan[j] * cattelan[i - j - 1];
        now_for_temp += cattelan[j] * cattelan[i - j - 2]; 
    }
    for(int k = 0; k < cattelan[i - 1]; k ++)
    {
        copy_add_array(ans + (now_for_ans + k) * n, temp + k * n, i - 1, 1);
    }
    return;
}
void set_end(int i, int *ans, int *temp, int n)
{
    int now_for_ans = 0;
    int now_for_temp = 0;
    for(int j = 0; j < cattelan[i - 1]; j ++)
    {
        copy_add_array(ans + j * n + 1, temp + j * n, i - 1, 1);//Set the first block in the ans array. 
    }
    for(int j = 1; j < i - 1; j ++)//Set value from the second block of the array, and leave the last alone, which doesn't need to be set.
    {
        for(int k = 0; k < cattelan[i - j - 2]; k ++)
        {
            for(int l = 0; l < cattelan[j]; l++)
            {
                copy_add_array(ans + (now_for_ans + l * cattelan[i - j - 1] + k) * n + j + 1, \
                temp + (now_for_temp + k) * cattelan[i - j - 2] + j, i - 1 - j, 1);
            }
        }
        now_for_ans += cattelan[j] * cattelan[i - j - 1] ;
        now_for_temp += cattelan[j] * cattelan[i - j - 2];
    }
    return;
}

//My array functions
void copy_add_array(int *a, int *b, int n, int m)
{
    printf("%d ", n);
    printf("add num %d to array:", m);
    printf("copy_add_array:");
    print_oneline(b, n);
    for(int i = 0 ; i < n ; i++ )
    {
        a[i] = b[i] + m;
    }
    return;
}

void print_oneline(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}