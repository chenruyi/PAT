#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
    int N;
    int num[1000];
    int i,j;
    int A[6];
    bool B[6]={false};
    scanf("%d",&N);

    for(i=0; i<N; i++ )
    {
        scanf("%d",&num[i]);
    }

    A[1]=0;
    A[2]=0;
    char kind='+';
    A[3]=0;
    int A4Sum=0,A4Num=0;
    A[5]=0;
    for(i=0; i<N; i++)
    {

        switch(num[i]%5)
        {
        case 0:
        {

            if(num[i]%2==0)
            {
                B[1]=true;
                A[1]+=num[i];
            }
            break;
        }
        case 1:
        {
            B[2]=true;
            if('+'==kind)
            {
                A[2]+=num[i];
                kind='-';
            }
            else
            {
                A[2]-=num[i];
                kind='+';
            }
            break;
        }
        case 2:
        {
            B[3]=true;;
            A[3]++;
            break;
        }
        case 3:
        {
            B[4]=true;
            A4Sum+=num[i];
            A4Num++;
            break;
        }
        case 4:
        {
            B[5]=true;
            A[5]=A[5]>num[i]?A[5]:num[i];
            break;
        }
        }

    }
    for(i=1;i<=3;i++)
    {
        if(B[i])
        {
           printf("%d ",A[i]);
        }
        else
        {
            printf("N ");
        }
    }
    if(B[4])
    {
        printf("%.1f ",1.0*A4Sum/A4Num);
    }
    else
    {
        printf("N ");
    }
    if(B[5])
    {
        printf("%d",A[5]);
    }
    else
    {
        printf("N");
    }


return 0;

}
