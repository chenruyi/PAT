#include<stdio.h>

int main()
{
    int n;
    char ch;

    scanf("%d %c",&n,&ch);

    int i,j;
    for(i=0; i<n; i++)
    {
        putchar(ch);
    }
    putchar('\n');
    for(i=2; i<(n+1)/2; i++)
    {

        putchar(ch);
        for(j=1; j<n-1; j++)
        {
            putchar(' ');
        }
        putchar(ch);
        putchar('\n');
    }

    for(i=0; i<n; i++)
    {
        putchar(ch);
    }

    return 0;
}
