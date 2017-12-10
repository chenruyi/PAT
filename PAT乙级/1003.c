#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 10000


char inStr[N];
int len;

//only 'A' or 'A...A'
///begin/ end: start form 0
bool CheckA(int begin,int end)
{
    int i=begin;
    for(; i<end; i++)
        if('A'!=inStr[i])
            return false;
    return true;
}


//only 'P' or 'A' or 'T'
bool CheckEvery()
{
    int i=0;
    for(; i<len; i++)
    {
        if('P' !=inStr[i] && 'A' !=inStr[i] && 'T' !=inStr[i])
            return false;
    }
    return true;
}

bool Check()
{
    int i,posP,posT;

    //get 'P' 'T' position
    for(i=0; i<len; i++)
    {
        if('P'==inStr[i])
            posP=i;
        if('T'==inStr[i])
            posT=i;
    }
    if(CheckA(0,posP)&&CheckA(posP+1,posT)&&CheckA(posT+1,len)&&posT-posP>1 && (posT-posP-1)*posP==len-posT-1)
        return true;
    return false;
}

int main()
{
    int nCase;
    scanf("%d",&nCase);
    while(nCase--)
    {
        scanf("%s",inStr);
        len=strlen(inStr);
        printf("%s\n",(CheckEvery()&&Check())?"YES":"NO");

    }
    return 0;

}
