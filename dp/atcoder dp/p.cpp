#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define si size()
#define bk back()
#define popb pop_back()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define emp empty()
#define beg begin()
#define en end()
#define ump unordered_map
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define fore(i,a,n) for(int i=a;i<=n;i++)
#define len length()
const int N=1e5+10;
const ll mod=1e9+7;
ll dp1[N],dp2[N];

// dp1[n]---- optimal answer for the subtree rooted at n and if i color the root as black
// dp2[n]---- optimal answer for the subtree rooted at n and if i color the root as white

/*
1) if i color root as white then i can color its children white or black
2)if i color root as black then i can only use white for its children 
this is the recurrence

*/
void dfs(int v,int par,vector<int>adj[])
{
    ll sum1=1;
    ll sum2=1;
    int ch=0;
    for(auto node:adj[v])
    {
        if(node==par) continue;
        ch=1;
        dfs(node,v,adj);
        sum1=(sum1*(dp1[node]+dp2[node]))%mod;
        sum2=(sum2*(dp1[node]))%mod;
    }
    if(!ch)
    {
        dp1[v]=dp2[v]=1;
    }
    else 
    {
        dp1[v]=sum1;
        dp2[v]=sum2;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    forl(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1,adj);
    cout<<(dp1[1]+dp2[1])%mod<<endl;
}













