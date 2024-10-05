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
    
    int mn = arr[0];
    int maxdiff = arr[1] - arr[0];
    
    for (int i = 0; i < n; i++){

        maxdiff = max(maxdiff, arr[i] - mn);
        mn = min(mn, arr[i]);
    }
    cout << maxdiff << endl;
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