#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
long long r = 0;
long long b = 0;
vector<long long> power_of_two(300001, 1);

bool isBipartite(vector<vector<int>> &adj, vector<int> &color, vector<bool> &vis, int o, int col)
{

    vis[o] = true;
    color[o] = col;
    if (color[o] == 1)
    {
        r++;
    }
    else if (color[o] == -1)
    {
        b++;
    }

    for (auto v : adj[o])
    {

        if (vis[v] == false)
        {

            if (!isBipartite(adj, color, vis, v, -color[o]))
                return false;
        }
        else if (color[v] == color[o])
        {

            return false;
        }
    }
    return true;
}
void solve()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, 0);
    vector<bool> vis(n, false);

    long long ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false && color[i] == 0)
        {

            if (isBipartite(adj, color, vis, i, 1))
            {
                ans *= (power_of_two[r] + power_of_two[b]) % mod;
                ans%=mod;
                r = 0;
                b = 0;
            }
            else
            {
                cout << 0 << endl;
                r = 0;
                b = 0;
                return;
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= 300000; i++)
    {
        power_of_two[i] = ((long long)2 * power_of_two[i - 1]) % mod;
    }

    while (T--)
    {
        solve();
    }
    return 0;
}