#include <bits/stdc++.h>
using namespace std;

//Link :-    https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
//Function to find the shortest path in an unweighted and undirected Graph
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<vector<int>> adj(n);
        vector<int> dis(n ,-1);
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(src);
        vis[src] =true;
        dis[src] = 0;
        
        for(int i =  0 ; i< edges.size() ;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        while(q.empty()!=true){
            int curr = q.front();
            for(auto v : adj[curr]){
                if(vis[v] == false){
                    dis[v] =dis[curr]+1;
                    vis[v]=true;
                    q.push(v);
                }
            }
            q.pop();
        }
      
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends