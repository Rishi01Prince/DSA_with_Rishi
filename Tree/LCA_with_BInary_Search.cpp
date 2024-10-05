#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &adj, int n, int s, map<int, int> &level, vector<vector<int>> &parent)
{

    queue<int> q;
    q.push(s);
    level[s] = 1;
    vector<bool> vis(n + 1, false);
    parent[s][0] = -1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (auto it : adj[p])
        {
            if (vis[it] == false)
            {
                q.push(it);
                parent[it][0] = p;
                level[it] = level[p] + 1;
                vis[it] = true;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int y;
            cin >> y;
            adj[i].push_back(y);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    map<int, int> level;
    vector<vector<int>> parent(n + 1, vector<int>(32, -1));

    BFS(adj, n, 0, level, parent);

    // Binary Lifting :-

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < parent[i].size(); j++)
        {
            cout << parent[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
        {
           if(parent[j][i] != -1){
               parent[j][i + 1] = parent[parent[j][i]][i];
           }
           else{
                parent[j][i + 1] = -1;
           }
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < parent[i].size(); j++)
        {
            cout << parent[i][j] << " ";
        }
        cout << endl;
    }



    int q ;cin>>q;
    while(q--){
        int a , b;cin>>a>>b;
    }
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}