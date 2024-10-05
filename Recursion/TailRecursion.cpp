#include <bits/stdc++.h>
using namespace std;

void rec(int n)
{

    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
    rec(n - 1);
}
void roc(int n)
{

    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }

    roc(n - 1);
    cout << n << " ";
}
// coverting roc into tail recursive
void ric(int n, int k)
{

    if (n == 0)
    {

        return;
        cout << k;
    }
    cout << k << " ";

    ric(n - 1, k + 1);
}

// non tail recursive factorial
int fac(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fac(n - 1);
}

// tail recursive factorial
int fic(int n, int k)
{
    
    if (n == 1 || n == 0)
    {
        return k;
    
    }
    
    return fic(n - 1,k*n);
    
}
//jo value change hoti ya koi aisi value jo har recursion me aap change kr rahe hai apne hisab se
//tb us value as a parameter pass kr dijiye recursion function me aur ho ske to usi value ko 
//termination condition me return kr dijiye


int main()
{
    int n;

    cin >> n;
    rec(n);
    cout << endl;
    roc(n);
    cout << endl;
    ric(n, 1);
    cout << endl;
    cout<<fac(n);
    cout <<"hmm" <<endl;
   cout<< fic(n,1);

    return 0;
}