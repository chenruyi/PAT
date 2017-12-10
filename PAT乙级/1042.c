#include<stdio.h>

int main()
{
    char ch;
    int OccNum[26];
    int i=0;
    for(i=0;i<26;i++)
    {
        OccNum[i]=0;
    }

    while((ch=getchar())!='\n')
    {
        if(ch>='a'&&ch<='z')
        {
            OccNum[ch-'a']++;
        }
        else if(ch>='A'&&ch<='Z')
        {
            OccNum[ch-'A']++;
        }
    }

    int j=0;
    for(i=1;i<26;i++)
    {
        if(OccNum[i]>OccNum[j])
        {
            j=i;
        }
    }
    printf("%c %d",j+'a',OccNum[j]);

    return 0;
}
