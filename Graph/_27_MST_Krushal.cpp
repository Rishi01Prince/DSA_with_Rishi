//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int parent(int node , vector<int>& par){
	    if(node== par[node]) return node;
	    return par[node] = parent(par[node] , par);
	}
	
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<int> sizes(n , 1);
        vector<int> par(n , 0);
        int ans = 0;
        
        for(int i =0 ;i<n ;i++){
            par[i] = i;
        }
        
        vector<pair<int,pair<int,int>>> edges ;
        
        for(int i = 0 ;i<n ;i++){
            for(int j = 0 ;j<adj[i].size() ;j++){
                 edges.push_back({adj[i][j][1] , {i , adj[i][j][0]}});
            }
        }
        
        sort(edges.begin() , edges.end());
        
        for(int i = 0;i<edges.size();i++){
            int u = parent(edges[i].second.first , par);
            int v = parent(edges[i].second.second, par);
            
            if(u!=v){
                if(sizes[u] > sizes[v]) par[v] = u;
                else par[u] = v;
                ans+=edges[i].first;
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