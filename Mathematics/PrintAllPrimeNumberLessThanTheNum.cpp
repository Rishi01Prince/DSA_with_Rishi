#include <bits/stdc++.h>
using namespace std;


//Most Optimized and Efficient Sieve Algorith to find all Prime no. less than the Number
//Time Complexity = T(nloglogn)
void SieveAlgotoPrintallPrimeNo( int n ){
    vector<bool> isPrime(n+1,true);
    for (int i = 2; i <=n; i++)
    {
        if(isPrime[i]){
            cout<<i<<" ";
            for (int j = i*i; j <=n;j=j+i)
            {
                isPrime[j]  = false;
                //Here we are making all multiple of prime no as false
            }
        }

    }

}



int main() {
    int n;
    cin>>n;

    SieveAlgotoPrintallPrimeNo(  n );

    return 0;
}