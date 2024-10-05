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
#define mod 1000000007
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

void dfs(ll node,ll par, ll height, vector<vector<ll> >&tree,map<ll ,ll> & mp)
{
    mp[node]=height;
    for(auto itr:tree[node])
    {
        if(itr!=par)
        {
            dfs(itr,node,height+1,tree,mp);
        }
    }
}


void dfs2(int node,int par, vector<vector<ll> >& tree,vector<vector<ll> >& bin_par)
{
    bin_par[node][0]=par;
    for(auto itr:tree[node])
    {
        if(itr!=par)
        {
            dfs2(itr,node,tree,bin_par);
        }
    }
}

ll do_jump(ll node,ll jump,vector<vector<ll> >& bin_par)
{
    while(jump!=0)
    {
        ll bin_jump =  log2(jump);
        jump -= pow(2,bin_jump);
        node= bin_par[node][bin_jump];
    }
    return node;
}

int main()
{
    v();
    int t;
    cin>>t;
    ll tt=t;
    while(t--)
    {
        cout<<"Case "<<tt-t<<":\n";
        ll n;
        cin>>n;
        vector<vector<ll> > tree(n+1);

        for(ll i=1;i<=n;i++)
        {
            ll m;
            cin>>m;
            for(ll j=0;j<m;j++)
            {
                ll node;
                cin>>node;
                tree[i].push_back(node);
                tree[node].push_back(i);
            }
        }
        map<ll,ll> level;
        dfs(1,-1,1,tree,level);
        vector<vector<ll> > bin_par(n+1,vector<ll>(32,-1));
        dfs2(1,-1,tree,bin_par);


        for(int pow=1;pow<32;pow++)
        {
            for(int node=1;node<=n;node++)
            {
                if(bin_par[node][pow-1]==-1)
                {
                    bin_par[node][pow]=-1;
                }
                else{
                    bin_par[node][pow]= bin_par[bin_par[node][pow-1]][pow-1];
                }
            }
        }
        ll q;
        cin>>q;

        while(q--)
        {
            ll a,b;
            cin>>a>>b;
            ll lvla=level[a];
            ll lvlb = level[b];
            if(lvla<lvlb)
            {
                ll jump = lvlb-lvla;
                b=do_jump(b,jump,bin_par);
            }
            else{
                ll jump = lvla-lvlb;
                a=do_jump(a,jump,bin_par);
            }

            ll mn=1;
            ll mx=level[a];
            ll ans=1;
            // cout<<a<<" "<<b<<" "<<mn<<" "<<mx<<"\n";
            while(mx>=mn)
            {
                ll md= (mn+mx)/2;
                if(do_jump(a,level[a]-md,bin_par)==do_jump(b,level[b]-md,bin_par))
                {
                    ans=md;
                    mn=md+1;
                }
                else
                {
                    mx=md-1;
                }
            }
            // cout<<ans<<"\n";
            cout<<do_jump(a,level[a]-ans,bin_par)<<"\n";
        }


    }
}