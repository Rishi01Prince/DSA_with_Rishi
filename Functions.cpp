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




//Most Optimized //isPrime check a no

vector<int> MostEfficientApproachPrimeFactors(int num)
{
    vector<int> v;
    if (num <= 1)
    {
        return v;
    }
    if (num % 2 == 0)
    {
        while (num % 2 == 0)
        {
            // cout<<2 <<" ";
            v.push_back(2);
            num = num / 2;
        }
    }
    if (num % 3 == 0)
    {
        while (num % 3 == 0)
        {
            // cout<<3<<" ";
            v.push_back(3);
            num = num / 3;
        }
    }


    for (int i = 5; i * i <= num; i = i + 6)
    {

        while (num % i == 0)
        {
            // cout<<i<<" ";
            v.push_back(i);
            num = num / i;
        }

        while ((num % (i + 2)) == 0)
        {
            // cout<<temp<<" ";
            v.push_back(i+2);
            num = num / (i+2);
        }
    }

    if (num > 3)
    {
        // cout<<num;
        v.push_back(num);
    }
    return v;
}


//Most Efficient Iterativeway of Power where you can do it in 1 Auxilary Space
//First we make n into binary and multiply all ones plcace with x itself

int MostEfficientPower( int x ,int n ){
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

//In theta(1) if ones are precomputed 

int countBits(int n,int *arr){
   

     int count = arr[n&0xff];  //0xff means last 8 bits of binary all 1 or we can say 
                                //that it is in hexadecimal form
     n = n>>8;


     count = count + arr[n&0xff]; 
     n = n>>8;
      count = count + arr[n&0xff]; 
     n = n>>8;
    count = count + arr[n&0xff]; 
     
     return count;

     //Keep this in main:
     //using count bits in theta(1) we must intialize a array of size 256 first

    // int arr[256];
    // arr[0] = 0;
    // for (int i = 1; i < 256; i++)
    // {
    //     arr[i] = (i&1) + arr[i/2];
    // }
    
    // int ans2 = countBits( n, arr);
    // cout<< ans2;




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

//Most Optimized 

int OptimizedEuclideanforGCD(int a ,int b){
    if(b==0){
        return a;
    }
    else{
        return OptimizedEuclideanforGCD(b,a%b) ;
    }
}


// To find no. of 1s or set bits
//theta(No. of 1 in bit form of no.)
bool Is_Pow_of_Two(int n)
{
    if(n == 0){
        return false; 
    }
    return (((n&(n-1))==0));
}


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



long long maxPrime(long long n)
{
    long long int mp = -1;

    while (n % 2 == 0) {
        mp = 2;
        n= n/2;
    }

     while (n % 3 == 0) {
        mp = 3;
        n=n/3;
    }
 
   
    for (int i = 5; i*i <= n; i += 6) {
        while (n % i == 0) {
            mp = i;
            n = n / i;
        }
        while (n % (i+2) == 0) {
            mp= i+2;
            n = n / (i+2);
        }
    }
 
    if (n > 4)
        mp = n;
 
    return mp;
}


//Please Use This

void MostEfficientApproachPrimeFactors(int num){

    if(num<=1){
        return;
    }
    if(num%2==0){
        while(num%2==0){
            cout<<2 <<" ";
            num=num/2;
        }
    }
    if(num%3==0){
        while(num%3==0){
            cout<<3<<" ";
            num=num/3;
        }
    }
    

    for (int i = 5; i*i < num; i=i+6)
    {
       if(MostEfficientwayforPrime(i)){
        
         while(num%i==0){
            cout<<i<<" ";
            num = num/i;
         }
         int temp = i+2;

         while(num%temp==0){
            cout<<temp<<" ";
            num = num/temp;
         }
       }
    }

    if(num>3){
        cout<<num;
    }
    
}



 
void solve(){

    


}

int main() {
    int T;
    cin>>T;

    while(T--){
        solve();
    }
    return 0;
}