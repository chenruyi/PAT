#include<stdlib.h>
#include<stdio.h>
struct Student
{
    char cName[11];
    char cNumber[11];
    int nScore;

};

int main()
{
    int n;
    struct Student temp,min,max;

    scanf("%d",&n);

    // n--;
    // scanf("%s %s %d",temp.cName,temp.cNumber,& temp.nScore);
    // min=max=temp;

    min.nScore=101;
    max.nScore=-1;
    while(n--)
    {
        scanf("%s %s %d",temp.cName,temp.cNumber,& temp.nScore);
        if(temp.nScore<min.nScore)
            min=temp;
        if(temp.nScore>max.nScore)
            max=temp;
    }
    printf("%s %s\n",max.cName,max.cNumber);
    printf("%s %s\n",min.cName,min.cNumber);

    return 0;
}
