#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());


class Solution {
public:
    bool isBiPar(vector<vector<int>> &adj , int n , vector<int> &vis , vector<int> &color , int o){


        queue<int> q ;q.push(o); vis[o] = true;
        color[o] = 1; 

        while(!q.empty() ){
            int p = q.front();
            q.pop();

            for(auto v : adj[p]){
                if(vis[v]==false){
                    vis[v] = true;
                    q.push(v);
                    color[v] = - color[p];
                }
                else {
                    if(color[p] == color[v]) return false;

                }

            }
        }

        return true;
        
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n , 0 );
        vector<int> vis(n , false);

       for(int i = 0 ; i< n ;i++){
           if(vis[i] == false){
               if(isBiPar(adj , n , vis , color , i)==false) return false;
           }
       }
        return true;
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