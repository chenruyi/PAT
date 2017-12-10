#include<stdio.h>
#include<stdlib.h>

//辗转相除求最大公约数
long Euclidean(long a,long b)
{
    long r,c;

    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

//化为标准形式

long ToSimplest(long *a,long *b)
{
    long gcd,result;
    if(*a==0)
    {
        *a=0;
        *b=1;
        return 0;
    }
    else if(*a<0)
    {
        *a=-(*a);
        gcd= Euclidean(*a,*b);
        *a=-(*a)/gcd;
        *b=*b/gcd;

    }
    else if(*b<0)
    {
        *b=-(*b);
        gcd= Euclidean(*a,*b);
        *a=-(*a)/gcd;
        *b=(*b)/gcd;
    }
    else
    {
        gcd= Euclidean(*a,*b);
        *a=*a/gcd;
        *b=*b/gcd;
    }
    // int result;

    result=(*a)/(*b);
        if(result<0)
            *a=-(*a-(*b)*result);
        else
            *a=(*a-(*b)*result);
    return result;
}

void Print(long k,long a,long b)
{
    if(k>0)
    {
        if(a!=0)
        {
            printf("%ld %ld/%ld",k,a,b);
        }
        else
        {
            printf("%ld",k);
        }
    }

    else if(k<0)
    {
        if(a!=0)
        {
            printf("(%ld %ld/%ld)",k,a,b);
        }
        else
        {
            printf("(%ld)",k);
        }
    }
    else
    {
        if(a>0)
        {
            printf("%ld/%ld",a,b);
        }
        else if(a<0)
        {
            printf("(%ld/%ld)",a,b);
        }
        else
        {
            printf("0");
        }

    }

}


int main()
{
    int i=0;
    long a[6],b[6],k[6];
    const char ch[4]= {'+','-','*','/'};
    scanf("%ld/%ld %ld/%ld",&a[0],&b[0],&a[1],&b[1]);

    // printf("%d/%d %d/%d\n",a[0],b[0],a[1],b[1]);
    b[2]=b[3]=b[4]=b[0]*b[1];
    a[2]=a[0]*b[1]+a[1]*b[0];
    a[3]=a[0]*b[1]-a[1]*b[0];
    a[4]=a[0]*a[1];
    b[5]=a[1]*b[0];
    a[5]=a[0]*b[1];

    k[0]=ToSimplest(&a[0],&b[0]);
    k[1]=ToSimplest(&a[1],&b[1]);
    for(i=2; i<5; i++)
    {
        k[i]=ToSimplest(&a[i],&b[i]);
        Print(k[0],a[0],b[0]);
        printf(" %c ",ch[i-2]);
        Print(k[1],a[1],b[1]);
        printf(" = ");
        Print(k[i],a[i],b[i]);
        putchar('\n');
    }

    Print(k[0],a[0],b[0]);
    printf(" %c ",ch[3]);
    Print(k[1],a[1],b[1]);
    printf(" = ");

    if(b[5]!=0)
    {
        k[5]=ToSimplest(&a[5],&b[5]);
        Print(k[5],a[5],b[5]);
    }
    else
    {
        printf("Inf");
    }
    return 0;
}
