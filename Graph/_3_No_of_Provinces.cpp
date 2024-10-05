//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     static void DFS(vector<vector<int>> &adj , vector<bool> &vis ,int o  ){
        vis[o] = true;
        for(auto it : adj[o]){
            if(vis[it]  == false){
                DFS(adj , vis , it);
            }
        }
        
    }
    
    int numProvinces(vector<vector<int>> v, int n) {
        int ans = 0;
        // int n = v[0].size();
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i< v.size()  ;i++){
            for(int j =  0 ; j< n ;j++){
                if(i!=j && v[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
     

        vector<bool>  vis( n , false);

        for(int i =  0 ; i< n ; i++){
            if(vis[i]== false){
                DFS(adj , vis , i);
                ans++;
            }
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends