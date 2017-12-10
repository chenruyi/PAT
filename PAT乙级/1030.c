#include<stdio.h>
#include<stdlib.h>
int mycomp(const void *a,const void *b)
{
    const long *x=(long *)a;
    const long *y=(long *)b;
    if(*x>*y)
        return 1;
    else if(*x==*y)
        return 0;
    else
        return -1;
}

int main()
{
    int N,i,j,result=0;
    long p;

    scanf("%d %ld",&N,&p);

    long Num[N];
    for(i=0;i<N;i++)
    {
        scanf("%ld%*c",&Num[i]);
    }

    qsort(Num,N,sizeof(long),mycomp);

//    for(i=0;i<N;i++)
//    {
//        printf("%d ",Num[i]);
//    }

    result=1;
    for(i=0;i<N;i++)
    {
        for(j=result;i+j-1<N;j++)
        {
            if(Num[i]*p>=Num[i+j-1])
                result=j;
            else
                break;
        }
    }
    printf("%d",result);



    return 0;
}
