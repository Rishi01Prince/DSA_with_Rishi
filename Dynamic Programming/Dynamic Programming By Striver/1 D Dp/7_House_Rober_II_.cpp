#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int max_non_adj_sum(vector<int> &v , vector<int> &dp , int n ){
	    if(n==0){
	        return dp[0]=v[0];
	    }
	    if(n<0) return 0;
	    
	    if(dp[n]!=-1) return dp[n];
	    
	    int pick = v[n] + max_non_adj_sum(v , dp , n-2);
	    int non_pick = 0 + max_non_adj_sum(v , dp , n-1);
	    return dp[n] = max(pick , non_pick);
	}

    
    
    
	int Tabulation(vector<int> &v, int n) {
	    
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
	
  
   
    int rob(vector<int>& v) {
        int n = v.size();
        if(n==1) return v[0];
       
       
        vector<int> p;//vector without house 0
        vector<int> q;//vector without house 1
        for(int i = 0 ; i< n;i++){
              if(i!=0)  p.push_back(v[i]);
              if(i!=n-1) q.push_back(v[i]);
        }


        //Memonizatio Stuff
        // vector<int> dp(n+1 ,-1);
        // vector<int> dp2(n+1 ,-1);
        // return max(max_non_adj_sum(q, dp , n-2),max_non_adj_sum(p, dp2 , n-2));


        //Tabulation 
        return max(Tabulation(p, n-1) , Tabulation(q,n-1));
    
    }
};





int32_t main() {
    Solution ob;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }
    cout << ob.rob(v) << endl;
    return 0;
}