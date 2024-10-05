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

struct Item
{
    int weight;
    int value;
};

bool mycmp(pair<int, int> a, pair<int, int> b)
{

    double x = ((double)a.second) / a.first;
    double y = ((double)b.second) / b.first;

    return x > y;
}
// Function to get the maximum total value in the knapsack.

double fractionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<int, int>> v;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i].weight, arr[i].value});
    }

    sort(v.begin(), v.end(), mycmp);
    // for(int i = 0 ; i<n;i++){
    //     cout<<v[i].first<<" "<<v[i].second<<"   ";
    // }
    for (int i = 0; i < n; i++)
    {
        if (W >= v[i].first)
        {
            ans += v[i].second;
            W = W - v[i].first;
        }
        else
        {
            double x = ((double)v[i].second) / v[i].first;
            ans += ((double)W) * x;
            break;
        }
    }

    return ans;
}

int32_t main()
{
    int T;
    cin >> T;
    return 0;
}