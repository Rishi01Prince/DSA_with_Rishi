#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> dis(n, 1e16);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});
    dis[s] = 0;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int wt = pq.top().second;
        pq.pop();

        for (auto v : adj[node])
        {
            int curr_node = v[0];
            int curr_wt = v[1];

            if (dis[node] + curr_wt < dis[curr_node])
            {
                dis[curr_node] = curr_wt + dis[node];
                pq.push({curr_node, dis[curr_node]});
            }
        }
    }
    return dis;
}

int32_t main()
{

    solve();

    return 0;
}