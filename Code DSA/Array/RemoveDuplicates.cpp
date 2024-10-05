#include <bits/stdc++.h>
using namespace std;


void solve(){

     int n ;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin>>arr[i];    
        }

        for (int i = 0; i < n; i++)
        {  
           if(i==0){
                cout<<arr[i]<<" ";
           }
           else if(arr[i]!=arr[i-1]){
                cout<<arr[i]<<" ";
           }
        }

}

int main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}