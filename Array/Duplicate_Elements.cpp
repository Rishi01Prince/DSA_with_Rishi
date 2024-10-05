#include <bits/stdc++.h>
using namespace std;

#define int long long int
// unordered_map<int,int> mpp;
// sort(v.begin(),v.end());

void solve()
{

     int n ;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];
    }


    int dup = -1, missing = 1;


    for (int n : v)
    {
        // cout<<v[abs(n) - 1]<<" ";
        if (v[abs(n) - 1] < 0)
            dup = abs(n);
        else
            v[abs(n) - 1] *= -1;
    }
    cout<<endl;

    cout<<"Hello"<<" "<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    


    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            missing = i + 1;
    }


    cout<<endl;
    cout << dup <<" "<<missing<< endl;
    cout<<endl;
}

int32_t main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}