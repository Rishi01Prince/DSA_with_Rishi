#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int co) {
        int n = v.size() ;
        int m = v[0].size();
        int a = v[sr][sc];
        vector<vector<bool>> vis ( n , vector<bool> (m,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            int r = q.front().first ;
            int c = q.front().second ;
            v[r][c] = co;
            q.pop();

            int x[] = {0,0,1,-1};
            int y[] = {-1,1,0,0};

            for(int i = 0 ; i< 4 ;i++){
               int p = r+x[i];
               int u = c+y[i];
                if(0<=p && 0<=u && p<n && u<m  && vis[p][u] == false && v[p][u] ==a){
                    v[p][u] = co;
                    vis[p][u] =true;
                    q.push({p,u});
                    // q.push({p,q});
                }
            }
        }
        return v;

        
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