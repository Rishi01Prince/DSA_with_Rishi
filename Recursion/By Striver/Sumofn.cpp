#include <bits/stdc++.h>
using namespace std;




//#define int long long int
 // unordered_map<int,int> mpp;
  //sort(v.begin(),v.end());


int solve1(int n){
    if(n==0){
        return 0 ;
    }

    return n + solve1(n-1);

}

int solve2(int n,int i){
    if(i==n){
        return i;
    }
     return i + solve2(n,i+1);


}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        int n;cin>>n;
       cout<< solve1(n)<<endl;
       cout<< solve2(n,1)<<endl;
    }
    return 0;
}