#define MAX_NUM 2147483647

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool JudgePrime(int n)
{
    bool IsPrime=true;
    if(n==1)
        IsPrime=false;
    //else if(n==2)
    //    IsPrime=true;
    else
    {
        int i=1;
        for(i=2; i<=sqrt(n); i++)
        {
            if(n%i==0)
            {
                IsPrime=false;
                break;
            }
        }
    }
    return IsPrime;
}


int main()
{
    int PrimeNum=0;
    int PrimeArray[10000];
    int i=0;
    int M,N;
    scanf("%d %d",&M,&N);

    for(i=2; PrimeNum<N&&i<MAX_NUM; i++)
    {
        if(JudgePrime(i))
            PrimeArray[PrimeNum++]=i;
    }


    for(i=M; i<=N; i++)
    {

        if(0==((i-M+1)%10))
        {
            printf("%d\n",PrimeArray[i-1]);
        }
        else if(i==N)
        {
            printf("%d",PrimeArray[i-1]);
        }
        else
        {
            printf("%d ",PrimeArray[i-1]);
        }
    }




    return 0;
}
