#include <bits/stdc++.h>
using namespace std;


void solve(){

    int n ;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {   
            cin>>arr[i];
            
        }

        int low =0;
        int high =n-1;
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;   
        }

        for (int i = 0; i < n; i++)
        {   cout<<arr[i]<< " ";
            
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