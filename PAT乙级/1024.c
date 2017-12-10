#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char Instr[10001];
    char Pw[10000];
    gets(Instr);

    int len=strlen(Instr);
    int pE=0;

    while(Instr[pE]!='E')
    {
        pE++;
    }

    int i=0,j=0;
    for(i=pE+2; i<len; i++,j++)
    {
        Pw[j]=Instr[i];
    }
    Pw[j]='\0';

    int n=atoi(Pw);

    //printf("n=%d\n",n);

    //the num is minus;printf '-'
    if('-'==Instr[0])
    {
        printf("-");

    }

    //if exponent part is minus;
    if('-'==Instr[pE+1])
    {
        for(i=0;i<n;i++)
        {
           putchar('0');
            if(i==0)
            {
                putchar('.');
            }
        }
        for(i=1;i<pE;i++)
        {
            if(i!=2)
              putchar(Instr[i]);
        }

    }
    else
    {
        for(i=1;i<pE;i++)
        {
            if(i!=2)
              putchar(Instr[i]);
            if(i==(n+2)&&pE-3>n)
            {
                putchar('.');
            }

        }
         for(i=0;i<(n-pE+3);i++)
        {
           putchar('0');
            //if(i==0)
           // {
            //    putchar('.');
           // }
        }
    }


    return 0;
}
