#include<stdlib.h>
#include<stdio.h>

int main()
{
    int IntArray[100];
    int IntNum,IntMoveSteps;
    int AuxiliarySpace;

    scanf("%d %d",&IntNum,&IntMoveSteps);

    if(IntNum>100||IntNum<1||IntMoveSteps<0)
        return 1;

    int i,j;
    for(i=0;i<IntNum;i++)
    {
        scanf("%d",&IntArray[i]);
    }

    for(i=1;i<=IntMoveSteps;i++)
    {
        AuxiliarySpace=IntArray[IntNum-1];
        for(j=IntNum-1;j>=1;j--)
        {
            IntArray[j]=IntArray[j-1];
        }
        IntArray[0]=AuxiliarySpace;
    }

    for(i=0;i<IntNum-1;i++)
    {
        printf("%d ",IntArray[i]);
    }
    printf("%d",IntArray[i]);

    return 0;

}
