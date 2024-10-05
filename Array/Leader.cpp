#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = n-1; i >=0; i--)
    {
        if(i==n-1){
            cout<<arr[n-1]<<" ";
        }
        else{
            if(arr[i]>arr[i+1]){
                cout<<arr[i]<<" ";
            }
            else {
                break;
            }
        }
    }
    
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}