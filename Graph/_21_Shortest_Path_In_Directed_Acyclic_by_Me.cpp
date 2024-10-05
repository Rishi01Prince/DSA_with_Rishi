//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// User function Template for C++
class Solution {
  public:
    
     vector<int> shortestPath(int n,int m, vector<vector<int>>& v){
         vector<vector<pair<int,int>>> adj(n);
         vector<int> dist(n , 1e8);
         vector<bool> vis(n , false);
         

         for(int i = 0 ; i< m ;i++){
            adj[v[i][0]].push_back({v[i][1], v[i][2]});
         }
        
        //Game Begins :- :)
         dist[0] = 0;
         stack<int> st;st.push(0);
         
         while(!st.empty()){
             int node = st.top();
             st.pop();
             
             for(auto  it: adj[node]){
                 int v  = it.first;
                 int wt = it.second;
                 
                 if(dist[node] + wt < dist[v]){
                     dist[v] = dist[node] + wt;
                     st.push(v);
                 }
                 
             }
         }
         for(int i = 0 ; i< n ;i++){
             if( dist[i] == 1e8) dist[i] = -1;
         }
         return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends