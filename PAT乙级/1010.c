#include<stdlib.h>
#include<stdio.h>

int main()
{


    int Coefficient,Index,bZeroPoly=0;
    scanf("%d %d",&Coefficient,&Index);
    if(Index==0)
    {
        printf("0 0");
    }
    else
        printf("%d %d",Coefficient*Index,Index-1);
    while(getchar()!='\n')
    {
        scanf("%d %d",&Coefficient,&Index);
        if(Index!=0&&Coefficient!=0)
            printf(" %d %d",Coefficient*Index,Index-1);
        else
            break;
    }

    return 0;

}
