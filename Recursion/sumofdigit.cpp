#include <bits/stdc++.h>
using namespace std;

int dsum(int n)
{
    if (n < 10)
    {
        return n;
    }
    return (n % 10) + dsum(n / 10);
}

//tail rec
int dsum(int n,int k)
{

    if (n < 10)
    {
        return k+n;
    }

    return  dsum(n / 10,k+n%10);
}


int main()
{
    int T;
    cin >> T;
    cout << dsum(T);
    cout<<endl;
    cout<<dsum(T,0);
    return 0;
}