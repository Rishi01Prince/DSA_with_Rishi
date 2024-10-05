#include <bits/stdc++.h>
using namespace std;


int sum(vector<int>& v  , int i , vector<int> &dp ){


    if(i<0) return -1;
    if(i == 0){
        return dp[0] = v[0];
    }
    if(i==1){
        return dp[1] =v[1];
    }

    if(dp[i] != -1) return dp[i];

    int l = 0;
    int r = 0;

     if(i-2>=0) l = sum(v  , i-2 , dp) + v[i] ;

     if(i-1>=0) r = sum(v ,i-1,dp );

   return dp[i] = max(l,r);

}





void solve(){

     int n ;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];
    }
    vector<int> dp(n+1 , -1 );
    int ans = sum(v , n-1, dp)  ;
    cout<<ans<<endl;


    


}

int32_t main() {
    
        solve();
    
    return 0;
}