//Give me the code of Djikstra's algorithm IN C++.
//I am not able to understand the code given in the book.
//I am a beginner in C++.   Give me the code of Djikstra's algorithm IN C++.
#include <bits/stdc++.h>
using namespace std;




void Djkistra(vector<pair<int,int>> v[] , int n , int src){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(n , INT_MAX);
    dist[src] = 0;
    pq.push({0 , src});
    while(pq.empty()!=1){
        int x = pq.top().second;
        pq.pop();
        for(auto it : v[x]){
            int y = it.first;
            int w = it.second;
            if(dist[y] > dist[x] + w){
                dist[y] = dist[x] + w;
                pq.push({dist[y] , y});
            }
        }
    }
    for(int i = 0 ; i< n ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    int n , m;
    cin>>n>>m;
    vector<pair<int,int>> v[n];
    for(int i = 0 ; i< m ; i++){
        int x , y , w;
        cin>>x>>y>>w;
        v[x].push_back({y , w});
        v[y].push_back({x , w});
    }
    Djkistra(v , n , 0);
    
    


}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}
