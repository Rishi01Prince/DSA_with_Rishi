#include <bits/stdc++.h>
using namespace std;



bool NaiveApproachforPrime(int a ){
    if(a==1){
        return false;
    }

    for (int i = 2; i < a; i++)
    {
        if(a%i==0){
            return false;
        }
    
    }
    return true ;   
}

//MoreEfficient way for Prime:
bool EfficientwayforPrime(int a){
    if(a==1){
        return false;
    }

    for (int i = 2; i*i <= a; i++)
    {
        if(a%i==0){
            return false;
        }
    }
    
    return true ;
    
}


//Most Optimized 

bool MostEfficientwayforPrime(int a){
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



int main() {

    int num1;
    cin >> num1;

    cout<<NaiveApproachforPrime(num1)<<endl;
    cout<<EfficientwayforPrime(num1)<<endl;
    cout<<MostEfficientwayforPrime(num1)<<endl;
    



    return 0;
}