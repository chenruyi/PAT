#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,num=0;
    scanf("%d",&n);
    while(n!=1)
    {
        if(n%2)
        {
            n=(3*n+1)/2;
            num++;
        }
        else
        {
            n/=2;
            num++;
        }
    }
    printf("%d",num);
    return 0;
}
