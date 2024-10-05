#include <bits/stdc++.h>
using namespace std;

//Pure Recursion
int Fib_Recur(int n )
{
    if(n<=1) return n;

    return Fib_Recur(n-2)+Fib_Recur(n-1);

}

//Using Memonization

int fib_DP_Memo(vector<int>& dp,int n)
{
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = fib_DP_Memo(dp,n-1) +fib_DP_Memo(dp,n-2);
}


//Using Tabular Method
int DP_Tab(int n)
{
    vector<int> dp (n,-1);
    dp[0] = 0;
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

   
    int x = 0;
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

    //Fibonacci Series

    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout<<Fib_Recur(n)<<endl;
    cout<<fib_DP_Memo(dp,n)<<endl;;
    DP_Tab(n);
    Space_Optimized_DP_Tab(n);

    cout<<" " << endl;

    return 0;
}
