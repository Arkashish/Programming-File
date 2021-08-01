
//Program to sort in such a way that even numbers come first and then opdd numbers;

#include <bits/stdc++.h>
using namespace std;

bool condition(int key, int val)
{
    if (key % 2 == 0 and val % 2 == 0)
        return key>val;
    else if (key % 2 != 0 and val % 2 != 0)
        return key > val;
     else if (key % 2 != 0 and val % 2 == 0)
        return true;
    else
        return false;
}
void func(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 and condition(arr[j], val))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(arr,n);
    for (int i = 0; i < n; i++)
    {
       cout<< arr[i] << " ";
    }
}