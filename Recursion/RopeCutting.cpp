#include <bits/stdc++.h>
using namespace std;

//O(3^n)
int rope(int n,int a ,int b ,int c){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1;
    }
    int res = max(rope(n-a,a,b,c),max(rope(n-b,a,b,c),rope(n-c,a,b,c)));

    if(res==-1){
        return -1;
    }


    return res+1;
    


}

int main() {
    int T;
    cin>>T;

    while(T--){
        int n, a , b ,c;
        cin>>n>>a>>b>>c;
        cout<<rope(n,a,b,c);
    }
    return 0;
}