#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

///bug
typedef struct
{
    int TicNum;//TicketNum;
    int QuaScore;//QualityScore;
    int AbiScore;//AbilityScore;
} Candidate;

bool Compare(Candidate can1,Candidate can2)
{
    //can1>can2 return fasle, can1<can2 return true;
    //
    int a1=can1.QuaScore,a2 =can1.AbiScore;
    int b1=can2.QuaScore,b2 =can2.AbiScore;
    if(
        (a1+a2<b1+b2)
        ||(a1+a2==b1+b2&&a1<b1)
        ||((a1+a2==b1+b2&&a1==b1)&&(can1.TicNum > can1.TicNum)))
    {
        return true;
    }
    return false;

}

int mycomp(const void * p1,const void * p2)
{
    const Candidate * can1=(const Candidate *) p1;
    const Candidate * can2=(const Candidate *) p2;
    int a1=can1->QuaScore,a2 =can1->AbiScore;
    int b1=can2->QuaScore,b2 =can2->AbiScore;

    if(
        (a1+a2<b1+b2)
        ||(a1+a2==b1+b2&&a1<b1)
        ||((a1+a2==b1+b2&&a1==b1)&&(can1->TicNum > can1->TicNum)))
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

int Partition(Candidate * array,int low,int high)
{
    // int low=0,high=LevelNum[i]-1;
    Candidate catemp=array[low];
    while(low<high)
    {
        while( low<high && !Compare(array[high],catemp))
            --high;
        array[low]=array[high];
        while(low<high && Compare(array[low],catemp))
            ++low;
        array[high]=array[low];
    }

    array[low]=catemp;
    return low;
}

void QSort(Candidate * array,int low,int high)
{
    if(low<high)
    {
        int pivotloc=Partition(array,low,high);
        QSort(array,low,pivotloc-1);
        QSort(array,pivotloc+1,high);
    }
}



int main()
{
    int NumCa,LowScore,HighScore;
    int LevelNum[4]= {0,0,0,0};
    //0: QuaScore >= HighScore and  AbiSocre >= HighScore;
    //1: QuaScore >= HighScore and  LowScore <= AbiScore <= HighScore;
    //2: LowScore <= QuaScore <= HighScore and  LowScore <= AbiScore <= HighScore and QuaScore >= AbiScore;
    //3: LowScore <= QuaScore <= HighScore and  LowScore <= AbiScore <= HighScore and QuaScore < AbiScore;

    int i=0,j,k;
//    FILE * fout=fopen("1015.txt","w");
//
//    fputs("\n==================\n",fout);

    scanf("%d %d %d",&NumCa,&LowScore,&HighScore);

    Candidate canArray[4][NumCa];
    Candidate InCan;
    for(i=0; i<NumCa; i++)
    {
//        {
//            InCan.AbiScore=rand()/(32767/41+1)+60;
//            InCan.QuaScore=rand()/(32767/41+1)+60;
//            InCan.TicNum=i+10000;
//
//            fprintf(fout,"%d\t\t%d\t\t%d\n",InCan.TicNum,InCan.QuaScore,InCan.AbiScore);
//        }

       scanf("%d %d %d",&(InCan.TicNum),&(InCan.QuaScore),&(InCan.AbiScore));
        if(InCan.QuaScore>=HighScore && InCan.AbiScore>=HighScore)
        {
            canArray[0][LevelNum[0]]=InCan;
            LevelNum[0]++;
        }
        else if(InCan.QuaScore>=HighScore && InCan.AbiScore>=LowScore)
        {
            canArray[1][LevelNum[1]]=InCan;
            LevelNum[1]++;
        }
        else if(InCan.QuaScore>=LowScore && InCan.AbiScore>=LowScore && InCan.QuaScore>=InCan.AbiScore)
        {
            canArray[2][LevelNum[2]]=InCan;

            LevelNum[2]++;

        }
        else if(InCan.QuaScore>=LowScore && InCan.AbiScore>=LowScore && InCan.QuaScore<InCan.AbiScore)
        {
            canArray[3][LevelNum[3]]=InCan;

            LevelNum[3]++;
        }

    }

//    fputs("\n**********\n",fout);
//    fclose(fout);

    printf("%d\n",LevelNum[0]+LevelNum[1]+LevelNum[2]+LevelNum[3]);

//
//    for(i=0; i<4; i++)
//    {
//        qsort(canArray[i],LevelNum[i],sizeof(Candidate),mycomp);
//
//        for(j=0; j<LevelNum[i]; j++)
//        {
//            printf("%d %d %d\n",canArray[i][j].TicNum,canArray[i][j].QuaScore,canArray[i][j].AbiScore);
//        }
//    }

    for(i=0; i<4; i++)
    {

        int low=0,high=LevelNum[i]-1;

        QSort(canArray[i],low,high);
        for(j=LevelNum[i]-1; j>=0; j--)
        {
            printf("%d %d %d\n",canArray[i][j].TicNum,canArray[i][j].QuaScore,canArray[i][j].AbiScore);
        }
    }


    return 0;
}
