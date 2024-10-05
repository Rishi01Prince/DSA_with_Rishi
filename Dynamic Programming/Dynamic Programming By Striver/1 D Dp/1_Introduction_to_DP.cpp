//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int m = 1e9+7;
public:
    long long int solve(int n  , vector<long long int> &dp){
        if (n <= 0) return dp[0] =  0;
        if (n <= 2) return dp[n] = 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n-1,dp)%m  + solve(n-2,dp)%m )%m;
    }
    long long int topDown(int n) {
        vector<long long int > dp(n+1 , -1);
        solve(n , dp);
        return dp[n];
    }
    
    long long int bottomUp(int n) {
       
        
        if (n == 0) return 0;
        if (n <= 2) return 1;
        
        long long int a = 1;
        long long int b = 1;
        long long int ans = b;
        
        for (int i = 3; i <= n; i++) {
            ans = (a % m + b % m) % m;
            b = a;
            a = ans;
        }
        
        return ans % m;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends