#include <bits/stdc++.h>
using namespace std;




//#define yes cout<<"Yes"<<endl;
// #define no cout<<"No"<<endl;
//#define int long long int
// map<int,int> mpp;
//sort(v.begin(),v.end());
//  A= 65   Z= 90  a =97  z = 122
//Int to string                 ostringstream str1; string str = str1.str();  str1 << num;
 //  String to Integer int num = stoi(str);


// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);
int dp[1001][1001];
 
// Returns the length of the longest palindromic subsequence
// in seq

int lps(string& s1, string& s2, int n1, int n2)
{
    if (n1 == 0 || n2 == 0) {
        return 0;
    }

    if (dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
    
    if (s1[n1 - 1] == s2[n2 - 1]) {
        return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
    }
    else {
        return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2),   lps(s1, s2, n1, n2 - 1));
    }
}
 

int main()
{
    string seq = "GEEKSFORGEEKS";
    int n = seq.size();
    dp[n][n];
    memset(dp, -1, sizeof(dp));
    string s2 = seq;
    reverse(s2.begin(), s2.end());
    cout << "The length of the LPS is "
         << lps(s2, seq, n, n) << endl;
    return 0;
}
 