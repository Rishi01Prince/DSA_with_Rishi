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


//Most Optimized 
//Time :   O(log(min(a,b)))
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
    int gcd = OptimizedEuclideanforGCD(num1,num2);
    int LCM = (num1*num2)/gcd;
    cout<<LCM<<endl;


    return 0;
}