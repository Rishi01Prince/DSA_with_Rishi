#include <bits/stdc++.h>
using namespace std;
//    https://leetcode.com/problems/climbing-stairs/


// Time Complexity : O(n)
//Space Complexity : O(n)
//Auxilary Space : O(n)
int Climb_ways(int n,vector<int>&dp )
{
    if(n<0){
        return 0;
    }
    if(n==0){
        return dp[n] = 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }


    int path1 = Climb_ways(n-1,dp);
    int path2 = Climb_ways(n-2,dp);
    return dp[n] =path1+path2;


}


// Time Complexity : O(n)
//Space Complexity : O(n)
//Auxilary Space : O(1)

int Climb_Tabulation(int n ){
    vector<int> dp(n+1,-1);
    dp[0] = 1 ; dp[1]=1;
    for (int i = 2; i <= n; i++)
    {
        dp[n] = dp[n-1] +dp[n-2];
    }
    

    return dp[n];


}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1 , -1);
   
   cout<< Climb_ways(n,dp);
    return 0;
}