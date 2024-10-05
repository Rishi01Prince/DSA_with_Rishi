//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Link to the problem: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    
    int Memo(int v[] , vector<int> &dp , int n ){
        if(n<0) return -1e9;
        if(n==0) return dp[0] = v[0];
        if(n==1) return dp[1] = max(v[1] , v[0] );
        if(dp[n] != -1) return dp[n];
        
        int take = v[n] + Memo(v , dp , n-2);
        int nontake = Memo(v ,dp , n-1);
        return dp[n]  = max(take , nontake); 
    }
    
    
	int Tabulation(int v[], int n) {
	    
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
	
    int FindMaxSum(int v[], int n)
    {
        
        //Memonization Stuff
        // int ans = 0;
        // vector<int> dp(n , -1);
        // ans = Memo(v, dp ,n-1);
       
        
        
        return Tabulation(v , n) ;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends