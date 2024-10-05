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

// 1 2 3       5  7  8  9

// 4  6  = 24
void solve()
{

    int n;
    cin >> n;
    if (n <= 3)
    {
        cout << "NO" << endl;
    }
    else if (n == 4)
    {
        cout << "YES" << endl;
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    }
    else if (n == 5)
    {
        cout << "YES" << endl;
        cout << "3 - 1 = 2" << endl;
        cout << "2 + 2 = 4" << endl;
        cout << "5 * 4 = 20" << endl;
        cout << "20 + 4 = 24" << endl;
    }
    else if (n % 2 == 0)
    {
        cout << "YES" << endl;
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
        int count = 0;

        for (int i = n; i >= 6; i-=2)
        {
            count++;
            cout << i << " - " << (i - 1) << " = 1"<<endl;
        }
        while(count--){
            cout <<"1 * 24 = 24"<<endl;
        }

         
    }
    else if (n % 2 != 0)
    {
        cout << "YES" << endl;
        cout << "3 - 1 = 2 " << endl;
        cout << "2 + 2 = 4 " << endl;
        cout << "5 * 4 = 20 " << endl;
        cout << "20 + 4 = 24 " << endl;
        int count = 0;
        for (int i = n; i >= 6; i-=2)
        {
            count++;
            cout << i << " - " << (i - 1) << " = 1"<<endl;
        }

        while(count--){
            cout <<"1 * 24 = 24"<<endl;
        }
    }
}

    int32_t main()
    {

        solve();

        return 0;
    }