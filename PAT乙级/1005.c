#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
///bug
int main()
{
    const int N = 100;
    int k,i,j;
    int num[N],keyword[N];
    bool bKeyWord[N];

    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&num[i]);
        bKeyWord[i]=true;
    }

    for(i=0;i<k;i++)
    {
        if(!bKeyWord[i])
            continue;
        int iTemp=num[i];

        while(iTemp!=1)
        {
            if(iTemp%2)
            {
                  iTemp=iTemp*3+1;

                  for(j=0;j<k;j++)
                  {
                      if(iTemp==num[j])
                        bKeyWord[j]=false;
                  }
            }
            else
            {
                 iTemp/=2;

                 for(j=0;j<k;j++)
                  {
                      if(iTemp==num[j])
                        bKeyWord[j]=false;
                  }
            }
        }

    }

    int nKeyWordNum=0;
    for(i=0;i<k;i++)
    {
        if(!bKeyWord[i])
            continue;
        keyword[nKeyWordNum++]=num[i];
    }
    if(nKeyWordNum==0)
        return 0;

    for(i=0;i<nKeyWordNum;i++)
    {
        for(j=i+1;j<nKeyWordNum;j++)
        {
            if(keyword[i]<keyword[j])
            {
                keyword[i]=keyword[i]+keyword[j];
                keyword[j]=keyword[i]-keyword[j];
                keyword[i]=keyword[i]-keyword[j];
            }
        }

    }
    for(i=0;i<nKeyWordNum-1;i++)
    {
        printf("%d ",keyword[i]);
    }

    printf("%d",keyword[nKeyWordNum-1]);


    return 0;

}
