#include<stdio.h>
#include<stdlib.h>

inline float GetUnitPrice(float a,float b)
{
    if(b==0)
        return 0;
    return a*1.0/b;
}

int PartionQSort(float * Inventory,float * AllSalePrice,int low,int high)
{
    int pria=Inventory[low],prib=AllSalePrice[low];
    float prikey= GetUnitPrice(AllSalePrice[low],Inventory[low]);
    while(low<high)
    {
        while(low<high&&GetUnitPrice(AllSalePrice[high],Inventory[high])<=prikey)
            --high;
        {
            Inventory[low]=Inventory[high];
            AllSalePrice[low]=AllSalePrice[high];
        }
        while(low<high&&GetUnitPrice(AllSalePrice[low],Inventory[low])>=prikey)
            ++low;
        {
            Inventory[high]=Inventory[low];
            AllSalePrice[high]=AllSalePrice[low];
        }
    }
    {
        Inventory[low]=pria;
        AllSalePrice[low]=prib;
    }
    return low;
}

void QSort(float * Inventory,float * AllSalePrice,int low,int high)
{
    if(low<high)
    {
        int prikey=PartionQSort(Inventory,AllSalePrice,low,high);
        QSort(Inventory,AllSalePrice,low,prikey-1);
        QSort(Inventory,AllSalePrice,prikey+1,high);
    }
}

int main()
{
    int nKind,nAllNeed;

    scanf("%d %d",&nKind,&nAllNeed);

    if(nKind<=0)
        exit(0);
    else
    {
        float Inventory[nKind];
        float AllSalePrice[nKind];
        //int UnitPrice[nKind];

        int i=0;
        for(i=0; i<nKind; i++)
        {
            scanf("%f",&Inventory[i]);
            getchar();
        }

        for(i=0; i<nKind; i++)
        {
            scanf("%f",&AllSalePrice[i]);
            getchar();
        }


        QSort(Inventory,AllSalePrice,0,nKind-1);

      //  for(i=0; i<nKind; i++)
      //  {
      //      printf("%f\n",AllSalePrice[i]);
            //getchar();
      //  }

        int sum=0;
        float allProfit=0.0;
        i=0;

        while((sum<nAllNeed)&&(i<nKind))
        {
            sum+=Inventory[i];
            allProfit+=AllSalePrice[i];
            i++;
        }

        sum-=Inventory[i-1];
        allProfit-=AllSalePrice[i-1];

        allProfit+=(nAllNeed-sum)*GetUnitPrice(AllSalePrice[i-1],Inventory[i-1]);


        if(nAllNeed==0)
            allProfit=0.0;
        printf("%.2f",allProfit);

        // getchar();
        // getchar();

    }
    return 0;


}
