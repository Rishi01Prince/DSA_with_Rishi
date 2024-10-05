#include <bits/stdc++.h>
using namespace std;


//Most Optimized 
bool isPrime(int a){
    if(a==1){
        return false;
    }
     if(a==2 || a == 3){
        return true;
    }
    if(a%2==0 || a%3 == 0){
        return false;
    }

    for (int i = 5; i*i <= a; i=i+6)
    {
        if(a%i==0 || a%(i+2)==0){
            return false;
        }
    }
     return true ;   
}

void NaiveApproachPrimeFactors(int num){
    for (int i = 0; i < num; i++)
    {
       if(isPrime(i)){
            int temp = i;
         while(num%temp==0){
            cout<<i<<" ";
            temp=temp*i;
         }
       }
    }
    
}

void MoreEfficientApproachPrimeFactors(int num){
    if(num<=1){
        return;
    }

    for (int i = 2; i*i < num; i++)
    {
       if(isPrime(i)){
            int temp = i;
         while(num%temp==0){
            cout<<i<<" ";
            num = num/temp;
         }
       }
    }
    if(num>1){
        cout<<num;
    }
}
    
//Most Optimized
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
       if(isPrime(i)){
        
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


int main() {

    int num1;
    cin >> num1;

    NaiveApproachPrimeFactors(num1);  
    cout<<endl;
    MoreEfficientApproachPrimeFactors(num1);  
    cout<<endl;
    MostEfficientApproachPrimeFactors(num1);  



    return 0;
}