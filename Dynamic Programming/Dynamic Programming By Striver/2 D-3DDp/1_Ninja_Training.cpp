#include <bits/stdc++.h>
using namespace std;


int memo(vector<vector<int>> &v , vector<vector<int>> &dp , int n , int last){
    if(n<0) return 0;
    if(n==0){
        int ma = -1e6;
        for(int i = 0 ; i<3 ;i++){
            if(i!=last) ma = max(ma , v[0][i]);
        }
        return dp[n][last] = ma;
    }
    if(dp[n][last]!=-1) return dp[n][last];

    int zero = -1e6 ,   one = -1e6,  third = -1e6;

    if(last != 0) zero = v[n][0] +  memo(v , dp ,n-1 , 0 );
    if(last != 1) one = v[n][1] +  memo(v , dp ,n-1 , 1 );
    if(last != 2) third = v[n][2] +  memo(v , dp ,n-1 , 2 );

    return dp[n][last] = max({one,zero , third});
    
}

int Tabulation(vector<vector<int>> &v , int n){
    
    vector<vector<int>> dp(n , vector<int> (3,0));
    dp[0][0] = v[0][0] , dp[0][1] = v[0][1] , dp[0][2] =v[0][2];
    
    for(int i = 1 ; i <n ;i++){
        dp[i][0] = v[i][0] +  max (dp[i-1][2] ,dp[i-1][1]);
        dp[i][1] = v[i][1] +  max (dp[i-1][0] ,dp[i-1][2]);
        dp[i][2] = v[i][2] +  max (dp[i-1][1] ,dp[i-1][0]);
    }

    return max({dp[n-1][0] , dp[n-1][1] , dp[n-1][2]});
}

int ninjaTraining(int n, vector<vector<int>> &v){

    //Its Memonization :-

    // vector<vector<int>> dp(n+1 , vector<int> (4 ,-1));
    // memo(v , dp ,n-1 , 3 );
    // int ans = dp[n-1][3];

    //Tabulation
    int ans = Tabulation(v ,n);

    
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    cout << ninjaTraining(n, v) << endl;
    
    return 0;
}