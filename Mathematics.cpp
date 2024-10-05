#include <bits/stdc++.h>
using namespace std;


//My GCD
//O(log(min(a, b))
int mygcd(int a ,int b){
    if(b==0){
        return a;
    }
    else{
        return mygcd(b,a%b) ;
    }
}


//To Learn
//Checks A no is Prime Or Not
//O(Root n)

bool isPrime_my(int n ){
    if(n==1) return false;

    for (int i = 2; i*i <=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

//Print All Prime Factors of a number
//For Prime Numbers --> Theta(suatre_root (n))
//Usually It takes less time

vector<int> allPrimeFactor_my(int n ){
    vector<int> p;
    if(n<=1) return p;

    for (int i = 2; i*i <= n; i++){

        while (n%i==0){
            p.push_back(i);
            n = n / i ;
        }  
    }

    //for prime no. remaining
    if(n>1){
        p.push_back(n);
    }
    
}




//To Learn
//Checks A no is Prime Or Not
//O(Root n)

bool isPrime_(int a){
    if(a==1){
        return false;
    }
     if(a==2 || a == 3){
        return true;
    }
    if(a%2==0 || a%3 == 0){
        return false;
    }

    for(int i = 5; i*i <= a; i=i+6){
        if(a%i==0 || a%(i+2)==0)
            return false;
    }
    
    return true;
    
}

//Print All Prime Factors of a number
//For Prime Numbers --> Theta(suatre_root (n))
//Usually It takes less time

vector<int> allPrimeFactor(int n ){
    vector<int> p;
    if(n<=1) return p;
    while (n%2==0)
    {
        p.push_back(2);
        n=n/2;
    }
    while (n%3==0){
        p.push_back(3);
        n=n/3;
    }
    
    for (int i = 5; i*i <= n; i+=6){
        while (n%i==0)
        {
            p.push_back(i);
            n=n/i;
        }
        while (n%(i+2)==0)
        {
             p.push_back(i+2);
            n=n/(i+2);
        }
    }

    //For Prime no. Remaining
    if(n>3){
        p.push_back(n);
    }
    
}


map<int, int> allPrimeFactor(int n)
{
    map<int, int> mpp;
    if (n <= 1)
        return mpp;
    while (n % 2 == 0)
    {
        mpp[2]++;
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        mpp[3]++;
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            mpp[i]++;
            ;
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            mpp[i + 2]++;
            n = n / (i + 2);
        }
    }

    // For Prime no. Remaining
    if (n > 3)
    {
        mpp[n]++;
    }
    return mpp;
}




//Print All Divisor
//O( root(n))
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


//Print All Divisor in Increasing Order
//O( root(n))
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


void PrintAllDivisorsInIncreasingOrder( int n ){
    vector<int> v;
    int i ;
    for ( i = 1 ; i*i < n; i++)
    {
        if(n%i==0){
            v.push_back(i);
        }
    }
    for (; i >=1; i--)
    {
        if(n%i==0){
            v.push_back(n/i);
        }
    }
    

}






//Highest Prime Number 

const int N = 1e5 + 1000;
vector<bool> isPrime(N+1, true);
vector<int> HighP(N, 0);

void Sieve_for_HighestPrime_Factor() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            HighP[i] = i;

            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
                HighP[j] = i;
            }
        }
    }
}



//O(nloglogn)
void Sieve(int n){

    vector<bool> isPrime(n+1,true);

    for (int i = 2; i*i <= n; i++)
    {
        if(isPrime[i]){
            for (int j = i*i; j <=n ; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }  
}



//Most Efficient Iterativeway of Power where you can do it in 1 Auxilary Space
//First we make n into binary and multiply all ones plcace with x itself
//O(logn)
int myPower( int x ,int n ){
    int ans = 1;
    while (n>0)
    {
        if(n&1 == 1){
            ans = ans * x;
        }
        n=n>>1;
        x=x*x; 
    }
    return ans;
    
}



// Works for Prime Number
int NoofPowercanhaveofX(int num, int X)
{
  int Power = 0;
  for (int i = X; i <= num; i = i * X)
  {
    Power = Power + (num / i);
  }
  return Power;
}
 



int32_t main() {
    int T;
    return 0;
}