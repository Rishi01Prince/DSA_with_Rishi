#include <bits/stdc++.h>
using namespace std;

//#define yes cout<<"Yes"<<endl;
// #define no cout<<"No"<<endl;
// #define int long long int
// map<int,int> mpp;
// sort(v.begin(),v.end());
//  A= 65   Z= 90  a =97  z = 122
// Int to string                 ostringstream str1; string str = str1.str();  str1 << num;
//  String to Integer int num = stoi(str);

// Unique for vector
// vector<int>::iterator ip;ip = std::unique(v.begin(), v.end ());v.resize(std::distance(v.begin(), ip));
// Unique for string
// auto ip = unique(s.begin(), s.end());string un = string(s.begin(), ip);

// bool mycmp(pair<int, int> a, pair<int, int> b)
// {
//     return a.second < b.second;
// }

int maxTask(vector<pair<int, int>> &c, int n)
{

    int ans = 0;

    sort(c.begin(), c.end());

    // pair<int, int> curr;
    // curr.first = c[0].first;
    // curr.second = c[1].second;
    int curr = c[0].second;
    for (int i = 1; i < n; i++){
        if (c[i].first)
        {
            ans++;
            curr = min(curr, c[i].second);
        }
        else
        {
            curr = c[i].second;
        }
    }

    return ans;
}

int32_t main()
{
    int T;
    T = 1;
    // cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> c;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            c.push_back({b, a});
        }

        int ans = maxTask(c, n);

        cout << (ans - 1) << endl;
    }
    return 0;
}
