#include<stdio.h>
#include "func.h"

int main()
{
    node *root = NULL;
    char *dictionary = "dictionary.txt";
    char *filename1 = "input.txt";
    char *filename2 = "output.txt";
    ini(&root , dictionary);
    enc(filename1 , filename2 , dictionary);
    dec(filename2 , "soijassdoiajisaioiaohiol.txt" , dictionary);
    return 0;
}