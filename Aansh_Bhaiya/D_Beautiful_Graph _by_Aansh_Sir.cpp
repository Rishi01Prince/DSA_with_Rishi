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

ll b=0;
ll r=0;

ll dfs(ll node,ll color,vector<ll>& col ,vector<vector<ll> >& graph)
{
    col[node]=color;
    if(color==0)
    {
        b++;
    }
    else{
        r++;
    }
    bool can=true;
    for(auto itr:graph[node])
    {
        if(col[itr]==-1)
        {
            can &= dfs(itr,1^color,col,graph);
        }
        else if(col[itr]==color)
        {
            can=false;
        }
    }
    return can;
}

int main()
{
    
    vector<ll> two_pow(300001,1);
    for(ll i=1;i<=300000;i++)
    {
        two_pow[i]=2ll*two_pow[i-1];
        two_pow[i]%=mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int m;
        cin>>n>>m;
        vector<vector<ll > > graph(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        ll ans=1;
        vector<ll> col(n+1,-1);
        

        
        for(ll i=1;i<=n;i++)
        {
            if(col[i]==-1)
            {
                if(dfs(i,0,col,graph))
                {
                    ans*= (two_pow[b] + two_pow[r]);
                    ans%=mod;
                    b=0;
                    r=0;
                }
                else{
                    ans=0;
                    r=0;
                    b=0;
                }
            }
        }
        cout<<ans<<"\n";
    }

}