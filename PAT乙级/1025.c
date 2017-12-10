#include<stdio.h>
#include<stdlib.h>
#define N 100000
#undef NULL
#define NULL -1


void swp(int **a,int **b)
{
    int *temp=*a;
    *a=*b;
    *b=*temp;
}

int main()
{
    int head,M,K;

    FILE *infile=fopen("input.txt","r");

     scanf("%d%*c%d%*c%d%*c",&head,&M,&K);

    //fscanf(infile,"%d%*c%d%*c%d%*c",&head,&M,&K);
    // printf("%05d %d %05d\n",
    //                 head, M,K);


    int tab[N][2],p[M+1][2];
    int i,j,temp;


    for(i=0; i<M; i++)
    {
        //fscanf(infile,"%d",&temp);
        //fscanf(infile,"%d%*c%d",&tab[temp][0],&tab[temp][1]);
         scanf("%d",&temp);
           scanf("%d%*c%d",&tab[temp][0],&tab[temp][1]);

    }

    for(i=head,j=0; i!=NULL&&j<M; i=tab[i][1],j++)
    {
        p[j][0]=i;
        p[j][1]=tab[i][0];
    }
    p[j][0]=-1;

    for(i=0; i+K<=M; i+=K)
    {
        for(j=0; j<K/2; j++)
        {
           int a[2]={p[j+i][0],p[j+i][1]};
            p[j+i][0]=p[K-j+i-1][0];
            p[j+i][1]=p[K-j+i-1][1];
            p[K-j+i-1][0]=a[0];
            p[K-j+i-1][1]=a[1];

        }
    }


    for(i=0; i<M; i++)
    {
        printf("%05d %d %0*d\n",p[i][0],p[i][1],p[i+1][0]==-1?2:5,p[i+1][0]);
    }
   // printf("%05d %d %d\n",p[i][0],p[i][1],NULL);

//    for(i=0;i<M;i++)
//    {
//        printf("%05d %d %05d\n",p[i+1][1],p[i][0],p[i][1]);
//    }



    return 0;


}
