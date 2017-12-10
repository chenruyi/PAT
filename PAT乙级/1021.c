#include<stdio.h>

int main()
{
    int num[10]={0,0,0,0,0,0,0,0,0,0};
    char n;
    int i;

    while((n=getchar())!='\n')
    {
        num[n-'0']++;
    }

    for(i=0;i<10;i++)
    {
        if(num[i]!=0)
        printf("%d:%d\n",i,num[i]);
    }
}
