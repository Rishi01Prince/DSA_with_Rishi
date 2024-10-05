#include <bits/stdc++.h>
using namespace std;

// Simple Recursion
int frogJump(int n, int k, vector<int> &heights)
{
    if (n == 0)
        return 0;
    int mi = INT_MAX;

    for (int i = i; i <= k; i++)
    {
        if (n - i > 0)
        {
            int x = frogJump(n - i, k, heights) + abs(heights[n] - heights[n - i]);
            mi = min(mi, x);
        }
    }
    return mi;
}

// Memonization Dp
//Time Complexity: O(N *K)
//Space Complexity: O(N)

int frogJump2(int n, int k, vector<int> &heights, vector<int> &dp)
{

    if (n == 0)
        return dp[0] = 0;
    int mi = INT_MAX;

    if (dp[n] != -1)
        return dp[n];

    for (int i = 1; i <= k; i++)
    {
        if (n - i > 0)
        {
            int x = frogJump2(n - i, k, heights, dp) + abs(heights[n] - heights[n - i]);
            mi = min(mi, x);
        }
    }
    return dp[n] = mi;
}

// Tabular

// Time Complexity: O(N*K)

// Reason: We are running two nested loops, where outer loops run from 1 to n-1 and the inner loop runs from 1 to K

// Space Complexity: O(N)
int frogJump3(int n,int k, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mi = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if(i-j>0){
                int jump = dp[i - k] + abs(heights[i - k] - heights[i]);
                mi = min(mi, jump);
            }
        }

        dp[i] = mi;
    }

    return dp[n - 1];
}

// Optimized Space Tabular
int frogJump4(int n, int k ,vector<int> &heights)
{
    return 0;

}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // cout << frogJump(n - 1,k, v) << endl;
        // vector<int> dp(n,k, -1);
        // cout << frogJump2(n - 1,k, v, dp) << endl;

        // cout << frogJump3(n ,k, v) << endl;
        cout << frogJump4(n, k, v) << endl;
    }

    return 0;
}
