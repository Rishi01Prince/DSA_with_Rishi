#include <bits/stdc++.h>
using namespace std;




//#define int long long int
 // unordered_map<int,int> mpp;
  //sort(v.begin(),v.end());


int fibo(int n){

    if(n==0 ) return 0;
    else if(n==1 || n==2) return 1;
    else return fibo(n-2) +fibo(n-1);

}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        int n ; cin>>n;
        cout<< fibo(n)<<endl;
    }
    return 0;
}