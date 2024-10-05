//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

//We can find minimum Spanning tree either using way or we use DSU (Find the lenght - Sort them and apply dsu)

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0;
        pq.push({0,0});
        vector<bool> vis(n,false);
        
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(!vis[node])ans += w;
            if(vis[node]) continue; 
            vis[node] = true;
            
            for(auto it : adj[node]){
                int curr = it[0];
                int weight = it[1];
                
                if(!vis[curr]){
                    pq.push({weight , curr});
                }
                
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends