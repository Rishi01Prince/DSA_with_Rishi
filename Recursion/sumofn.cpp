#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{

    if (n == 1)
    {
        return 1;
    }
    return n+sum(n-1);
}

//Tail Rec
int sum(int n,int k)
{

    if (n == 1)
    {
        return k;
    }
    return sum(n-1,k+n);
}


int main()
{
    int n;

    cin >> n;

   cout<< sum(n);
   cout<<endl;
   cout<<sum(n,1);

    return 0;
}