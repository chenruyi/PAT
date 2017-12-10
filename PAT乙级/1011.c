#include <stdio.h>
int main()
{
    int n=0;
    long a[10],b[10],c[10];
    //printf("%d",sizeof(long));

    scanf("%d",&n);

    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld %ld",&a[i],&b[i],&c[i]);
    }

    for(i=0;i<n;i++)
    {

        if(a[i]+b[i]>c[i])
            printf("Case #%d: %s\n",i+1,"true");
        else
            printf("Case #%d: %s\n",i+1,"false");
    }



}
