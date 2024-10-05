//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//Q link : - https://practice.geeksforgeeks.org/problems/topological-sort/1
// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	static void DFS(vector<int> adj[] , vector<bool> &vis ,stack<int> &st  ,int o ) {
	    vis[o] = true;
	    
	    for(auto v : adj[o]){
	        if(vis[v] == false){
	            DFS(adj ,vis , st ,v );
	        }
	    }
	    st.push(o);
	    
	}
	vector<int> topoSort(int n, vector<int> v[]) 
	{
	    
	 
	   vector<bool> vis(n , false);
	   vector<int> ans;
	   stack<int> st;
	   for(int i = 0 ; i< n;i++){
	       if(vis[i] == false){
	           DFS(v, vis , st , i);
	           
	       }
	   }
	   while(!st.empty()){
	               // cout<<st.top()<<" ";
	               ans.push_back(st.top()) ;st.pop();
	              
	           }
	   return ans;
	}
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends