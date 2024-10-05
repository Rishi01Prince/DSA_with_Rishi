#include <bits/stdc++.h>
using namespace std;

long long r = 0 ;
long long c = 0;
bool isBiPartite(vector<vector<int>> &adj, vector<int> &color, int o ){
    if(color[o] == 0 )   {

    } 

    return true;
}

void solve()
{
    int m, n;
    cin >> n >> m;

    vector<vector<int>> v(n);
    vector<int> color(n + 1, 0);
    vector<bool> vis(n, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++)
    {
        bool isBipa = isBiPartite(v, color, i);
        if (!isBipa)
        {
            cout << i << endl;
            cout << "NO" << endl;
            break;
        }
    }
}

int32_t main()
{
    int T;
    cin >> T;

    for(int i )

    while (T--)
    {
        solve();
    }
    return 0;
}