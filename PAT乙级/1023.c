#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10];
    int i=0;
    for(i=0; i<10; i++)
    {
        scanf("%d%*c",&a[i]);
    }


    for(i=1; i<10; i++)
    {
        if(a[i]!=0)
        {
            printf("%d",i);
            a[i]--;
            break;
        }
    }
    int j=a[0];
    while(j>0)
    {
        printf("%d",0);
        j--;
    }
    for(i=1; i<10; i++)
    {

        if(a[i]!=0)
        {
            int j=a[i];
            while(j>0)
            {
                printf("%d",i);
                j--;
            }
        }


    }
    return 0;


}
