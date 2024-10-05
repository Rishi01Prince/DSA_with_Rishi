#include <bits/stdc++.h>
using namespace std;


//Here we are finding x^n
//Time Complexity = theta(logn)
//Auxilary Space = logn
int efficientPower( int x ,int n ){
    if(n==0){
        return 1;
    } 

    int temp = efficientPower(x,n/2);
    temp=temp*temp;
    if(n%2==0){
        return temp ;
    }
    else{
        return temp*x;
    }

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


int main() {
    int n,x;
    cin>>x>>n;
    int power1 = efficientPower(x,n);
     cout<<power1<<endl;

    // int power2  = MostEfficientPower(  x , n );
    // cout<<power2<<endl;
  

    return 0;

}