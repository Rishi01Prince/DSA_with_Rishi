#include <bits/stdc++.h>
using namespace std;




int lcs(string X, string Y, int m, int n,vector<vector<int> >& dp)
{
    if (m == 0 || n == 0)
        return X[m] == Y[n];

    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
  
    if (dp[m][n] != -1) {
        return dp[m][n];
    }

    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),lcs(X, Y, m - 1, n, dp));
}



int32_t main() {
    int T;
    cin>>T;

    return 0;
}