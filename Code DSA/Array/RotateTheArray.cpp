#include <bits/stdc++.h>
using namespace std;


void solve(){

     int n ;
        cin>>n;
         int d ;
        cin>>d;
        int arr[n];
        for (int i = 0; i < n; i++)
        {   
            cin>>arr[i];
            
        }
        
       
        for (int i = 0; i < n; i++)
        {   
            if(arr[i]!=0){
                swap(arr[i],arr[(i+(n-d))%n]);
                // count++;
            }
            
        }

        //count = (i+(n-d))%n







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