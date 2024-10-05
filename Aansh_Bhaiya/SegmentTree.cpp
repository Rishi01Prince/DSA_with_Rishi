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


void build(ll node,ll st,ll en,vector<ll>& v,vector<ll>& sgtree)
{
    if(st==en)
    {
        sgtree[node]=v[st];
        return;
    }
    ll md=(st+en)/2;
    build(2*node+1,st,md,v,sgtree);
    build(2*node+2,md+1,en,v,sgtree);
    sgtree[node] = sgtree[2*node+1] + sgtree[2*node+2];
}

void update(ll node,ll st, ll en, vector<ll>& sgtree,ll ind,ll val)
{
    if(ind>en||ind<st)
    {
        return;
    }
    sgtree[node]+=val;
    if(st==en)
    {
        return ;
    }
    ll md=(st+en)/2;
    update(2*node+1,st,md,sgtree,ind,val);
    update(2*node+2,md+1,en,sgtree,ind,val);
}

ll get_sum(ll node,ll st , ll en, vector<ll>& sgtree,ll qst, ll qen)
{
    if(qst>en||qen<st)
    {
        return 0;
    }
    if(st>=qst&&en<=qen)
    {
        return sgtree[node];
    }
    ll md= (st+en)/2;
    return get_sum(2*node+1,st,md,sgtree,qst,qen)+get_sum(2*node+2,md+1,en,sgtree,qst,qen);
}

int main()
{
    

    int n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }

    vector<ll> sgtree(4*n+1,0);

    build(0,0,n-1,v,sgtree);
    for (int i = 0; i < 4*n+1; i++)
    {
        cout<<sgtree[i]<<" ";
    }
    cout<<endl;
    cout<<get_sum(0,0,n-1,sgtree,1,3)<<endl;
    update(0,0,n-1,sgtree,2,10);


    for (int i = 0; i < 4*n+1; i++)
    {
        cout<<sgtree[i]<<" ";
    }
    cout<<endl;
    cout<<get_sum(0,0,n-1,sgtree,1,3)<<endl;
    
}