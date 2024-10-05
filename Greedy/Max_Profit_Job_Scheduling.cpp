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



vector<int> JobScheduling(vector<vector<int>> v, int n){

    vector<pair<int, int>> c;
    int count = 0;
    int sum = 0 ;
    int ma = INT_MIN;

    // v[i][1] = deadline;
    // v[i][0] = profit;

    for (int i = 0; i < n; i++){
        // cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<endl;
        c.push_back({v[i][0], v[i][1]});
        ma = max(ma, v[i][1]);
    }

    sort(c.begin(), c.end(), greater<pair<int, int>>());
    
    vector<int> ans(ma + 1, 0);
    for (int i = 0; i < n; i++)
    {

        if (ans[c[i].second] == 0)
        {
            ans[c[i].second] = c[i].first;
            sum += c[i].first;
            count++;
        }
        else
        {
            for (int j = c[i].second; j >= 1; j--)
            {
                if (ans[j] == 0)
                {
                    ans[j] = c[i].first;
                    count++;
                    sum += c[i].first;
                    break;
                }
            }
        }
    }

    // for(int i=0;i<n;i++ ) {
    //     cout<<i<<" "<<ans[i]<<endl;
    // }

    vector<int> ans2(2, 0);
    ans2[0] = count;
    ans2[1] = sum;
    return ans2;

}

void solve()
{

     int n ;
     cin>>n;
     vector<vector<int>> v(n, vector<int> (2,0));
     for (int i = 0; i < n; i++)
    { 
        cin>>v[i][0];
        cin>>v[i][1];
    }

    vector<int> ans =  JobScheduling(v,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    
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