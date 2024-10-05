#include <bits/stdc++.h>
using namespace std;


#define ll long long
ll mod=1e9+7;
class Solution {
public:
    
    long long rec(vector<int> nums, vector<vector<ll> >& ncr)
    {
        if(nums.size()==0)
        {
            return 1;
        }
        
        vector<int> left;
        vector<int> right;
        
        int node=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<node)
            {
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        
        ll left_sz= left.size();
        ll right_sz = right.size();
        ll num = max(1ll,ncr[left_sz+right_sz][left_sz]);
        num*=rec(right,ncr);
        num%=mod;
        num*=rec(left,ncr);
        num%=mod;
        return num;
    }
    
    int numOfWays(vector<int>& nums) {
        vector<vector<ll> > ncr(1001,vector<ll>(1001,0));
        ncr[0][0]=1;
        for(ll i=1;i<=1000;i++)
        {
            for(ll j=0;j<=1000;j++)
            {
                if(j>i)
                {
                    break;
                }
                if(j==0)
                {
                    ncr[i][j]=1;
                }
                else{
                    ncr[i][j] = (ncr[i-1][j-1]+ncr[i-1][j])%mod;
                }
            }
        }
        
        return rec(nums,ncr)-1;
        
    }
};


int32_t main() {
    Solution s;
    vector<int> nums={3,1,2,5,4,6};
    cout<<s.numOfWays(nums);

    return 0;
}