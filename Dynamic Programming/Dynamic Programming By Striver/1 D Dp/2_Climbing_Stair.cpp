
#include <bits/stdc++.h>
using namespace std;

// 3. Min Cost Climbing Stairs
// Link : https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};



int32_t main() {
   Solution ob;
    int n;
    cin >> n;
    cout << ob.climbStairs(n) << endl;
    
    return 0;
}