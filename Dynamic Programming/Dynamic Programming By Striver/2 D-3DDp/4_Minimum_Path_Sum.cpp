#include <bits/stdc++.h>
using namespace std;


//Leetcode 64. Minimum Path Sum Link : https://leetcode.com/problems/minimum-path-sum/


class Solution {
public:
    int Memo(vector<vector<int>> &v  ,vector<vector<int>> &dp , int n , int m ){
        if(n<0 || m<0) return 1e6;
        if(n==0 && m==0) return dp[0][0] =v[0][0];
        if(dp[n][m] != 1e6) return dp[n][m];
        int up = 1e6,left =1e6;

        if(n>0) up =  v[n][m]  +  Memo(v,dp , n-1,  m)  ;
        if(m>0) left = v[n][m]  +  Memo(v,dp , n,  m-1)  ;
        return dp[n][m] = min(up , left);
    }

    int Tabulation(vector<vector<int>> &v , int n ,int m ){
        vector<vector<int>> dp(n+1 , vector<int> (m+1 ,1e6));
        dp[0][0] = v[0][0];

        for(int i = 0 ;i< n;i++){
            for(int j = 0 ;j<m ;j++){
                
                if(i>0) dp[i][j] = min(dp[i][j] , dp[i-1][j] + v[i][j]);
                if(j>0) dp[i][j] = min(dp[i][j] , dp[i][j-1] + v[i][j]);
            }
        }
        return dp[n-1][m-1];

    }
    int minPathSum(vector<vector<int>>& v) {
        
        int n = v.size();
        int m = v[0].size() ;
        //Memonization :-
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 ,1e6));
        // int ans = Memo(v ,dp , n-1 , m-1);

        //Tabulation
        int ans = Tabulation(v, n ,m);

        return ans;
    }
};

int32_t main() {
    int m , n;
    cin>>m>>n;
    vector<vector<int>> v(m , vector<int> (n,0));
    for(int i = 0 ; i<m ; i++ ){
        for(int j = 0 ; j<n ;j++ ){
            cin>>v[i][j];
        }
    }

    return 0;
}