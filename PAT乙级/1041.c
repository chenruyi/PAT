#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
    char Tic[14];
    int Seat;
};

int main()
{
    struct Stu s[1000];
    char data[15];
    const char tokseps[]=" ";
    int n;
    scanf("%d%*c",&n);
    int i=0,j=0;
    int tem1,tem2;
    for(i=0; i<n; i++)
    {
        scanf("%s%*c%d %d",data,&tem1,&tem2);

        strcpy(s[tem1].Tic,data);
        s[tem1].Seat=tem2;
    }
    int k;
    scanf("%d",&k);
    int selectnum[k];
    for(i=0; i<k; i++)
    {
        scanf("%d%*c",&selectnum[i]);
    }
    for(i=0; i<k; i++)
    {
        printf("%s %d\n",s[selectnum[i]].Tic,s[selectnum[i]].Seat);

    }
    return 0;
}
