
// C++ implementation to get the position of rightmost unset bit
#include <bits/stdc++.h>
 
using namespace std;
 
// function to find the position
// of rightmost set bit
int getPosOfRightmostSetBit(int n)
{
    return log2(n&-n)+1;
}
 
// function to get the position of rightmost unset bit
int countSetBits(int N)
{
    int count = 0;
   
    // (1 << i) = pow(2, i)
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (N & (1 << i))
            count++;
    }
    return count;
}
 
int getPosOfRightMostUnsetBit(int n)
{
    // if n = 0, return 1
    if (n == 0)
        return 1;
     
    // if all bits of 'n' are set
    if ((n & (n + 1)) == 0)   
        return -1;
     
    // position of rightmost unset bit in 'n'
    // passing ~n as argument
    return getPosOfRightmostSetBit(~n);       
}
 
// Driver program to test above
int main()
{
    int n = 15;
    cout << getPosOfRightMostUnsetBit(n);
    return 0;
}