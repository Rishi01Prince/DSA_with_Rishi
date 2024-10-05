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

// std::vector<int>::iterator upper1, upper2;
// upper1 = std::upper_bound(v.begin(), v.end(), 35);
// upper2 = std::upper_bound(v.begin(), v.end(), 45);
// std::cout  << (upper1 - v.begin());
// std::cout << (upper2 - v.begin());

void solve()
{

    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pq.push(v[i]);
    }

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans =a+b;
    }

    cout<<ans<<endl;
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