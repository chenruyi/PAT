#include<stdio.h>
void InsertSort(int array[],int n);
void Merge(int des[],int i,int m,int n);
void MergeSort(int des[],int s,int t);
int comp(const int a[],const int b[],const int n)
{
    int i=0;
    for(i=0; i<n; i++)
    {
        if(a[i]!=b[i])
            break;
    }

    return i==n?0:1;
}
int main()
{
    int i,j;
    int flag=-1;
    int N=10;
    scanf("%d",&N);
    int raw[200],raw1[200],inter[200];


    for(i=0; i<N; i++)
    {
        scanf("%d%*c",&raw[i]);
        raw1[i]=raw[i];
    }

    for(i=0; i<N; i++)
    {
        scanf("%d%*c",&inter[i]);
    }
    //InsertSort(raw,10);
    for(i=1; i<N; i++)
    {
        if(raw[i]<raw[i-1])
        {
            int temp=raw[i];
            for(j=i-1; j>=0&&temp<raw[j]; j--)
            {
                raw[j+1]=raw[j];
            }
            raw[j+1]=temp;
        }

        if(flag==0)
        {
            printf("Insertion Sort\n");
            for(i=0; i<N-1; i++)
            {
                printf("%d ",raw[i]);
            }
            printf("%d",raw[i]);
        }
        if(comp(raw,inter,N)==0)
        {
            flag=0;
        }
    }

    for(i=1; i<N&&flag!=0; i=i*2)
    {
        MergeSort(raw1,i,N-1);
        if(flag==1)
        {
            printf("Merge Sort\n");
            for(i=0; i<N-1; i++)
            {
                printf("%d ",raw1[i]);
            }
            printf("%d",raw1[i]);
        }
        if(comp(raw1,inter,N)==0)
        {
            flag=1;
        }


    }

    return 0;
}
void InsertSort(int array[],int n)
{
    int i=0,j;
    int temp=0;
    for(i=1; i<n; i++)
    {
        if(array[i]<array[i-1])
        {
            temp=array[i];
            for(j=i-1; j>=0&&temp<array[j]; j--)
            {
                array[j+1]=array[j];
            }
            array[j+1]=temp;
        }
    }
}
void MergeSort(int des[],int s,int t)
{
    int i;
    for(i=0; i+2*s-1<t; i=i+s*2)
    {
        Merge(des,i,i+s-1,i+s*2-1);
    }
    if(i+s-1<t)
        Merge(des,i,i+s-1,t);

}

void Merge(int des[],int i,int m,int n)
{
    int c[200];
    int j,k;
    int h=i;
    for(j=m+1,k=0; i<=m&&j<=n; k++)
    {
        if(des[i]<des[j])
        {
            c[k]=des[i++];
        }
        else
        {
            c[k]=des[j++];
        }
    }
    while(i<=m)
    {
        c[k++]=des[i++];
    }
    while(j<=n)
    {
        c[k++]=des[j++];
    }
    for(i=0; i<k; i++)
    {
        des[i+h]=c[i];
        //    printf("*%d*",des[i+h]);
    }
    // printf("%%");
}
