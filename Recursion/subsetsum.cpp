#include <bits/stdc++.h>
using namespace std;


int sub(int arr[],int a ,int sum,int cursum,int count ){
    if(sum==0){
        return 1;
    }
    if(a == count){
        if(cursum == sum ){
         return 1;
        }
        else{
            return 0;
        }
    }
    int ans = sub(  arr , a , sum, cursum+arr[count],count+1)+ sub(  arr , a , sum, cursum,count+1);

    return ans;


}

int main() {
    int T;
    cin>>T;

    while(T--){
        int a;
        cin>>a;
        int arr[a];
        for (int i = 0; i < a; i++)
        {
            cin>>arr[i];
            
        }
        int sum;
        cin>>sum;
        
        cout<<sub(arr,a,sum,0,0);
    }
    return 0;
}