#include <stdio.h>
//#include "work.h"
#include "func.h"

#define MAX 1000
int cattelan[MAX];

void set_cattelan(int n);
void display_ans(int n, int *ans, int nth_cattelan);
void get_ith_ans(int i, int n,  int *ans, int *temp);
void set_one(int i, int *ans);
void set_pre(int i, int *ans, int *temp);
void set_end(int i, int *ans, int *temp);

//void work4(int n)
int main(void)
{
    int n = 4; // Example value for n, you can change it as needed
    set_cattelan(n);

    int ans[cattelan[n] * n];
    int temp[cattelan[n] * n];
    //set_one(n, ans);
    display_ans(n, ans, cattelan[n]);
    printf("Cattelan numbers:\n");
    /*for(int i = 0; i <= n; i++)
    {
        printf("%d ", cattelan[i]);
    }
    printf("\n");*/
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
    set_one(i, ans);//Set the split one num in the ans array
    set_pre(i, ans, temp);//Set the pre num in the ans array
    set_end(i, ans, temp);//Set the end num in the ans array
    return;
}
void set_one(int i, int *ans)
{
    int now = 0;
    for(int j = 0; j <= i; j++)
    {
        for(int k = now; k - now < cattelan[j] * cattelan[i - j - 1]; k++)
        {
            ans[k * i + j] = 1;
        }
        now += cattelan[j] * cattelan[i - j - 1];
    }
    return;
}
void set_pre(int i, int *ans, int *temp)
{
    int now_for_ans = cattelan[i - 1];
    int now_for_temp = cattelan[i - 2];
    for(int j = 1; j < i - 1; j ++)
    {
        
    }
}
void set_end(int i, int *ans, int *temp)
{}