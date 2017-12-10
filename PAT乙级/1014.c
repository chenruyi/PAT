#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 60

int main()
{
    char InStr[4][MAX_LENGTH+1];
    char DAY[7][4]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int day,hour,minute;
    int i=0,j,k;
    int StrLength[4];

    for(i=0; i<4; i++)
    {
        scanf("%s",InStr[i]);
        StrLength[i]=strlen(InStr[i]);
    }


    int length=StrLength[0]<StrLength[1] ? StrLength[0] :StrLength[1];
    for(i=0; i<=length; i++)
    {
        if(InStr[0][i]>='A' && InStr[0][i]<='G')
        {
            if(InStr[0][i]==InStr[1][i])
            {
                day=InStr[0][i]-'A'+1;
                break;
            }
        }
    }
    i++;
    for(; i<=length; i++)
    {
        if(InStr[0][i]>='0' && InStr[0][i]<='9')
        {
            if(InStr[0][i]==InStr[1][i])
            {
                hour=InStr[0][i]-'0';
                break;
            }
        }
        else if(InStr[0][i]>='A' && InStr[0][i]<='N')
        {
            if(InStr[0][i]==InStr[1][i])
            {
                hour=InStr[0][i]-'A'+10;
                break;
            }
        }
    }

    for(i=0; i<=StrLength[2]; i++)
    {
        if(((InStr[2][i]>='a' && InStr[2][i]<='z')
                || (InStr[2][i]>='A' && InStr[2][i]<='Z'))
            &&(InStr[2][i]==InStr[3][i]))
        {
                    minute=i;

                    break;
        }
    }


    printf("%s %02d:%02d",DAY[day-1],hour,minute);

    return 0;
}
