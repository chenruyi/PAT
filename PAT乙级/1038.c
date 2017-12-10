#include<stdio.h>

int main()
{
    int ScoreNum[101];
    int N;
    int i=0,j;

    for(i=0;i<102;i++)
    {
        ScoreNum[i]=0;
    }

    scanf("%d",&N);

    int tempScore;
    for(i=0;i<N;i++)
    {
        scanf("%d%*c",&tempScore);
        if(tempScore>=0&&tempScore<=100)
            ScoreNum[tempScore]++;
    }

    int k;
    scanf("%d",&k);

    int Num[k];

    for(i=0;i<k;i++)
    {
        scanf("%d%*c",&Num[i]);
    }

    for(i=0;i<k-1;i++)
    {
        printf("%d ",ScoreNum[Num[i]]);
    }

        printf("%d",ScoreNum[Num[i]]);

        return 0;


}
