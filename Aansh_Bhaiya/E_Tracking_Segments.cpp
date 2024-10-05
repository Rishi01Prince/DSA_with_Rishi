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
    if(st==en&&st==ind)
    {
        sgtree[node]=val;
        return ;
    }
    ll md=(st+en)/2;
    update(2*node+1,st,md,sgtree,ind,val);
    update(2*node+2,md+1,en,sgtree,ind,val);
    sgtree[node]=sgtree[2*node+1]+sgtree[2*node+2];
}

ll getsum(ll node,ll st, ll en, vector<ll>& sgtree,ll qst,ll qen)
{
    if(qst>en||qen<st)
    {
        return 0;
    }
    if(st>=qst&&en<=qen)
    {
        return sgtree[node];
    }
    ll md=(st+en)/2;
    return getsum(2*node+1,st,md,sgtree,qst,qen)+getsum(2*node+2,md+1,en,sgtree,qst,qen);
}

int main()
{
    v();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> > range(m,vector<ll>(2));
        for(ll i=0;i<m;i++)
        {
            cin>>range[i][0]>>range[i][1];
            range[i][0]--;
            range[i][1]--;
        }

        ll q;
        cin>>q;
        vector<ll> v(q);
        for(ll i=0;i<q;i++)
        {
            cin>>v[i];
            v[i]--;
            
        }
        ll st=0;
        ll en=q;
        ll ans=-2;
        vector<ll> sgtree(4*n+1,0);
        while(en>=st)
        {
            ll md=(st+en)/2;
            for(ll i=0;i<q;i++)
            {
                if(i<=md)
                {
                    // cout<<v[i]<<"\n";
                    update(0,0,n-1,sgtree,v[i],1);
                }
                else{
                    update(0,0,n-1,sgtree,v[i],0);
                }
            }
            int can=0;
            for(int i=0;i<m;i++)
            {
                ll sm=getsum(0,0,n-1,sgtree,range[i][0],range[i][1]);
                if(2*sm>range[i][1]-range[i][0]+1)
                {
                    can=1;
                }
            }
            if(can)
            {
                ans=md;
                en=md-1;
            }
            else{
                st=md+1;
            }
        }

        cout<<ans+1<<"\n";


    }
}