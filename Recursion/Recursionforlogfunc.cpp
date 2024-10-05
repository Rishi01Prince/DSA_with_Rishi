#include <bits/stdc++.h>
using namespace std;

int rec(int n, int b)
{

    if (n == 1)
    {
        return 0;
    }
    else
    {
        return (1 + rec(n / b,b));
    }
}

int main()
{
    int n, x;
    cout << "Please Enter the number and then after a space the base which you want to take : " << endl;
    cin >> n >> x;
    cout << rec(n, x);

    return 0;
}