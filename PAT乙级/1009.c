#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//bug
int main()
{
    char Instr[81];
    int i,j,BlankSpaceNum=0,InstrLen=0;

    gets(Instr);

    InstrLen=strlen(Instr);
    printf("\n%d\n",InstrLen);
    if(InstrLen>80)
       {
           exit(0);
       }
    int *BlankSpace=(int *)malloc(InstrLen*sizeof(int));
    BlankSpace[BlankSpaceNum++]=0;
    for(i=0;i<=InstrLen;i++)
    {
        if(' '==Instr[i])
        {
            BlankSpace[BlankSpaceNum++]=i+1;
        }
    }
    BlankSpace[BlankSpaceNum++]=InstrLen+1;

    for(i=BlankSpaceNum-1;i>=1;i--)
    {
        for(j=BlankSpace[i-1];j<BlankSpace[i];j++)
            {
                printf("%c",Instr[j]);
            }
    }

    printf("\n");
    return 0;
}
