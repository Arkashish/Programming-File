/*
Program to print n natural nnumbers recurusively. Eg-N=5
1
2
3
4
5
*/
#include<iostream>
using namespace std;

void printsnum(int n)
{
	if(n==0)
	return;
	
	printsnum(n-1);
	
	cout<<n<<endl;
}
int main()
{
    int n;
   cout<<"Ntr the number:";
   cin>>n;
   //cout<<n<<endl;
    printsnum(5);
}