#include<stdio.h>
#include<string.h>

int main()
{
     unsigned long A,B;
     int Radix;
     scanf("%ld%*c%ld%*c%d",&A,&B,&Radix);

    //printf("%ld %ld %d",A,B,Radix);
    unsigned long c=A+B;

    if(c==0)
        printf("0");

    int i,n=0,Q,R;
    int s[30];

    while(c!=0)
    {
        R=c%Radix;
        c=c/Radix;

        s[n++]=R;
    }


    for(i=n-1;i>=0;i--)
    {
        printf("%d",s[i]);
    }


    return 0;
}
