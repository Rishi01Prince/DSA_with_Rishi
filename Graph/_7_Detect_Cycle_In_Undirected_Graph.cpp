
#include <bits/stdc++.h>
using namespace std;

//Q link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public: 
    // Function to detect cycle in an undirected graph.
    static bool DFS(vector<int> adj[] , vector<bool> &vis ,int origin , int last ){
        vis[origin] = true;
        
        for(auto v :  adj[origin]){
            if(vis[v] == false){
                //kahi iske children me ho jisme ye property satisfy kr rahi hai
                if(DFS( adj , vis , v, origin) == true) return true;
            }
            else{
                // Agar visited true hai  to check karo ki yahi call krne wala to ni 
                if(v!=last) return true;
            }
        }
        
        return false;
        
    }
    
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> vis (n , false);
        for(int i =0 ; i< n ;i++){
            for(auto it : adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
        //for undirected Graph
        for(int i = 0 ; i<n ;i++){
            if(vis[i]==false ){
                if(DFS(adj , vis , i , -1)) return true;
            }
        }
        
        
        
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends