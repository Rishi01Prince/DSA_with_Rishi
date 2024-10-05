#include <bits/stdc++.h>
using namespace std;

//#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());


class Solution {
public:
    static void helper(vector<vector<int>> &v , vector<vector<bool>> &vis , int i , int j , int n , int m ){

        vis[i][j] = true;
        v[i][j] =0;
        int x[] = {0, 0 , 1 , -1};
        int y[] = {-1 , 1 , 0 , 0};
        for(int  k = 0 ; k< 4 ;k++){
            int  p = i+x[k];int q =j+y[k];
            if(p>=0 && q>=0 && p<n && q<m && vis[p][q] == false && v[p][q] == 1){
                helper(v , vis , p,q,n ,m);
            }
            
        }

    }
    int numEnclaves(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n , vector<bool> ( m , false));

        for(int i= 0 ; i< n ;i++){
            for(int j =0 ;j< m ;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && vis[i][j] == false && v[i][j] == 1){
                   helper(v , vis , i,j,n ,m);
                }
            }
        }
        for(int i= 0 ; i< n ;i++){
            for(int j =0; j< m ;j++){
                if(v[i][j] == 1){
                  ans++;
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