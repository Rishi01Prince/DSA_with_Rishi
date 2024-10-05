// A C++ program to find longest subarray with
// sum of elements at-least k.
#include <bits/stdc++.h>
using namespace std;
 
// function to find the length of largest subarray
// having sum atmost k.
int atMostSum(int arr[], int n, int k)
{
    int sum = 0;
    int cnt = 0, maxcnt = 0;
 
    for (int i = 0; i < n; i++) {
         
        // If adding current element doesn't
        // cross limit add it to current window
        if ((sum + arr[i]) <= k) {
            sum += arr[i];
            cnt++;
        }
 
        // Else, remove first element of current
        // window and add the current element
        else if(sum!=0)
        {
            sum = sum - arr[i - cnt] + arr[i];
        }
 
        // keep track of max length.
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}
 
// Driver function
int main()
{
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
 
    cout << atMostSum(arr, n, k);
    return 0;
}