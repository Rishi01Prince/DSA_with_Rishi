//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//Q link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    static bool check(vector<int> adj[] , vector<bool> &vis , vector<bool> &rec_stack ,int &n ,int origin){
        vis[origin] = true;
        rec_stack[origin] = true;
        // cout<<origin<<" ";
        
        for(auto v : adj[origin]){
            
            if( (vis[v] == false)    && check(adj , vis , rec_stack , n , v) ){
                    return true;
            }
            //Visisted hai ye
            else if(rec_stack[v] == true) return true;
   
        }
        
        rec_stack[origin] = false;
        
        
        return false;
    }
    
    
    bool isCyclic(int v, vector<int> adj[]) {
        int n = v;
        // cout<<adj[0][0]<<"   ";
        
        vector<bool> vis(n,false);
        vector<bool> rec_stack (n ,false);
        
        for(int i =0  ; i< n ;i++){
            if(vis[i] == false){
                 if(check(adj , vis , rec_stack , n , i) == true){
                    return true;
                }
                   
            }
        }
     
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends