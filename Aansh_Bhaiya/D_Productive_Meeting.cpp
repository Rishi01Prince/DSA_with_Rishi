#include <bits/stdc++.h>
using namespace std;

// getline(cin, str);
// #define yes cout<<"YES"<<endl;
// #define no cout<<"NO"<<endl;
// #define int long long int
//  map<int,int> mpp;
// sort(v.begin(),v.end());
// to_string(n)
//   A= 65   Z= 90  a =97  z = 122
// Int to string                 ostringstream str1; str1 << num; string str = str1.str();
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
//  __builtin_popcount(n);
// binary_search(v.begin(), v.end(), x);

void solve()
{

    int n;
    cin >> n;
    vector<int> v(n);
    priority_queue<pair<int, int>> pq;
    // Min Priority Queue
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
         if(v[i]) pq.push({v[i], i + 1});
    }

    while (pq.size() > 1)
    {
        pair<int, int> x = pq.top();
        pq.pop();
        pair<int, int> y = pq.top();
        pq.pop();
        ans.push_back({x.second, y.second});
        
        x.first--;
        y.first--;
        if (x.first > 0)
            pq.push(x);
        if (y.first > 0)
            pq.push(y);
    }

    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
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

// 2 1 2