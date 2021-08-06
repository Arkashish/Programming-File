

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	 ll ans =0;
	   ll N,p,K;
	   cin>>N>>p>>K;
	   ll q = p%K;
	   q--;
	  
	   ll s = (((N-1)/K)*K);
	   s=N-1-s;
	   if(q>s)
	   {
	       ans+=(s+1)*((N-1)/K+1)+(q-s)*((N-1)/K);
	   }
	   else
	   {
	       ans+=((N-1)/K+1)*(q+1);
	   }
	   for(int i=q+1; i<N;i+=K)
	   {
	       ans++;
	       if(i==p){
	       cout<<ans<<endl;
	       break;
	       }
	   }
	}
}


// 
// 	   ll c=0,r=0;
	   
// 	   for(int i=0;i<K;i++)
// 	   {
// 	       for(int j=i;j<N;j+=K)
// 	       {
// 	           if(j==p)
// 	           {
// 	               c++;
// 	               r=1;
// 	               break;
// 	           }
// 	           c++; 
// 	       }
// 	       if(r)
// 	       break;
// 	   }
// 	   cout<<c<<endl;
// 	}
// 	return 0;

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// int main() {
// 	// your code goes here
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	   int N,p,K;
// 	   cin>>N>>p>>K;
	   
// 	   int ans =0;
// 	   int q = p%K;
// 	   q--;
// 	   int s = ((N-1)/K)*K;
// 	   s=N-1-s;
// 	   if(q>s)
// 	   {
// 	       ans+=(s+1)*((N-1)/(K+1))+(q-s)*((N-1)/K);
// 	   }
// 	   else
// 	   {
// 	       ans+=((N-1)/(K+1))*(q+1);
// 	   }
// 	   for(int i=q+1; i<N;i+=K)
// 	   {
// 	       ans++;
// 	       if(ans==p){
// 	       cout<<ans<<endl;
// 	       break;
// 	       }
// 	   }
// 	}
// 	return 0;
// }
	 

//         // int N,p,K;
// 	   // cin>>N>>p>>K;//N=10,p=5,k=5
// 	   // int ans=0,c=1;
// 	   // vector<int> v(N,-1);
// 	   //// for(int i=0;i<N;i+=K)
// 	   //int i=0;
// 	   //for(int i=0;i<N;i++)
// 	   //{
// 	   //    if(i%K==p)
// 	   //    break;
	       
// 	   //}
// 	   // while(i<N)
// 	   // {
// 	   //     if(i+K<N){
// 	   //         i=i+K;
// 	   //     if(i==p || i%K==p){
// 	   //         break;
// 	   //     }
// 	   //     c++;
// 	   //     }
// 	   //     else
// 	   //     {
// 	   //         i=i+K-N;
// 	   //         if(i==p || i%K==p){
// 	   //         break;
// 	   //         }
// 	   //     c++;
// 	   //     }
// 	   // }
// 	   // cout<<c<<endl;