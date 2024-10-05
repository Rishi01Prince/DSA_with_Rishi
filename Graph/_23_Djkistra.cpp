//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//link : gfg -- Driver Code
//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        vector<int> dis(n , 1e8);
        
        priority_queue<pair<int,int>  , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({s,0});
        dis[s] = 0;
        
        while(!pq.empty()){
            int node = pq.top().first;
            int wt = pq.top().second;
            pq.pop();
            
            for(auto v : adj[node]){
                int curr_node = v[0];
                int curr_wt = v[1];
                
                if(dis[node] + curr_wt < dis[curr_node] ){
                    dis[curr_node] = curr_wt + dis[node];
                    pq.push({curr_node , dis[curr_node]});
                }
            }
            
        }
        return dis;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends