#include <bits/stdc++.h>
using namespace std;

// Simple Recursion
int frogJump(int n, vector<int> &heights)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return abs(heights[1] - heights[0]);

    int left = frogJump(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int right = frogJump(n - 2, heights) + abs(heights[n] - heights[n - 2]);

    return min(left, right);
}


// Memonization Dp

int frogJump2(int n, vector<int> &heights, vector<int> &dp)
{

    if (n == 0)
        return dp[0] = 0;
    if (n == 1)
        return dp[1] = abs(heights[1] - heights[0]);

    if (dp[n] != -1)
        return dp[n];

    int left = frogJump2(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = frogJump2(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);

    return dp[n]=min(left, right);
}

//Tabular 
int frogJump3(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1]= abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        int left =  dp[i-1]+abs(heights[i-1] - heights[i]);
        int right =dp[i-2] +abs(heights[i-2] - heights[i]);
        dp[i]=min(left, right);
    }
  
    return dp[n-1];
}


// Optimized Space Tabular 
int frogJump4(int n, vector<int> &heights)
{
    // dp[i-1] =y;
    // dp[i-2]  =x

    int x = 0;   // x y curr
    int y = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++)
    {
        int left =  y + abs(heights[i-1] - heights[i]);
        int right = x + abs(heights[i-2] - heights[i]);
        int curr = min(left, right);
        x = y;
        y = curr;
  
    }  
    return y;
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {

        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // cout << frogJump(n - 1, v) << endl;
        // vector<int> dp(n, -1);
        // cout << frogJump2(n - 1, v, dp) << endl;

        // cout << frogJump3(n , v) << endl;
        cout << frogJump4(n , v) << endl;
    }

    return 0;
}
