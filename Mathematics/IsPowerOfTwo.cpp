#include <bits/stdc++.h>
using namespace std;

// To find no. of 1s or set bits
//theta(No. of 1 in bit form of no.)
bool Is_Pow_of_Two(int n)
{
    if(n == 0){
        return false; 
    }
    return (((n&(n-1))==0));
}

bool Is_Pow_of_Two_SatKat(int n)
{
    return (n!=0)&&((n&(n-1))==0);
}


int main()
{
    int n;
    cin >> n;
    bool x = Is_Pow_of_Two(n);
    cout<<x;
    cout<<endl;
    x=Is_Pow_of_Two_SatKat( n);
    cout<<x;
    return 0;
}