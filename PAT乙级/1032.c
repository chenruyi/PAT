#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N;

    scanf("%d",&N);
    getchar();

    int i,j;
    int a[N];
    for(i=1;i<=N;i++)
    {
        a[i]=0;
    }

    int temp1,temp2;

    for(i=0;i<N;i++)
    {
        scanf("%d %d%*c",&temp1,&temp2);
        a[temp1]+=temp2;
    }

    j=1;
    for(i=1;i<=N;i++)
    {
        if(a[i]>a[j])
        {
            j=i;
        }
    }
    printf("%d %d",j,a[j]);




    return 0;
}
