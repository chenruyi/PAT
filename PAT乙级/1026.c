#include<stdio.h>
#include<time.h>
#include<string.h>
#undef CLK_TCK
#define CLK_TCK 100


int main()
{
    long C1=123,C2=4577973;
   scanf("%d %d",&C1,&C2);

    long m=(C2-C1+50)/CLK_TCK;


    //for(i=1; i<=100000; i++)
    {

        time_t m_time= m;



//        char tmpBuf[512];
//        strftime(tmpBuf,512,"%H:%M:%S",gmtime(&m_time));
//        printf("%s\t",tmpBuf);
//

        int hour,minute,second;
        second=m%60;
        m/=60;
        minute=m%60;
        hour=m/60;

        printf("%02d:%02d:%02d\n",hour,minute,second);

        //strcmp()
    }
    return 0;
}
