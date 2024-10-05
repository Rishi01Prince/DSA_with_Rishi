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

#define pb push_back

void solve()
{
    int n, m;
    cin >> n;
    vector<int> vendors(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vendors[i];
    }

    cin >> m;
    vector<int> customers(m);
    for (int i = 0; i < m; i++)
    {
        cin >> customers[i];
    }

    sort(vendors.begin(), vendors.end());

    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++)
    {
        auto ub = upper_bound(vendors.begin(), vendors.end(), customers[i]);
        int dist1 = 1e9 + 10; // r

        if (ub != vendors.end())
        {
            dist1 = *ub - customers[i];
        }


        int dist2 = 1e9 + 10; // l
        if (ub != vendors.begin())
        {
            ub--;
            dist2 = customers[i] - *ub;
        }
        if (dist2 == 0)
        {
            ans.pb({0, 0});
            continue;
        }



        if (dist1 < dist2)
        {
            ans.pb({dist1, 1});
        }
        else
        {
            ans.pb({dist2, -1});
        }
    }

    for (auto it : ans)
    {
        cout << it.first << ' ' << it.second << endl;
    }
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