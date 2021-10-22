#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define inf 1e18
#define pii pair<ll, ll>
#define vi vector<ll>
#define endl "\n"
#define loop(i,a,b) for(int i = (a); i <= (b); i++)
#define revloop(i,a,b) for(int i = (b); i >= (a); i--)
#define pb push_back
#define ump unordered_map
int main() {
	
	int n;
	cin>>n;
	vector<int> v(n),ans(n);
    stack<int> st;
    
	for(int i=0;i<n;i++)
	{
	    cin>>v[i];
	}
    st.push(v[0]);
    loop(i,1,n-1)
    {
        int next = v[i];
        if(!st.empty())
        {
            int element = st.top();
            st.pop();
            while (element<next)
            {
                cout<<element<<"-->"<<next;
                cout<<endl;
                if (st.empty())
                {
                    break;
                }
                element=st.top();
                st.pop();
            }
            if(element>next)
            st.push(element);
        }
        st.push(next);
    }
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        int next = -1;
        cout<<element<<"-->"<<next;
        cout<<endl;
    }
    // loop(i,0,ans.size()-1)
	// {
	//     cout<<ans[i]<<" ";
	// }



	// ans[n-1] = -1;
	// int val = v[n-1];
	// for(int i=n-2;i>=0;i--)
	// {
	//     if(val>v[i])
	//     {
	//         if(v[i]<v[i+1]){
	//             val = v[i+1];
	//             ans[i]=val;
	//         }
	//         else
	//         {
	//             ans[i] = val;
	            
	//         }
	//     }
	//     else
	//     {
	//         val=v[i];
	//         ans[i]=-1;
	//     }
	// }
	// loop(i,0,ans.size()-1)
	// {
	//     cout<<ans[i]<<" ";
	// }
	return 0;
}
