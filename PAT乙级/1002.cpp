#include<iostream>
int main()
{
    using namespace std;

    int sum=0,i=0;
    char n;
    string NumArray[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string ResultArray[3]={"","",""};
    while((n=cin.get())!='\n')
    {
        sum=sum+(n-'0');
    }

    while(sum>=10)
    {
        ResultArray[i++]=NumArray[sum%10];
        sum/=10;
    }
    ResultArray[i++]=NumArray[sum%10];
    while(i>0)
    {
        cout<<ResultArray[--i];
        if(i>=1)
            cout<<' ';
    }
    cout<<endl;

    return 0;
}
