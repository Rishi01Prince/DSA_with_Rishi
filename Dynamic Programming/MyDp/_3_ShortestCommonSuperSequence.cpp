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


int superSeq(string X, string Y, int n, int m,vector<vector<int> > lookup)
{
 
    if (m == 0 || n == 0) {
        lookup[n][m] = n + m;
    }

 
    if (lookup[n][m] == 0)
        if (X[n - 1] == Y[m - 1]) {
            lookup[n][m] = superSeq(X, Y, n - 1, m - 1, lookup) + 1;
        }
 
        else {
            lookup[n][m] = min(superSeq(X, Y, n - 1, m, lookup) + 1,superSeq(X, Y, n, m - 1, lookup) + 1);
        }
    
                           
    return lookup[n][m];
}



int32_t main() {
    int T;
    cin>>T;

   
    return 0;
}