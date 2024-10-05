#include <bits/stdc++.h>
using namespace std;




void kill(int sum , int n , int k , int count , int fire){

    if(count == n-1){
        cout<<sum<<endl;
        return;
    }

    sum = sum - fire;

    kill(sum , n, k, count+1,  (fire+k)%(n-1));

    


}

int32_t main() {
    int T;
    cin>>T;

    while(T--){
        int n , k; 
        int sum =(n*(n+1))/2;
        kill (sum , n , k,0,k-1);
    }
    return 0;
}