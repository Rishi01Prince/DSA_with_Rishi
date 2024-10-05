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


//std::vector<int>::iterator upper1, upper2;
//upper1 = std::upper_bound(v.begin(), v.end(), 35);
//upper2 = std::upper_bound(v.begin(), v.end(), 45);
 //std::cout  << (upper1 - v.begin());
//std::cout << (upper2 - v.begin());


int maxMeetings(int s[], int e[], int n)
{
    // Your code here
    vector<pair<int, int>> c;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        c.push_back({e[i], s[i]});
    }

    sort(c.begin(), c.end());
    if (c.size() > 0)
        ans++;
    int curr = c[0].first;

    for (int i = 1; i < n; i++)
    {
        if (c[i].second > curr)
        {
            ans++;
            curr = c[i].first;
        }
    }
    return ans;
}



void solve(){

    


}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}