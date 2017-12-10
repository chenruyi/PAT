#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_LENGTH 10

int main()
{
    char A[MAX_LENGTH],B[MAX_LENGTH];
    char a,b;

    scanf("%s",A);
    getchar();
    scanf("%c",&a);
    getchar();
    scanf("%s",B);
    getchar();
    scanf("%c",&b);

    int i,j,lena=0,lenb=0;
    int Pa=0,Pb=0;
    for(i=0; i<=strlen(A); i++)
    {
        if(A[i]==a)
        {
            int temp=0,pw=1;;
            while(temp<lena)
            {
                pw*=10;
                temp++;;
            }
            Pa+=(a-'0')*pw;
            lena++;
        }
    }
    for(i=0;i<=strlen(B);i++)
    {
        if(B[i]==b)
        {
            int temp=0,pw=1;;
            while(temp<lenb)
            {
                pw*=10;
                temp++;
            }
            Pb+=(b-'0')*pw;
           // printf("----- %d ----\n",Pb);
            lenb++;
        }
    }

    printf("%d",Pa+Pb);
    return 0;
}
