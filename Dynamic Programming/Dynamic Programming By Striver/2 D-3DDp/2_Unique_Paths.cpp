#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int memo(int m ,int n , vector<vector<int>> &dp  ){
        if(m<0 || n<0) return 0;
        if(m == 0 && n==0) return 1;
        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = memo(m-1,n, dp ) + memo(m, n-1 , dp);
    }
    
    int Tabulation(int m , int n ){
        vector<vector<int>> dp(m , vector<int> (n , 0));
        dp[0][0] = 1;

        for(int i = 0 ; i< m ;i++){
            for(int j = 0 ; j<n ;j++){
               if(i-1>=0) dp[i][j] = dp[i-1][j];
               if(j-1>=0) dp[i][j]+= dp[i][j-1];
    
            }
        }
        
        return dp[m-1][n-1];
    }
 


// n+1
// m+1
    int uniquePaths(int m, int n){
        //Memo Starts :-
        // vector<vector<int>> dp(m , vector<int> (n , -1));
        // int ans = memo(m-1 , n-1 , dp );

        //Tabulation
        int ans = Tabulation(m , n);
        return ans;
    }
};

int32_t main() {
    int m, n;
    cin >> m >> n;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
    
    return 0;
}