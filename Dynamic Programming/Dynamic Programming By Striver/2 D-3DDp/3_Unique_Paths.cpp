#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int count_path( int m , int n , vector<vector<int>> &dp,vector<vector<int>>& obs){
        if(m<0 || n<0) return 0;
        if(obs[m][n] == 1 ) return dp[m][n]= 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = count_path(m-1, n ,dp,obs) +  count_path(m, n-1 , dp,obs);
    }

    int Tabulation( int m , int n  , vector<vector<int>>& obs){
       vector<vector<int>> dp(m , vector<int> (n,0));
        dp[0][0] =1;

        for(int i = 0 ; i<m ; i++ ){
            for(int j = 0 ; j<n ;j++ ){
                if (obs[i][j]) dp[i][j] = 0;
                else {
                    if(i>0) dp[i][j] +=dp[i-1][j];
                    if(j>0) dp[i][j]+=dp[i][j-1];
                }
               
            }
        }

        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n =obs[0].size();

        //Memonization
        // vector<vector<int>> dp(m , vector<int> (n,-1));
        // int ans = count_path(m-1 ,  n-1 ,dp,obs );

        int ans = Tabulation(m , n , obs);
        
        return ans;
        
    }
};

int32_t main() {
    int m , n;
    cin>>m>>n;
    vector<vector<int>> obs(m , vector<int> (n,0));
    for(int i = 0 ; i<m ; i++ ){
        for(int j = 0 ; j<n ;j++ ){
            cin>>obs[i][j];
        }
    }
    return 0;
}