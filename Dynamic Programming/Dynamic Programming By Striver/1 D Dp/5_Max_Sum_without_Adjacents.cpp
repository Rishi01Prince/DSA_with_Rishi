//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int Memo(int *v , vector<int> &dp , int n ){
        if(n<0) return -1e9;
        if(n==0) return dp[0] = v[0];
        if(n==1) return dp[1] = max(v[1] , v[0] );
        if(dp[n] != -1) return dp[n];
        int take = v[n] + Memo(v , dp , n-2);
        int nontake = Memo(v ,dp , n-1);
        return dp[n]  = max(take , nontake); 
    }

	int findMaxSum(int *v, int n) {
	    //Memonization Stuff
        // int ans = 0;
        // vector<int> dp(n , -1);
        // ans = Memo(v, dp ,n-1 );
        // Tabulation Starts
        if(n==1) return v[0];
        vector<int> dp(n,0);
        dp[0] = v[0];
        dp[1] = max(v[1], v[0]);
        
        for(int i = 2 ; i<n ;i++){
            int take = v[i] + dp[i-2];
            int nontake = dp[i-1];
            dp[i] = max(take , nontake);
        }
        return  dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends