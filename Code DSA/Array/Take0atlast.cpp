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
        int count =0;
        for (int i = 0; i < n; i++)
        {   
            if(arr[i]!=0){
                swap(arr[i],arr[count]);
                count++;
            }
            
        }

        for (int i = 0; i < n; i++)
        {   
            cout<<arr[i]<<" ";  
        }
        cout<<endl;
}

int main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}