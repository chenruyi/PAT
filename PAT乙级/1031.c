#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int main()
{
    const char M[11]= {'1','0','X','9','8','7','6','5','4','3','2'};
    const int w[17]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int N;
    int i,j;
    scanf("%d",&N);
    getchar();

    char Input[N][19];
    // bool IsPassed[N];

    for(i=0; i<N; i++)
    {
        gets(Input[i]);
    }

    bool AllPassed=true;
    for(i=0; i<N; i++)
    {
        int sum=0;
        for(j=0; j<17; j++)
        {
            if(Input[i][j]<'0' || Input[i][j]>'9')
            {
                break;
            }
            sum+=(Input[i][j]-'0')*w[j];
        }
        if(j<17||M[sum%11]!=Input[i][17])
        {
            puts(Input[i]);
            AllPassed=false;
        }
    }
    if(AllPassed)
        printf("All passed");

    return 0;

}
