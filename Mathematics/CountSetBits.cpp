#include <bits/stdc++.h>
using namespace std;

// To find no. of 1s or set bits
//theta(No. of 1 in bit form of no.)
void Brian_Kernigam_Algo(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }

    cout << count << endl;
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


int main()
{
    int n;
    cin >> n;
    Brian_Kernigam_Algo( n);

    //using count bits in theta(1) we must intialize a array of size 256 first

    // int arr[256];
    // arr[0] = 0;
    // for (int i = 1; i < 256; i++)
    // {
    //     arr[i] = (i&1) + arr[i/2];
    // }
    
    // int ans2 = countBits( n, arr);
    // cout<< ans2;

    return 0;
}