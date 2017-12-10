#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void Totm(char * str,int time[]);
const int TIME_TODAY[3]={2014,9,6};
int CheckInput(int tm[]);
int Comp(int tm1[],int tm2[]);

int main()
{
   int num,ReasonalInput=0;;
   scanf("%d",&num);

    char Name[num][6],temp[11];
    int Birthday[num][3];
    int i=0,j;
    for(i=0;i<num;i++)
    {
        scanf("%s %s",Name[ReasonalInput],temp);
        Totm(temp,Birthday[ReasonalInput]);
        if(CheckInput(Birthday[ReasonalInput])==0)
        {
            // printf("%s %d/%d/%d\n",Name[ReasonalInput],Birthday[ReasonalInput][0],Birthday[ReasonalInput][1],Birthday[ReasonalInput][2]);
            ReasonalInput++;
        }
    }

//    for(i=0;i<ReasonalInput;i++)
//    {
//        printf("%s %d/%d/%d\n",Name[i],Birthday[i][0],Birthday[i][1],Birthday[i][2]);
//    }


    int maxAge=0,minAge=0;
    for(i=1;i<ReasonalInput;i++)
    {
        //j=Comp(Birthday[max],Birthday[i]);
        if(Comp(Birthday[maxAge],Birthday[i])==-1)
        {
            maxAge=i;
        }
        else if(Comp(Birthday[minAge],Birthday[i])==1)
        {
            minAge=i;
        }
    }
    if(ReasonalInput>0)
   {
       printf("%d %s %s",ReasonalInput,Name[maxAge],Name[minAge]);
   }
    else
    {
        printf("%d",0);
    }

    return 0;
}

void Totm(char str[],int time[])
{
    const char tokseps[]="/";//·Ö¸ô·û
    char * pt;
    int i=0;
    pt=strtok(str,tokseps);
    while(pt!=NULL)
    {

        time[i]=atoi(pt);
       // printf("%d",time[i]);
        pt=strtok(NULL,tokseps);
        i++;
    }
}

int CheckInput(int tm[])
{
    if((tm[0]>TIME_TODAY[0])
       ||(tm[0]==TIME_TODAY[0]&&tm[1]>TIME_TODAY[1])
       ||(tm[0]==TIME_TODAY[0]&&tm[1]==TIME_TODAY[1]&&tm[2]>TIME_TODAY[2]))

        return -1;//not born
    else if((tm[0]<TIME_TODAY[0]-200)
       ||(tm[0]==TIME_TODAY[0]-200&&tm[1]<TIME_TODAY[1])
       ||(tm[0]==TIME_TODAY[0]-200&&tm[1]==TIME_TODAY[1]&&tm[2]<TIME_TODAY[2]))
       return 1;//age over 200
    else
        return 0;
}

int Comp(int tm1[],int tm2[])
{
    if((tm1[0]>tm2[0])
       ||(tm1[0]==tm2[0]&&tm1[1]>tm2[1])
       ||(tm1[0]==tm2[0]&&tm1[1]==tm2[1]&&tm1[2]>tm2[2]))
       return -1;//tm1 < tm2
    else if((tm1[0]<tm2[0])
       ||(tm1[0]==tm2[0]&&tm1[1]<tm2[1])
       ||(tm1[0]==tm2[0]&&tm1[1]==tm2[1]&&tm1[2]<tm2[2]))
        return 1;//tm1 >tm2
    else
        return 0;
}
