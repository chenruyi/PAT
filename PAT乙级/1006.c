#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void IntegerInput();
void StringInput();
//void FunctionC();


int main()
{
    IntegerInput();
   // StringInput();


    return 0;

}
void IntegerInput()
{//input as integer

    int Num[3];

    int n;
    scanf("%d",&n);


    int i=0,j;
    while(n>=10)
    {
        Num[i++]=n%10;
      //  printf("%d ",Num[i-1]);
        n/=10;
    }
    Num[i++]=n;
     //   printf("%d",Num[i-1]);
    switch(i)
    {
    case 3:
        for(j=1;j<=Num[2];j++)
            {
                printf("%c",'B');
            }

    case 2:
        for(j=1;j<=Num[1];j++)
            {
                printf("%c",'S');
            }

    case 1:
        for(j=1;j<=Num[0];j++)
            {
                printf("%d",j);
            }
         break;
    default:
         printf("ERROR!!Illegal Input!");

    }


}

void StringInput()
{//input as string
      char *n=(char *)malloc(sizeof(char)*4);
    int Length=0;
    int j;

    gets(n);

    Length=strlen(n);
    switch(Length)
    {
    case 3:
        for(j=1;j<=n[0]-'0';j++)
            {
                printf("%c",'B');
            }
        for(j=1;j<=n[1]-'0';j++)
            {
                printf("%c",'S');
            }
        for(j=1;j<=n[2]-'0';j++)
            {
                printf("%d",j);
            }
        break;

    case 2:
         for(j=1;j<=n[0]-'0';j++)
            {
                printf("%c",'S');
            }
        for(j=1;j<=n[1]-'0';j++)
            {
                printf("%d",j);
            }
        break;

    case 1:
        for(j=1;j<=n[0]-'0';j++)
            {
                printf("%d",j);
            }
        break;
    default:
         printf("ERROR!!Illegal Input!");

    }

}

