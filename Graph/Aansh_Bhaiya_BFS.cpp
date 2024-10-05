#include <bits/stdc++.h>
using namespace std;

// getline(cin, str);
// #define yes cout<<"YES"<<endl;
// #define no cout<<"NO"<<endl;
// #define int long long int
//  map<int,int> mpp;
// sort(v.begin(),v.end());
// to_string(n)
//   A= 65   Z= 90  a =97  z = 122
// Int to string                 ostringstream str1; str1 << num; string str = str1.str();
//   String to Integer int num = stoi(str);

// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);

// std::vector<int>::iterator upper1, upper2;
// upper1 = std::upper_bound(v.begin(), v.end(), 35);
// upper2 = std::upper_bound(v.begin(), v.end(), 45);
// std::cout  << (upper1 - v.begin());
// std::cout << (upper2 - v.begin());
//  __builtin_popcount(n);
// binary_search(v.begin(), v.end(), x);

void BFS(vector<int> adj[], int n, int src)
{
    queue<int> q;
    q.push(src);
    vector<int> vis(n + 1, 0);
    vis[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        queue<int> temp;
        while (q.size() > 0)
        {

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    temp.push(it);
                    vis[it] = 1;
                }
            }

            q.pop();
        }
        q = temp;
    }
}

void solve()
{
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