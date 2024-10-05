#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    vector<int> deg(n , 0);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].insert(b - 1);
        adj[b- 1].insert(a - 1);
    }
    queue<int> q;

    for (int i = 0; i < n; i++){
        deg[i] = adj[i].size();
        if(deg[i]== 1) q.push(i);
    }
    // cout<<q.size()<<endl;
    int ans = 0;


    while (q.empty()!=1)
    {
        ans++;
        int s = q.size() ;
        for (int i = 0; i <s; i++)
        {
            int x = q.front();
            q.pop();
            for(auto it : adj[x]){
                adj[it].erase(x);
            }
            adj[x].clear();
        }
        for (int i = 0; i <n; i++)
        {
           if(adj[i].size() == 1) q.push(i);
        }
        

    }

    cout<<ans<<endl;
    
    
    
}

int32_t main()
{
    

        solve();
    
    return 0;
}