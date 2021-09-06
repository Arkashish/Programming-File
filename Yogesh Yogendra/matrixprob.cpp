
#include<bits/stdc++.h>
using namespace std;

void binsearch(vector<vector<int>> &v,int n,int m,int row,int t)
{
    int low = 0,high = m-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if(t == v[row][mid])
        {
            cout<<"Found at "<<row<<" "<<mid;
            return;
        }
        else if( t > v[row][mid]) 
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    cout<<"Not found"<<"\n";
    
}
void solve(vector<vector<int>> &v,int n,int m,int t)
{
    int low = 0;
    int high = n-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if(t == v[mid][0])
        {
            cout<<mid<<" "<<0;
            break;
        }
        else if(t == v[mid][m-1])
        {
            cout<<mid<<" "<<(m-1);
            break;
        }
        else if(t<v[mid][0])
        {
            high = mid-1;
        }
        
        else if(t>v[mid][m-1])
        {
            low = mid+1;
        }
        else if(t>v[mid][0] and t<v[mid][m-1])
        {
            binsearch(v,n,m,mid,t);
            break;
        }
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int t;
    cin>> t;

    solve(v,n,m,t);
}