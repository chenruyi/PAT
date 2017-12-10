#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool JudgePrime(int num);
//judge  is prime or not



int main()
{
    int N,m,n,i,j;
    int TwinPrimeNum=0;
    m=2,n=3;

    scanf("%d",&N);


    for(i=4; i<=N; i++)
    {

        if(JudgePrime(i))
        {
            m=n;
            n=i;
            if(n-m==2)
            {

            TwinPrimeNum++;
            }

        }
    }

    printf("%d",TwinPrimeNum);
    return 0;
}

bool JudgePrime(int num)
{
    bool bIsPrime=true;

    int End=sqrt(num);
    int i=0;
    for(i=2; i<=End; i++)
    {
        if(num%i==0)
        {
            bIsPrime=false;
            break;
        }
    }

    return bIsPrime;
}
