//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
     int Memo(vector<int>& v , vector<int> &dp , int n ,int &k  ){
        
        if(n==0) return dp[0] = 0;
        if(n==1) return dp[1] = abs(v[1]-v[0]);
        if(dp[n] != -1) return dp[n];
        
        int step = 1e8 ; 
        
        for(int i = 1 ; i<=k ;i++){
            if(n-i>=0) step = min(step ,  abs(v[n]- v[n-i]) + Memo(v, dp ,n-i ,k) );
        }
        return dp[n]  =step; 
    }
    
    int minimizeCost(vector<int>& v, int n, int k) {
        
        
        //Memonization Stuff
        // int ans = INT_MAX;
        // vector<int> dp(n , -1);
        // ans = Memo(v, dp ,n-1 ,k);
        
        
        // Tabulation Starts
        if(n==1) return 0;
        vector<int> dp(n,0);
        dp[1] = abs(v[1] - v[0]);
        
        for(int i = 2 ; i<n ;i++){
            int step = 1e8;
            
            for(int j = 1 ; j<=k;j++)
                if(i-j>=0) step = min(step , abs(v[i] -v[i-j]) + dp[i-j]);
            
            dp[i] = step;
        }
        
       
        return dp[n-1];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends