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

    int m =0;
    int temp=0;
    
    for (int i = 0; i < n; i++)
    {
        temp=max(arr[i]+temp,temp);
        
    }

    cout<<temp<<endl;

    


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