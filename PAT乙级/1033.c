#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

///bug
int main()
{
    char Input[100000];
    char BrokenKey[100000];

    gets(BrokenKey);
    gets(Input);

    int len1=strlen(BrokenKey),len2=strlen(Input);

    int i;
    bool bNumber[10],
    bLetter[26],
    bOther[5];
    ///0:_  1:,
    ///2:.  3:-
    ///4:+
    bool IsPrint=false;
    for(i=0; i<10; i++)
    {
        bNumber[i]=true;
    }
    for(i=0; i<26; i++)
    {
        bLetter[i]=true;
    }
    for(i=0; i<5; i++)
    {
        bOther[i]=true;
    }
    for(i=0; i<len1; i++)
    {
        if(BrokenKey[i]>='0'&&BrokenKey[i]<='9')
        {
            bNumber[BrokenKey[i]-'0']=false;
        }
        else if(BrokenKey[i]>='A'&&BrokenKey[i]<='Z')
        {
            bLetter[BrokenKey[i]-'A']=false;
        }
        else
        {
            switch(BrokenKey[i])
            {
            case '_':
            {
                bOther[0]=false;
                break;
            }
            case ',':
            {
                bOther[1]=false;
                break;
            }
            case '.':
            {
                bOther[2]=false;
                break;
            }
            case '-':
            {
                bOther[3]=false;
                break;
            }
            case '+':
            {
                bOther[4]=false;
                break;
            }
            default:
            {
               // printf("ÊäÈë·Ç·¨");
            }
            }
        }


    }


    for(i=0; i<len2; i++)
    {
        //number
        if(Input[i]>='0'&&Input[i]<='9')
        {
            if(bNumber[Input[i]-'0'])
            {
                putchar(Input[i]);
                IsPrint=true;
            }
        }

        //down letter
        else if(Input[i]>='a'&&Input[i]<='z')
        {
            if(bLetter[Input[i]-'a'])
            {
                putchar(Input[i]);
                 IsPrint=true;
            }
        }

        //upper letters
        else if(Input[i]>='A'&&Input[i]<='Z')
        {
            if(bOther[4]&&bLetter[Input[i]-'A'])
            {
                putchar(Input[i]);
                 IsPrint=true;
            }
        }

        else if(Input[i]=='_'&&bOther[0])
        {
            putchar(Input[i]);
             IsPrint=true;
        }
        else if(Input[i]==','&&bOther[1])
        {
            putchar(Input[i]);
             IsPrint=true;
        }
        else if(Input[i]=='.'&&bOther[2])
        {
            putchar(Input[i]);
             IsPrint=true;
        }
        else if(Input[i]=='-'&&bOther[3])
        {
            putchar(Input[i]);
             IsPrint=true;
        }
    }
    if(!IsPrint)
    {
        printf("\n");
    }








    return 0;
}
