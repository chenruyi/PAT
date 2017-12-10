#include <stdio.h>

const int Rate[2]= {17,29};


int ToFormat(int n,int *g,int *s,int *k);
int ToKnut(int g,int s,int k);


int main()

{
    int pg,ps,pk;
    int ag,as,ak;

    scanf("%d.%d.%d %d.%d.%d",&pg,&ps,&pk,&ag,&as,&ak);
    // printf()

    int n=ToKnut(ag,as,ak)-ToKnut(pg,ps,pk);
    if(n<0)
    {
        ToFormat(-n,&ag,&as,&ak);
        printf("-%d.%d.%d",ag,as,ak);
    }
    else
    {
        ToFormat(n,&ag,&as,&ak);
        printf("%d.%d.%d",ag,as,ak);
    }
    return 0;
}
int ToFormat(int n,int *g,int *s,int *k)
{
    *k=n%Rate[1];
    n=n/Rate[1];
    *s=n%Rate[0];
    *g=n/Rate[0];
    return 0;

}
int ToKnut(int g,int s,int k)
{
    //  printf("%d\n",k+s*Rate[1]+g*Rate[1]*Rate[0]);
    return k+s*Rate[1]+g*Rate[1]*Rate[0];
}
