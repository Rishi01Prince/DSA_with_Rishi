#include <bits/stdc++.h>
using namespace std;



//For Connected Graph
//Time Complexity : O(v+h)
//Space Complexity : O()
//Main BFS 
void Breadth_First_Search(vector<vector<int>> adj , int vertices , int start_node,vector<bool> &visited){
    
    visited[start_node] = true;
    queue<int> q;
    cout<<start_node<<" ";
    q.push(start_node);

    while (q.empty() != true){
        int v = q.front();
        for(int p : adj[v] ){
            if(visited[p] == false){
                cout<<p<<" ";
                visited[p] = true;
                q.push(p);
            }
        }
        q.pop();
    }
    
}



//For Unoconnected Graph & start vertex is also not given

void BFS_Unconnected_Graph(vector<vector<int>> v, int no_of_vertex){
    vector<bool> visited(no_of_vertex+1 , false);
    for (int i = 0; i < no_of_vertex; i++){
        if(visited[i]==false ){
            Breadth_First_Search(v,no_of_vertex,i, visited );
        }
    }
}

void solve(){
    vector<vector<int>> v  = {{1,2},{0,2,3},{0,1,3,4},{1,2,4},{2,3}};
   
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        
    }
    int no_of_vertex =4;
    // Breadth_First_Search(v,4, 0);
    BFS_Unconnected_Graph( v,  no_of_vertex);
}

int32_t main() {
    solve();
    return 0;
}



