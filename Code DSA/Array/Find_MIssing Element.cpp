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


// finding missing element in array starting from 1
// Test Case: {1,3,2,5}
// O/p: 4


// Approach : I) Find max number i.e. 5, II) now take xor from 1 to maxNumber III) Take xor with the array this time. IV) we will get unique element.



void solve(){

     int n ;
     cin>>n;
     vector<int> v(n);
     int ma =INT_MIN;
     int my_xor = 0;
     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];
        ma = max(ma,v[i]);
        my_xor =v[i]^my_xor;
    }
    // if(n!=ma){
    //     cout<<n<<endl;
    //     return;
    // }

    for (int i = 1; i <= ma; i++)
    {
        my_xor=i^my_xor;
    }

    cout<<my_xor<<endl;
    








}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}