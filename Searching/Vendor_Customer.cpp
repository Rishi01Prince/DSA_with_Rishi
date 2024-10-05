#include <bits/stdc++.h>
using namespace std;

// getline(cin, str);
//#define yes cout<<"Yes"<<endl;
//  #define no cout<<"No"<<endl;
//#define int long long int
//  map<int,int> mpp;
// sort(v.begin(),v.end());
//   A= 65   Z= 90  a =97  z = 122
// Int to string                 ostringstream str1; string str = str1.str();  str1 << num;
//   String to Integer int num = stoi(str);

// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);

// std::vector<int>::iterator upper1, upper2;
// upper1 = std::upper_bound(v.begin(), v.end(), 35);
// upper2 = std::upper_bound(v.begin(), v.end(), 45);
// std::cout  << (upper1 - v.begin());
// std::cout << (upper2 - v.begin());

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int x = c[i];

        auto up = upper_bound(v.begin(), v.end(), x);
        // right distance
        int d1 = 1e9 + 10;

        if (up != v.end())
        {
            d1 = *up - x;
        }

        int d2 = 1e9 + 10;

        if (up != v.begin())
        {
            up--;
            d2 = x - *up;
        }


        if(d2 == 0){
            ans.push_back({0,0});
        }
        else if( d1>d2){
            ans.push_back({d2,-1});
        }
        else if( d2 < d1){
            ans.push_back({d1,1});

        }

    }

    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int32_t main()
{
    int T;
    // cin>>T;
    T = 1;

    while (T--)
    {
        solve();
    }
    return 0;
}