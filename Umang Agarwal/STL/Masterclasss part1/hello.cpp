
/* 
STL Libraries used in cpp
*/

#include<bits/stdc++.h> //this is the stl library that includes almost all the stl library available to us
using namespace std;

int main()
{
    int N;
    cin>>N;

    
    //##VECTOR##
    vector<int> vv = { 1,2,3,4,5};
    vector<int> v(N); // here vector is basically a dynamic array
    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }
    v.push_back(7);//note here we can add a value without any modification in the size.
    cout<<"Output for v: ";
    for(int i=0;i<v.size();i++) 
    {
        cout<<v[i];//1234567
    }
    cout<<"\nOutput for v1:  ";
    vector<int> v1(N);
    v1.push_back(7); //Note one thing carefully the seven will be pushed at the back of the vector only after the first six places have some value or they will be initialised with zero 
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]; //output -> 0000007
    }


    //##PAIR##
    cout<<"\nPairs: \n";
    vector<pair<int,int>> p1;
    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin>>a>>b;
        p1.push_back({a,b});
    }
    p1.push_back({1,7});
    cout<<"Output for pairs:\n";
    for(int i=0;i<p1.size();i++)
    {
        //p1[i] = {a,b};
        //key = p1[i].first;
        //value = p1[i].second;
        cout<<p1[i].first<<" "<<p1[i].second<<"\n"; //output -> 0000007
    }





    //##SETS##
    //One of feature of sets and all other containers(except vector) we cannot set size
    // we also cannot iterate in indexes except for arrays or vectors and hence we use iterators

    set<int> st;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    for(auto it: st)
        cout<< it << " "; // Also a set returns unique elements in sorted order
    cout<<"\n"<<"Number of distinct elements : "<<st.size();


    //Now Suppose the size of a pair is given

    vector<pair<int,int>> p2(N);
    for (int i = 0; i < N; i++)
    {
        cin>>p2[i].first>> p2[i].second  ;
    }
    for (int i = 0; i < N; i++)
    {
        cout<<p2[i].first<< p2[i].second <<endl ;
    }

    //Now Suppose we want to include the pair into a seet then: 

    // {a,b} is not equal to {b,a}
    set<pair<int,int>> p3;
    for (auto it: p2)
    {
        p3.insert(it);
    }
    for (auto it: p3)
    {
        cout << it.first << " " << it.second <<endl;
    }
    

    // ##MAPS##

    //map stores key value pair
    // it sorts  the elements in accordance to their ascii value
    map<string,float> mp;
    mp.insert({"Arkashish",9.72});
    mp.insert({"Rahul",9.46});
    mp.insert({"Kunal",9.90});
    mp.insert({"Tarun",8.90});

    cout<<mp["Arkashish"]<<endl;
    //THe same thing (functions) of aa map can be done in maps but we dont get the random access
    for(auto it: mp)
    {
        cout<<it.first << " " <<it.second <<endl;
    }

    cout<<"\n\n";
    if(mp.find("Codechef")!=mp.end())
    {
        cout<<"Codechef is found"<<"\n";
    }
    else
    {
        cout<<"Not found"<<"\n";
    }
    
}