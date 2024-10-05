#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());


class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& adj) {
        int ans = 0;
        int n = adj.size();
        int m = adj[0].size();
        vector<vector<bool>>  vis( n , vector<bool> (m,false));
        queue<pair<pair<int,int>,int>> q;

        for(int i =  0 ; i< n ; i++){
            for(int j = 0 ; j< m ;j++){
                if( adj[i][j] == 2){
                    q.push({{i,j} , 0});
                }
            }
        }
        int x[] = {0 ,0, -1 , 1 };
        int y[] = {1 , -1 , 0, 0}; 
      


        while(!q.empty()){

            int a = q.front().first.first;
            int b = q.front().first.second;
            int k = q.front().second;
            ans = max(ans , k);
            q.pop();

            for(int i = 0 ; i< 4 ;i++){
                int  c = a+x[i];
                int d = b+y[i];

                if(0<=c && 0<=d && c<n && d<m && vis[c][d] == false && adj[c][d] == 1){
                    vis[c][d]=true;
                    q.push({{c,d} , k+1});

                }
            }


        }



        for(int i =  0 ; i< n ; i++){
            for(int j = 0 ; j< m ;j++){
                if(vis[i][j]== false && adj[i][j] == 1){
                    return -1; 
                }
            }
        }

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