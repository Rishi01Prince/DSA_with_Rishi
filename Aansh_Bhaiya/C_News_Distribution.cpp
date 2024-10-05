#include <bits/stdc++.h>
using namespace std;


int find(vector<int> &parent, int node)
{
    if (node == parent[node])
        return node;
    else
        return parent[node] = find(parent, parent[node]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> v(m+1);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }

    vector<int> parent(n+1);
    vector<int> size(n+1, 1);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        if(v[i].empty()) continue; 
        int x = v[i][0];
        for (int j = 1; j < v[i].size(); j++)
        {
            int y = v[i][j];
            int a = find(parent, x);
            int b = find(parent, y);

            if (a != b)
            {
                if (size[a] < size[b])
                {
                    parent[a] = b;
                    size[b] += size[a];
                }
                else
                {
                    parent[b] = a;
                    size[a] += size[b];
                }
            }
        }
    }


    for (int i = 1; i <= n; i++)
    {
        int node = find(parent, i);
        cout << size[node] << " ";
    }
    cout << endl;
    
}

int32_t main()
{
    solve();
    return 0;
}