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


bool mycmp(int a ,int b){
    return a>b;
}

void solve(){

     int n ;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];
    }
    sort(v.begin() , v.end() ,mycmp);

    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<< " ";
    }
    cout<<endl;
    

    


}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}