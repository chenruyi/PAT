#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_LEN 80

int main()
{
    char ShouldInput[MAX_LEN+1];
    char InputStr[MAX_LEN+1];

    gets(ShouldInput);
    gets(InputStr);

    int i=0,j=0;
    int len1=strlen(InputStr),len2=strlen(ShouldInput);
    char BrokenKey[len2-len1];
    int BrokeNum=0;
    bool NotBroken[len2];
    for(i=0;i<len2;i++)
    {
        NotBroken[i]=false;
    }
    int p=0;
    for(i=0;i<len1;i++)
    {
        for(j=p;j<len2;j++)
        {
            if(ShouldInput[j]==InputStr[i])
            {
                NotBroken[j]=true;
                p=j+1;
                break;
            }
        }
    }

  //   BrokenKey[BrokeNum++]=ShouldInput[j];


    for(i=0;i<len2;i++)
    {
        if(!NotBroken[i])
        {
            if((ShouldInput[i]>='0'&&ShouldInput[i]<='9')
               ||(ShouldInput[i]>='A'&&ShouldInput[i]<='Z')
               ||(ShouldInput[i]=='_'))
            {
                bool flag=false;//标记是否已经存在
                for(j=0;j<BrokeNum;j++)
                {
                    if(BrokenKey[j]==ShouldInput[i])
                    {
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    BrokenKey[BrokeNum++]=ShouldInput[i];

            }
            else
            {
                bool flag=false;//标记是否已经存在
                for(j=0;j<BrokeNum;j++)
                {
                    if(BrokenKey[j]-'A'+'a'==ShouldInput[i])
                    {
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    BrokenKey[BrokeNum++]=(char)ShouldInput[i]-'a'+'A';
             }
        }
    }

    for(i=0;i<BrokeNum;i++)
    {
           //printf("%d->",i);
                printf("%c",BrokenKey[i]);

    }

    return 0;
}
