#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());
//link :- https://leetcode.com/problems/course-schedule-ii/
//Comment :- This is a topological sort problem. We have to find the order in which the courses should be taken.
class Solution {
public:
    static void BFS_Topo(vector<vector<int>> &adj ,vector<int> &indeg , vector<bool> &vis , int o , vector<int> &ans){
        queue<int> q;
        q.push(o);
        vis[o]=true;
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            for(auto v : adj[x]){
                indeg[v]--;
                if(vis[v] == false  && indeg[v] == 0 ){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }


    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        vector<bool> vis(n,false);
        vector<int> ans;
     

        for(int i = 0 ; i< v.size() ;i++){
            adj[v[i][1]].push_back(v[i][0]);
            indeg[v[i][0]]++;
        }


        for(int i = 0 ; i< n ; i++){
            if(vis[i] == false && indeg[i]==0 ){
                BFS_Topo(adj,indeg,vis,i,ans);
            }
        }

        if(ans.size()<n) return {};
    
        return ans;
    }
};

void solve(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {

        string str;cin>>str; 
        vector<int> v;
        for (int i=0; i< str.length();i++)
        {
            if ((str[i] != ',') && (str[i] != '[') && (str[i] != ']')  ){
                v.push_back(int(str[i]-'0'));
            }   
        }
       
        solve(v);
    }
    return 0;
}