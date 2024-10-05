#include <bits/stdc++.h>
using namespace std;


void solve(){

    int n ;
        cin>>n;
        int arr[n];
        int max = 0;
        for (int i = 0; i < n; i++)
        {   
            cin>>arr[i];
            if(arr[i]>arr[max]){
                max = i;
            }
            
        }
        cout<<arr[max];



}

int main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}