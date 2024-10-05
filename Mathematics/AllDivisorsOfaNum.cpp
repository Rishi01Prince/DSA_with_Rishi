#include <bits/stdc++.h>
using namespace std;

void PrintAllDivisors( int n ){
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            cout<<i<<" ";
            if(i!=n/i){
                cout<<n/i<<" ";
            }
        }
    }
    cout<<endl;

}

void PrintAllDivisorsInIncreasingOrder( int n ){
    int i ;
    for ( i = 1 ; i*i < n; i++)
    {
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    for (; i >=1; i--)
    {
        if(n%i==0){
            cout<<n/i<<" " ;
        }
    }
    cout<<endl;
    

}


int main() {
    int n;
    cin>>n;

    PrintAllDivisors(n);
    PrintAllDivisorsInIncreasingOrder( n );

    return 0;
}

