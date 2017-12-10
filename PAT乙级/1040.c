#include<stdio.h>
int main()
{
    char s[100000];
    int n=0;
    char ch;
    while ((ch=getchar())!='\n')
    {
        s[n++]=ch;
    }

    int i=0,j,k,result=0;
    int nAT=0,nT=0;

    for(i=n-1;i>=0;i--)
    {
        if(s[i]=='T')
        {
            nT++;
        }
        else if(s[i]=='A')
        {
            nAT=(nAT+nT)%1000000007;
        }
        else if(s[i]=='P')
        {
            result=(result+nAT)%1000000007;
        }
    }

    printf("%d",result);


    return 0;
}

