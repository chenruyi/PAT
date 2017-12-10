#include <stdio.h>

int main()
{
    int n;
    char ch='*';

    scanf("%d %c",&n,&ch);
 //   for(n=1; n<50; n++)
    {
        int i,j,row,chnum;

        for(i=1; i<=n; i++)
        {
            if(2*(i+1)*(i+1)-1>n)
            {
                row=2*i-1;
                chnum=2*i*i-1;
                break;
            }
        }

        for(i=1; i<=row/2; i++)
        {
            for(j=1; j<=i-1; j++)
            {
                putchar(' ');
            }
            for(j=1; j<=row-2*i+2; j++)
            {
                putchar(ch);
            }
//        for(j;j<=row-i;j++)
//        {
//            putchar(' ');
//        }
            putchar('\n');

        }
        for(i=row/2+1; i<=row; i++)
        {
            for(j=1; j<=row-i; j++)
            {
                putchar(' ');
            }
            for(j=1; j<=2*i-row; j++)
            {
                putchar(ch);
            }
//        for(j;j<=row-i;j++)
//        {
//            putchar(' ');
//        }
            putchar('\n');

        }
     //   if(n>chnum)
        {
            printf("%d",n-chnum);
        }

    }
    return 0;
}
