#include <bits/stdc++.h>
using namespace std;




//#define int long long int
 // unordered_map<int,int> mpp;
  //sort(v.begin(),v.end());


void solve(){
     int n ;
     cin>>n;
     vector<int> v(n);
     map<int,int> mpp;

     for (int i = 0; i < n; i++)
    { 
        cin>>v[i];
        mpp[v[i]]++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";

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