#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a,b;
    int i=0,j;

    scanf("%d %d",&a,&b);

    a=a+b;
    b=abs(a);

    char str[9];

    str[i++]=(b%10)+'0';
    b=b/10;
    while(b!=0)
    {
       // printf("%c ",str[i-1]);
        str[i++]=(b%10)+'0';
        b=b/10;
    }
    if(a<0)
       putchar('-');

    for(j=i-1; j>=0; j--)
        {
            putchar(str[j]);
            if(j%3==0&&j!=0)
            {
                putchar(',');
            }
        }

    return 0;

}
