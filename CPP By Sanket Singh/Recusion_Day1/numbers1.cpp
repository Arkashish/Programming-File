/*
##Program 1

#program to print
5
4
3
2
1
2
3
4
5	#recursively
*/
#include <iostream>
using namespace std;

void sum(int n)
{
    if(n==0)
    return;
    
    cout<<n<<endl;
    
    sum(n-1);
    if(n!=1)
    cout<<n<<endl;
    
}

// ## OR ##

void sum1(int n)
{
    if(n==1){
	cout<<1<<endl;
	return;
    }
    
    cout<<n<<endl;
    
    sum1(n-1);
    
    cout<<n<<endl;
    
}


int main() {
    sum(5);
	return 0;
}
