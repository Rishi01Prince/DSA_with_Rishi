#include <bits/stdc++.h>
using namespace std;

/* (n&~(n-1)) always return the binary number containing the rightmost set bit as 1.
if N = 12 (1100) then it will return 4 (100).
Here log2 will return, the number of times we can express that number in a power of two.*/


//The expression n = n & (n - 1) is commonly used in programming to clear the
// least significant (rightmost) set bit in the binary representation of the
// variable n. Here's a breakdown of how the expression works:

//Some more interesting facts about Bit Manipulation in Competitive Programming

// 1. n & 1 == 1 means n is odd, while n & 1 == 0 means n is even.
// 2. n >> 1 will return n / 2.
// 3. n & (n - 1) will clear the least significant bit set.
// 4. n & ~(n - 1) extracts the least significant bit of n (all others are clear).
// 5. n | (n + 1) returns the least power of 2 greater than or equal to n.
// 6. n | ~(n + 1) extracts the least significant 0 bit of n (all others are set).
// 7. n | (n - 1) returns the largest power of 2 less than or equal to n, assuming n is not already a power of 2.
// 8. n | ~(n - 1) extracts the least significant 1 bit of n (all others are clear).
// 9. n & (n + 1) == 0 checks if n is a power of 2 (or zero).
// 10. n & ~(n + 1) == 0 checks if n is zero.
// 11. n & (n - 1) == (n - 1) checks if n is a power of 2 (or zero).
// 12. n & (n + 1) will increment n if it is a power of 2 (or zero).
// 13. n - (n & ~(n - 1)) extracts the least significant 1 bit of n (all others are clear).
// 14. n - (n & (n + 1)) extracts the least significant 0 bit of n (all others are set).
// 15. n - (n & (n - 1)) extracts the least significant 0 bit of n (all others are set).
// 16. n - (n | (n + 1)) extracts the least significant 0 bit of n (all others are set).
// 17. n - (n & (n + 1)) extracts the least significant 0 bit of n (all others are set).
// 18. n - (n & (n - 1)) extracts the least significant 0 bit of n (all others are set).

//n&(n-1) will clear the least significant bit set.
//Hence if 0 is returned, then n is a power of 2.

// GFG :
// O(log2 N)
//Position of Set Bit

int getFirstSetBitPos(int n)
{
    return log2(n & -n) + 1;
}

int getPosOfRightMostUnsetBit(int n)
{
    // if n = 0, return 1
    if (n == 0){return 1;}

    // if all bits of 'n' are set
    if ((n & (n + 1)) == 0)
        return -1;
        
    // position of rightmost unset bit in 'n'
    // passing ~n as argument
    return getFirstSetBitPos(~n);
    
}

//Compute power using bit manipulation
// O(log2 N)
int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }
    return res;
}

int countsetBits(int N)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if (N & (1 << i))e
}

// To find no. of 1s or set bits
// theta(No. of 1 in bit form of no.)
//(n & (n - 1) --> becomes 0 if it is a power of2
bool Is_Pow_of_Two(int n)
{
    if (n == 0)
    {
        return false;
    }
    return (((n & (n - 1)) == 0));
}

// Count Set Bits
// O(No of Set Bits)
// Brain Kerningam's Algorithm

int countSetBits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        
// The expression n = n & (n - 1) is commonly used in programming to clear the least
// significant (rightmost) set bit in the binary representation of the variable n.
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

// Table and DP approach
// In theta(1) if ones are precomputed

int countBits(int n, int *arr)
{

    int count = arr[n & 0xff]; // 0xff means last 8 bits of binary all 1 or we can say
                               // that it is in hexadecimal form
    n = n >> 8;

    count = count + arr[n & 0xff];
    n = n >> 8;
    count = count + arr[n & 0xff];
    n = n >> 8;
    count = count + arr[n & 0xff];

    return count;

    // Keep this in main:
    // using count bits in theta(1) we must intialize a array of size 256 first

    // int arr[256];
    // arr[0] = 0;
    // for (int i = 1; i < 256; i++)
    // {
    //     arr[i] = (i&1) + arr[i/2];
    // }

    // int ans2 = countBits( n, arr);
    // cout<< ans2;
}

// Power Set : Generating all Subsequences of a String3
//   No of Subsequences = 2^n
//  O(n*2^n)

void PowerSet(string str){

    int n = str.length();
    int max_no_of_Subseq = pow(2, n);

    for (int i = 0; i < max_no_of_Subseq; i++)
    {
        for (int j = 0 ; j < n ; j++){

            if (i & (1 << j)){   
                cout << str[j];
            }
        }
        cout << endl;
    }
}

int32_t main()
{
    // int T;
    // cin>>T;
    string str;
    cin >> str;
    PowerSet(str);

    return 0;
}