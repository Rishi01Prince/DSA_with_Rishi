#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());

void solve(int n)
{
    if (n == 0)
    {
        return;
    }

    solve(n - 1);
    cout << n << endl;
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}