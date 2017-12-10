#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_LEN 1000

int main()
{
    char A[MAX_LEN+1];
    int B;

    //int Q[MAX_LEN+1],R=0;
    int Q,R=0;

    scanf("%s",A);
   // getchar();

    scanf("%d",&B);

    //puts(A);
    //printf("---- %d ----",B);

    int len=strlen(A);
    int i=0,j;

    if(1==len&&A[0]-'0'<B)
    {
        printf("0");
    }
    for(i=0;i<len;i++)
    {
        //Q[i]=(R*10 + (A[i]-'0'))/B;
        Q=(R*10 + (A[i]-'0'))/B;
        R=(R*10 + (A[i]-'0'))%B;
        if(0==i&&0==Q)
        //if(0==i&&0==Q[i])
        {
            //Ê×Î»Îª0
        }
        else
        {
            //printf("%d",Q[i]);
            printf("%d",Q);
        }
    }
    printf(" %d",R);

    return 0;
}
