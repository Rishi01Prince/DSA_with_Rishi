#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iterator>
#include <deque>
#include <set>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include<assert.h>
#include <unordered_set>
#define ll long long
using namespace std;
#define mod 998244353
void v()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}



void update(ll node,ll st, ll en, vector<ll>& sgtree,ll ind,ll val)
{
    if(ind>en||ind<st)
    {
        return ;
    }
    if(st==en)
    {
        sgtree[node]= min(sgtree[node],val);
        return ;
    }
    ll md=(st+en)/2;
    update(2*node+1,st,md,sgtree,ind,val);
    update(2*node+2,md+1,en,sgtree,ind,val);
    sgtree[node]=min(sgtree[2*node+1],sgtree[2*node+2]);
}

ll getmin(ll node,ll st, ll en,vector<ll>& sgtree,ll qst, ll qen)
{
    if(qen<st||qst>en)
    {
        return 1e18;
    }
    if(st>=qst&&en<=qen)
    {
        return sgtree[node];
    }
    ll md=(st+en)/2;
    return min(getmin(2*node+1,st,md,sgtree,qst,qen),getmin(2*node+2,md+1,en,sgtree,qst,qen));
}

int main()
{
    v();
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
        vector<ll> sgtree(4*n+1,1e18);
        map<ll,ll> compress;
        ll presum=0;
        compress[presum]=0;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            presum+=v[i];
            compress[presum]=0;
        }
        ll com_index=0;
        for(auto& itr:compress)
        {
            itr.second=com_index;
            com_index++;
        }
        presum=0;
        update(0,0,n-1,sgtree,compress[presum],-1);
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            presum+=v[i];
            ll com_val=(*compress.lower_bound(presum-k)).second;
            ll min_ind=getmin(0,0,n-1,sgtree,com_val,n-1);
            ans=max(ans,i-min_ind);
            update(0,0,n-1,sgtree,compress[presum],i);
        }
        cout<<ans<<"\n";
    }
}