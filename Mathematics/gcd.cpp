#include <bits/stdc++.h>
using namespace std;


//Time :   O(min(a,b))
int NaiveApproachforGCD(int a ,int b){
    int gcd = min(a,b);
    for (int i = gcd; i >0; i--)
    {
        if(a%gcd==0 && b%gcd ==0){
            break;
        }
        gcd--;
    }
    return gcd;
    
}

int EuclideanBasicforGCD(int a ,int b){
    while(a!=b){
        if(a>b){
            a = a-b;
        }
        else{
            b=b-a;
        }
    }
     
    return b ;
    
}







//------------------------------------------------------------------------>

 
//find all Prime no. less than the Number T(nloglogn) :  prime<no
//Find GCD  O(log(min(a, b)) : gcdu 
//Check the no is prime or not : isPrime
//Power : powu
//Count set Bits : countbits
//To check if the thw no. is only power of 2  : ispowof2
//Print Prime Factors: primefac
//Print All divisoors of a number in inreasing order : printalldivisors
//2D Vector  : //vector<vector<int>> g(n + 1, vector<int> (n + 1, 0));
//   double mi = 2e8;
// double max = -2e8;

//------------------------------------------------------------------------>

 

//Most Optimized 

int OptimizedEuclideanforGCD(int a ,int b){
    if(b==0){
        return a;
    }
    else{
        return OptimizedEuclideanforGCD(b,a%b) ;
    }
}



int main() {

    int num1, num2 ;
    cin>>num1>>num2;
    cout<<NaiveApproachforGCD(num1,num2)<<endl;
    cout<<EuclideanBasicforGCD(num1,num2)<<endl;
    cout<<OptimizedEuclideanforGCD(num1,num2)<<endl;



    return 0;
}