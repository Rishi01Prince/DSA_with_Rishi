#include <bits/stdc++.h>
using namespace std;
//    https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Time Complexity : O(n)
// Space Complexity : O(n)
// Auxilary Space : O(n)
int Frog_Jump(vector<int> v, vector<int> &dp, int n, int k)
{

    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int ans = INT_MAX;
    int path = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0){
            path = Frog_Jump(v, dp, n - i, k) + abs(v[n] - v[n - i]);
        }
        ans = min(ans, path);
    }

        return dp[n] = ans;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
// Auxilary Space : O(1)

int Frog_Jump_Tabulation(vector<int> v, int n)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++)
    {
        int x1 = dp[i - 1] + abs(v[i] - v[i - 1]);
        int x2 = dp[i - 2] + abs(v[i] - v[i - 2]);
        dp[i] = min(x1, x2);
    }
    return dp[n - 1];
}

int32_t main()
{
    int t=1;
    // cin >> t;
    while (t)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> dp(n + 1, -1);

        cout << Frog_Jump(v, dp, n - 1, k) << endl;
        // cout << Frog_Jump_Tabulation(v, n, k) << endl;
        t--;
    }

    return 0;
}