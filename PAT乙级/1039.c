#include<stdio.h>

int ToInt(char ch);

int main()
{
    const int ColorKind=62;
    char L1[ColorKind],L2[ColorKind],L3[ColorKind];
    int len1=0,len2=0;
    int flag=0;//
    int i;
    for(i=0;i<ColorKind;i++)
    {
        L1[i]=0;
        L2[i]=0;
        L3[i]=0;
    }
    char ch;
    while((ch=getchar())!='\n')
    {
       // printf("%c ",ch);
        L1[ToInt(ch)]++;
        len1++;
    }


    while((ch=getchar())!='\n')
    {
       // printf("%c ",ch);
       L2[ToInt(ch)]++;
        len2++;
    }

    for(i=0;i<ColorKind;i++)
    {
        if(L2[i]!=0)
        {
           //  printf(" %d->%d \n",i,L1[i]);
            //  printf(" %d->%d \n",i,L2[i]);
            L3[i]=L1[i]-L2[i];
            if(L3[i]<0)
            {
                flag=-1;
            }
        }
    }

    if(flag==-1)
    {
        int sum=0;
        for(i=0;i<ColorKind;i++)
        {
            if(L3[i]<0)
                sum+=L3[i];
        }
        printf("%s %d","No",-sum);
    }
    else
    {
        printf("%s %d","Yes",len1-len2);
    }




    return 0;
}


int ToInt(char ch)
{
    int result=0;
    if(ch>='0'&&ch<='9')
    {
        result=ch-'0';
    }
    else if(ch>='a'&&ch<='z')
    {
        result=ch-'a'+'9'-'0'+1;
    }
    else
    {
        result=ch-'A'+'z'-'a'+1+'9'-'0'+1;
    }
    return result;

}
