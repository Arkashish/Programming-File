
#include <bits/stdc++.h>
using namespace std;

int check(string s)
{
    stack<char> ch;
    int i = 0;
    int c = 0;
    while (s[i] != '\0')
    {
        if (ch.empty())
            ch.push(s[i]);
        else
        {
            if (ch.top() == s[i])
            {
                c++;
                ch.pop();
                
            }
            else
            {
                ch.push(s[i]);
            }
        }
        i++;
    }
//    cout<<"\n"<<c<<"\n";
    if (c % 2 == 0)
        return 0;
    else
        return 1;
}
int main()
{
    string s;
    //cout << "Enter the string: ";
    cin >> s;
    int a = check(s);
    //cout << "\n";
    //cout << a << endl;
    if(a==1)
    cout<<"Yes"<<"\n";
    else
    cout<<"No"<<"\n";
}