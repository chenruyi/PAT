#include<stdio.h>
#include<stdlib.h>

int intArray2Int(int array[],int start,int size)
{
    int i=0,n=0;
    for(i=0; i<size; i++)
    {
        int j=0,pw=1;
        while(j<i)
            pw=pw*10;
        n+=pw*array[start++];
    }
    return n;

}

void Int2Array(int n,int a[])
{
    int i=3;
    while(n/10!=0)
    {
        a[i--]=n%10;
        n=n/10;
    }
    a[i]=n;


}

int  LowInt(int n)
{
    int i=0,j;

    int a[4];
    Int2Array(n,a);

    for(i=0; i<4; i++)
    {
        for(j=i; j<4; j++)
        {
            if(a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }

    return intArray2Int(a,0,4);

}


int  HighInt(int n)
{
    int i=0,j=0;

    int a[4];
    Int2Array(n,a);

    for(i=0; i<4; i++)
    {
        for(j=i; j<4; j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }

    return intArray2Int(a,0,4);

}

int main()
{

    int a,b;
    int i=0,j,k;
    //for(i=0; i<4; i++)
   // {
        scanf("%d",&a);
  //  }

    //printf("%d",a);
    int array[4];
    Int2Array(a,array);

    //{
    //    printf("%d %d %d %d",array[0],array[1],array[2],array[3]);
   // }

    if(array[0]==array[1]&&array[1]==array[2]&&array[2]==array[3])
    {

        printf("N - N = 0000\n");

    }

    else
    {
        while( a!=6174)
        {

            a=LowInt(a);
            b=HighInt(a);

            printf("%d - %d = %d\n",a,b,a-b);

            a=a-b;

        }
    }


    return 0;
}
