#include <bits/stdc++.h>
using namespace std;

//Pure Recursion
int Recursion(int n)
{
    if(n==0 || n==1) return 1;
    int left =  Recursion(n-1);
    int right  = Recursion(n-2);

    return left + right ;
}
//Using Memonization

int DP_Memo(vector<int>& dp,int n)
{
    if(n<=1) return 1;

    if( dp[n] != -1 ) return dp[n];

    return dp[n] = DP_Memo(dp,n-1) + DP_Memo(dp,n-2);
}



//Using Tabular Method
int DP_Tab(int n)
{
    vector<int> dp (n,-1);
    dp[0] = 1;
    dp[1] = 1;


    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
   
    return dp[n-1];


}


//Using Tabular Method and with reduced Space Complexity
int   Space_Optimized_DP_Tab(int n)
{

   
    int x = 1;
    int y = 1;


    for (int i = 2; i < n ; i++)
    {
       int curr = x+y;
       x=y;
       y=curr;
    }
   
    return y;


}

int32_t main()
{

    int n;
    cin >> n;
    vector<int> dp;
  

    Recursion(n);
    DP_Memo(dp,n);
    DP_Tab(n);
    Space_Optimized_DP_Tab(n);

    cout<<" " << endl;

    return 0;
}