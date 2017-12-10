#include<stdio.h>

int main()
{
    char ch;
    int n[6]= {0,0,0,0,0,0};
    const char s[6]="PATest";
    while((ch=getchar())!='\n')
    {
        switch(ch)
        {
        case 'P':
        {
            n[0]++;
            break;
        }
        case 'A':
        {
            n[1]++;
            break;
        }
        case 'T':
        {
            n[2]++;
            break;
        }
        case 'e':
        {
            n[3]++;
            break;
        }
        case 's':
        {
            n[4]++;
            break;
        }
        case 't':
        {
            n[5]++;
            break;
        }
        }
    }
    int i,j;
    int len=0;
    for(i=0;i<6;i++)
    {
        //printf("%c %d\n",s[i],n[i]);
        len+=n[i];
    }

    for(i=0; i<len; i++)
    {
        for(j=0;j<6;j++)
        {
            if(n[j]>0)
            {
                printf("%c",s[j]);
                n[j]--;
            }
        }

    }

    return 0;
}
