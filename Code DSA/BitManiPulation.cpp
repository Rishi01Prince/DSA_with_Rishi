#include <bits/stdc++.h>
using namespace std;

/* (n&~(n-1)) always return the binary number containing the rightmost set bit as 1.
if N = 12 (1100) then it will return 4 (100).
Here log2 will return, the number of times we can express that number in a power of two.*/

// GFG :
// O(log2 N)
//Position of Set Bit

int getFirstSetBitPos(int n)
{
    return log2(n & -n) + 1;
}
// O(log2 N)
int getFirstSetBitPos2(int n) { return ffs(n); }

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

int countsetBits(int N)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if (N & (1 << i))
            count++;
    }
    return count;
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

void PowerSet(string str)
{

    int n = str.length();
    int max_no_of_Subseq = pow(2, n);

    for (int i = 0; i < max_no_of_Subseq; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
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