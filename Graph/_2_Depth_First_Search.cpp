#include <bits/stdc++.h>
using namespace std;



//For Connected Graph
//Time Complexity : O(v+h)
//Space Complexity : O()

void Depth_First_Search(vector<vector<int>> adj , int vertices , int start_node,vector<bool> &visited){
    // vector <bool> visited(vertices+1,false);
    visited[start_node] = true;
    cout<<start_node<<" ";
   
   for (auto v : adj[start_node] ){
        if(visited[v]== false){
            Depth_First_Search( adj , vertices ,  v,visited);
        }
  }
}



//For Unoconnected Graph & start vertex is also not given

void DFS_Unconnected_Graph(vector<vector<int>> v, int no_of_vertex){
    vector<bool> visited(no_of_vertex+1 , false);

    for (int i = 0; i < no_of_vertex; i++){
        if(visited[i]==false){
            Depth_First_Search(v,no_of_vertex,i, visited );
        }
    }
}
void solve(){
    vector<vector<int>> v  = {{1,2},{0,2,3},{0,1,3,4},{1,2,4},{2,3}};
   
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        
    }
    int no_of_vertex =4;
    // Breadth_First_Search(v,4, 0);
    DFS_Unconnected_Graph( v,  no_of_vertex);
}

int32_t main() {
   
    solve();
    return 0;
}