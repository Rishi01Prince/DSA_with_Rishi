#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<long> lucky(vector<int> &v)
{
    int n = v.size();
    vector<long> ans(n);
    long long m = 1000000007;

     int ma = -1;
    for (int i = 0; i < n; i++)
    {
        ma = max(ma, v[i]);
    }

    vector<long> l(ma + 1, 1);

   

    for (int i = 2; i <= ma; i++)
    {
        l[i] = (((l[i - 1] * i) / gcd(l[i - 1], i)) % m);
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = l[v[i]];
    }


     for (int i = 0; i <=ma; i++)
    {
        cout<<l[i]<<" ";
    }
    

    return ans;
}

int32_t main()
{

    int n ;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
   { 
       cin>>v[i];
   }

    vector<long> ans = lucky(v);

    // for(auto it  : ans) cout<<it<<" ";

    return 0;
}