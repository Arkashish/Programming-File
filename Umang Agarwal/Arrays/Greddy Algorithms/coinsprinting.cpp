
#include<bits/stdc++.h>
using namespace std;
#define MAX 20
#define n 10
int coins[n] = {1,2,5,10,20,50,100,200,500,2000};
void printer(int cost){
    int cointlist[MAX] = {0};
    int i,k=0;

    cout<<"Available coins are: ";
    for (int i = 0; i < n; i++)
    {
        cout<<coins[i]<<" ";
    }

    for(int i=n-1;i>=0;i--)
    {
        while (cost>=coins[i])
        {
            cost-=coins[i];
            cointlist[k++]=coins[i];
        }        
    }
    
    cout<<endl;
    cout<<"Total Number of notes and coins used are: "<< k <<endl;

    cout<<"The list of notes used: ";
    for (int i = 0; i < k; i++)
    {
        cout<<cointlist[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int cost;
    cout<<"Enter the cost: "<<endl;
    cin>>cost;
    printer(cost);
}