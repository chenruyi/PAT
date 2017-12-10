#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int ka,kb;
    scanf("%d%*c",&ka);
    int a0[ka];
    float a1[ka];

    int i=0,j=0;
    for(i=0; i<ka; i++)
    {
        scanf("%d %f",&a0[i],&a1[i]);
    }

    scanf("%d%*c",&kb);
    int b0[kb];
    float b1[kb];
    for(i=0; i<kb; i++)
    {
        scanf("%d %f",&b0[i],&b1[i]);
    }

    int kc=ka+kb;
    int c0[kc];
    float c1[kc];
    kc=0;


    i=0;
    j=0;
    while(i<ka&&j<kb)
    {
        if(a0[i]<b0[j])
        {
            c0[kc]=b0[j];
            c1[kc]=b1[j];
            kc++;
            j++;
        }
        else if(a0[i]>b0[j])
        {
            c0[kc]=a0[i];
            c1[kc]=a1[i];
            kc++;
            i++;
        }
        else
        {
            c0[kc]=a0[i];
            c1[kc]=a1[i]+b1[j];
            kc++;
            i++;
            j++;
        }
    }
    while(i<ka)
    {
        c0[kc]=a0[i];
        c1[kc]=a1[i];
        kc++;
        i++;
    }
    while(j<kb)
    {
        c0[kc]=b0[j];
        c1[kc]=b1[j];
        kc++;
        j++;
    }
    j=0;
    for(i=0; i<kc; i++)
    {
        if(c1[i]!=0)
        {
            j++;
        }
    }

    printf("%d",j);

    for(i=0; i<kc; i++)
    {
        if(c1[i]!=0)

        printf(" %d %.1f",c0[i],c1[i]);
    }

    return 0;

}
