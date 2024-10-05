//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//Link : https://practice.geeksforgeeks.org/problems/minimum-energy1821/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&problemStatus=unsolved&difficulty[]=0&page=1&sortBy=submissions&query=category[]Dynamic%20ProgrammingproblemStatusunsolveddifficulty[]0page1sortBysubmissionscategory[]Dynamic%20Programming#


// } Driver Code Ends
class Solution {
  public:
  
  
    int Memo(vector<int>& v , vector<int> &dp , int n  ){
        
        if(n==0) return dp[0] = 0;
        if(n==1) return dp[1] = abs(v[1]-v[0]);
        if(dp[n] != -1) return dp[n];
        
        int step1 = 1e8 , step2 = 1e8 ; 
        if(n-1>=0) step1 = abs(v[n]- v[n-1]) + Memo(v, dp ,n-1) ;
        if(n-2>=0) step2 = abs(v[n]- v[n-2]) + Memo(v, dp ,n-2) ;
        
        return dp[n]  = min( step1 , step2); 
    }
    
    int minimumEnergy(vector<int>& v, int n) {
        
        
        //Memonization Stuff
        //int ans = INT_MAX;
        // vector<int> dp(n , -1);
        // ans = Memo(v, dp ,n-1);
        
        
        //Tabulation Starts
        if(n==1) return 0;
        vector<int> dp(n+1,0);
       
        dp[1] = abs(v[1] - v[0]);
        
        for(int i = 2 ; i<n ;i++){
            int step1 = abs(v[i] - v[i-1]) + dp[i-1];
            int step2 = abs(v[i] - v[i-2]) + dp[i-2];
            dp[i] = min(step1 , step2);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
