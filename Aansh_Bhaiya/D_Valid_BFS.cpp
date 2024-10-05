#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> given(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++){
        cin>>given[i];given[i]--;
    }

    map<int, int> mpp;

    queue<int> q; 
    q.push(given[0]);
    vector<bool> vis(n , false);
    vis[given[0]] = true;
    mpp[given[0]] = -1;


    while(!q.empty()){
        int node = q.front();  
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                mpp[it] = node;
                vis[it] = true;
                q.push(it);
            }
        }
    }

   
    int st = 1; 
    queue<int> check ;
    check.push(0);

    while(st< n && check.empty()!=1){

        queue<int> temp ;

        while( st< n && check.empty()!=1){
            if(mpp[given[st]]  == check.front()){
                temp.push(given[st]) ; st++;
            }
            else{
                check.pop();
            }
        }
        check = temp ;

    }

    if(st == n ){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
}

int32_t main()
{

    solve();

    return 0;
}