#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int n  = v.size();
        int m = v[0].size() ;
        vector<vector<bool>> vis(n , vector<bool> (m,false));
        vector<vector<int>> dis(n , vector<int> (m,false));
        queue<pair<pair<int,int> , int >> q;

        for(int i = 0 ;i<n ;i++ ){
            for(int j = 0 ; j< m ;j++){
                if(v[i][j] == 0){
                    vis[i][j] = true;
                    q.push({{i,j} , 0});
                    dis[i][j] = 0;
                }
            }
        }


        while(!q.empty()){
            int x_node = q.front().first.first;
            int y_node = q.front().first.second;
            int distance = q.front().second;

            int x[] = {0,0,1 ,-1};
            int y[] = {-1,1 ,0,0};  
            q.pop();

            for(int i = 0 ; i < 4 ;i++){
                int a = x_node + x[i];
                int b = y_node + y[i];

                if(0<=a && 0<=b && a<n && b<m && vis[a][b] == false){
                    vis[a][b]=true;
                    dis[a][b] = distance +1;

                    q.push({ {a,b},dis[a][b]});

                }

            }

        }

        
        return dis;
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