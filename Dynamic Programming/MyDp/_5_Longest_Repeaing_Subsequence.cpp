#include <bits/stdc++.h>
using namespace std;

//#define yes cout<<"Yes"<<endl;
// #define no cout<<"No"<<endl;
//#define int long long int
// map<int,int> mpp;
// sort(v.begin(),v.end());
//  A= 65   Z= 90  a =97  z = 122
// Int to string                 ostringstream str1; string str = str1.str();  str1 << num;
//  String to Integer int num = stoi(str);

// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);

int lrs(string s1, int i, int j, vector<vector<int>> &dp)
{

    // return if we have reached the
    // end of either string
    if (i >= s1.length() || j >= s1.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // while dp[i][j] is not computed earlier
    if (dp[i][j] == -1)
    {

        // if characters at index m and n matches
        // and index is different
        // Index should not match

        if (s1[i] == s1[j] && i != j)
            dp[i][j] = 1 + lrs(s1, i + 1, j + 1, dp);

        else
            dp[i][j] = max(lrs(s1, i, j + 1, dp), lrs(s1, i + 1, j, dp));
    }

    return dp[i][j];
}

// Driver Code
int main()
{

    string s1 = "aabb";

    // Reversing the same string
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(1000, vector<int>(1000, -1));
    cout << "LENGTH OF LONGEST REPEATING SUBSEQUENCE IS : " << lrs(s1, 0, 0, dp);
}