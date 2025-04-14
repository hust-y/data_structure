#include "func.h"

void enc(const char *filename1, char *filename2 , char *dictionary)
{
    char dict[256][10];
    freopen(dictionary, "r", stdin);
    int n;
    scanf("%d" , &n);
    
    // printf("%d\n" , n);
    for( int i = 0 ; i < n ; i++ )
    {
        char c , code[10];
        scanf("%s" , &c);
        scanf("%s" , dict[c]);
    }
    fclose(stdin);
    freopen(filename1 , "r" , stdin);
    // printf("%s\n" , dict['a']);
    char text[100000];
    scanf("%s" , text);
    freopen(filename2 , "w" , stdout);
    for( int i = 0 ; text[i] ; i++ )
    {
        printf("%s" , dict[text[i]]);
    }
    fclose(stdout);
    return ;
}