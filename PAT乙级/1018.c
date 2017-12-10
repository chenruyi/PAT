#include<stdio.h>

static int Result[3][3]=
{
    //  //  B    C    J
    /*B*/   0,   1,  -1,
    /*C*/  -1,   0,   1,
    /*J*/   1,  -1,   0
};

char Oper[3]={'B','C','J'};

int Oper2Int(char ch)
{
    int i;
    for(i=0;i<3;i++)
    {
        if(ch==Oper[i])
            break;
    }
    return i;
}

char Int2Oper(int i)
{
    return Oper[i];
}

int main()
{
    int N;
    char a,b;
    int aScore[3]= {0,0,0},bScore[3]= {0,0,0};
    //[0]:'B',win;[1]:'C',win;[2]:'J',win;


    int ia,ib;

    scanf("%d",&N);
    getchar();
    int i=0;
    for(i=0;i<N;i++)
    {
        scanf("%c %c",&a,&b);
        getchar();
        ia=Oper2Int(a);
        ib=Oper2Int(b);
        switch(Result[ia][ib])
        {
        case -1:
        {
            bScore[ib]++;
            break;
        }
        case  0:
        {
            break;
        }
        case  1:
        {
            aScore[ia]++;
            break;
        }
        }
    }

    int aWinTimes=aScore[0]+aScore[1]+aScore[2];
    int bWinTimes=bScore[0]+bScore[1]+bScore[2];
    int DrawTimes=N-aWinTimes-bWinTimes;
    printf("%d %d %d\n",aWinTimes,DrawTimes,bWinTimes);
    printf("%d %d %d\n",bWinTimes,DrawTimes,aWinTimes);

    int aMax=aScore[0],bMax=bScore[0];
    char aBestCh='B',bBestCh='B';
    for(i=1;i<3;i++)
    {
        if(aMax<aScore[i])
        {
            aBestCh=Int2Oper(i);
            aMax=aScore[i];
        }
        if(bMax<bScore[i])
        {
            bBestCh=Int2Oper(i);
            bMax=bScore[i];
        }
    }
    printf("%c ",aBestCh);
    printf("%c",bBestCh);


   // getchar();
   // getchar();
    return 0;
}
